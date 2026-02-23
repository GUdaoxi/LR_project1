from rest_framework import serializers

from .models import Asset, WatchlistItem


class AssetSerializer(serializers.ModelSerializer):
    tags_list = serializers.ListField(child=serializers.CharField(), read_only=True)
    market_display = serializers.CharField(source='get_market_display', read_only=True)

    class Meta:
        model = Asset
        fields = [
            'id', 'symbol', 'name', 'market', 'market_display', 'currency', 'exchange',
            'sector', 'industry', 'tags', 'tags_list', 'description', 'updated_at', 'created_at'
        ]


class WatchlistItemSerializer(serializers.ModelSerializer):
    asset = AssetSerializer(read_only=True)

    class Meta:
        model = WatchlistItem
        fields = ['asset', 'created_at']


class WatchlistCreateSerializer(serializers.Serializer):
    asset_id = serializers.IntegerField()


class RecommendationSerializer(serializers.ModelSerializer):
    reason = serializers.CharField()
    market_display = serializers.CharField(source='get_market_display', read_only=True)

    class Meta:
        model = Asset
        fields = ['id', 'symbol', 'name', 'market', 'market_display', 'currency', 'reason']
