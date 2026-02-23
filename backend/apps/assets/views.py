from collections import Counter

from django.db.models import Q
from rest_framework import status
from rest_framework.permissions import IsAuthenticated
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework.generics import ListAPIView, RetrieveAPIView

from .models import Asset, WatchlistItem
from .serializers import (
    AssetSerializer,
    RecommendationSerializer,
    WatchlistCreateSerializer,
    WatchlistItemSerializer,
)


class AssetListView(ListAPIView):
    serializer_class = AssetSerializer
    permission_classes = [IsAuthenticated]

    def get_queryset(self):
        queryset = Asset.objects.all()
        query = self.request.query_params.get('query', '').strip()
        market = self.request.query_params.get('market', '').strip()
        tag = self.request.query_params.get('tag', '').strip()
        ordering = self.request.query_params.get('ordering', '').strip()

        if query:
            queryset = queryset.filter(Q(symbol__icontains=query) | Q(name__icontains=query))

        if market in [Asset.Market.US, Asset.Market.HK]:
            queryset = queryset.filter(market=market)

        if tag:
            queryset = queryset.filter(tags__icontains=tag)

        allowed_ordering = {'symbol', 'name', 'updated_at', '-updated_at'}
        if ordering in allowed_ordering:
            queryset = queryset.order_by(ordering)

        return queryset


class AssetDetailView(RetrieveAPIView):
    serializer_class = AssetSerializer
    permission_classes = [IsAuthenticated]
    queryset = Asset.objects.all()


class WatchlistView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        queryset = WatchlistItem.objects.filter(user=request.user).select_related('asset')
        serializer = WatchlistItemSerializer(queryset, many=True)
        return Response(serializer.data)

    def post(self, request):
        serializer = WatchlistCreateSerializer(data=request.data)
        serializer.is_valid(raise_exception=True)

        asset_id = serializer.validated_data['asset_id']
        try:
            asset = Asset.objects.get(id=asset_id)
        except Asset.DoesNotExist:
            return Response({'detail': 'Asset not found.'}, status=status.HTTP_404_NOT_FOUND)

        item, created = WatchlistItem.objects.get_or_create(user=request.user, asset=asset)
        result = WatchlistItemSerializer(item).data
        return Response(result, status=status.HTTP_201_CREATED if created else status.HTTP_200_OK)


class WatchlistDeleteView(APIView):
    permission_classes = [IsAuthenticated]

    def delete(self, request, asset_id):
        WatchlistItem.objects.filter(user=request.user, asset_id=asset_id).delete()
        return Response(status=status.HTTP_204_NO_CONTENT)


class RecommendationView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        top_n = int(request.query_params.get('limit', 10))

        watched_items = WatchlistItem.objects.filter(user=request.user).select_related('asset')
        watched_asset_ids = [item.asset_id for item in watched_items]
        if not watched_items:
            return Response([])

        tag_counter = Counter()
        sector_counter = Counter()
        market_counter = Counter()

        for item in watched_items:
            asset = item.asset
            tag_counter.update(asset.tags_list)
            if asset.sector:
                sector_counter.update([asset.sector])
            market_counter.update([asset.market])

        candidates = Asset.objects.exclude(id__in=watched_asset_ids)
        scored: dict[int, dict] = {}

        for asset in candidates:
            score = 0
            reason = ''
            matched_tags = [tag for tag in asset.tags_list if tag in tag_counter]
            if matched_tags:
                top_tag = max(matched_tags, key=lambda t: tag_counter[t])
                score += 30 + tag_counter[top_tag] * 5
                reason = f'与你关注的股票同属标签：{top_tag}'
            elif asset.sector and asset.sector in sector_counter:
                score += 15 + sector_counter[asset.sector] * 3
                reason = f'与你关注的股票同属板块：{asset.sector}'
            elif asset.market in market_counter:
                market_name = '美股' if asset.market == Asset.Market.US else '港股'
                score += 5 + market_counter[asset.market]
                reason = f'与你关注的市场一致：{market_name}'

            if score > 0:
                scored[asset.id] = {'asset': asset, 'score': score, 'reason': reason}

        ordered_items = sorted(scored.values(), key=lambda d: d['score'], reverse=True)[:top_n]

        payload = []
        for row in ordered_items:
            serialized = RecommendationSerializer(row['asset']).data
            serialized['reason'] = row['reason']
            payload.append(serialized)

        return Response(payload)
