from django.contrib.auth import get_user_model
from django.urls import reverse
from rest_framework import status
from rest_framework.test import APITestCase
from rest_framework_simplejwt.tokens import RefreshToken

from .models import Asset, WatchlistItem


class BaseAuthAPITestCase(APITestCase):
    def setUp(self):
        self.user = get_user_model().objects.create_user(username='tester', password='pass1234')
        token = RefreshToken.for_user(self.user).access_token
        self.client.credentials(HTTP_AUTHORIZATION=f'Bearer {token}')


class AssetListTests(BaseAuthAPITestCase):
    def setUp(self):
        super().setUp()
        Asset.objects.create(symbol='AAPL', name='苹果', market='US', currency='USD', tags='科技,消费')
        Asset.objects.create(symbol='MSFT', name='微软', market='US', currency='USD', tags='科技,云计算')
        Asset.objects.create(symbol='0700.HK', name='腾讯控股', market='HK', currency='HKD', tags='科技,互联网')

    def test_query_filter(self):
        resp = self.client.get(reverse('asset-list'), {'query': '腾'})
        self.assertEqual(resp.status_code, status.HTTP_200_OK)
        self.assertEqual(len(resp.data['results']), 1)
        self.assertEqual(resp.data['results'][0]['symbol'], '0700.HK')

    def test_market_filter(self):
        resp = self.client.get(reverse('asset-list'), {'market': 'US'})
        self.assertEqual(resp.status_code, status.HTTP_200_OK)
        self.assertEqual(len(resp.data['results']), 2)

    def test_tag_filter(self):
        resp = self.client.get(reverse('asset-list'), {'tag': '云计算'})
        self.assertEqual(resp.status_code, status.HTTP_200_OK)
        self.assertEqual(len(resp.data['results']), 1)
        self.assertEqual(resp.data['results'][0]['symbol'], 'MSFT')


class WatchlistTests(BaseAuthAPITestCase):
    def setUp(self):
        super().setUp()
        self.asset = Asset.objects.create(symbol='AAPL', name='苹果', market='US', currency='USD', tags='科技,消费')

    def test_add_idempotent(self):
        payload = {'asset_id': self.asset.id}
        first = self.client.post(reverse('watchlist'), payload, format='json')
        second = self.client.post(reverse('watchlist'), payload, format='json')

        self.assertIn(first.status_code, [status.HTTP_200_OK, status.HTTP_201_CREATED])
        self.assertEqual(second.status_code, status.HTTP_200_OK)
        self.assertEqual(WatchlistItem.objects.count(), 1)

    def test_remove_idempotent(self):
        WatchlistItem.objects.create(user=self.user, asset=self.asset)

        first = self.client.delete(reverse('watchlist-delete', args=[self.asset.id]))
        second = self.client.delete(reverse('watchlist-delete', args=[self.asset.id]))

        self.assertEqual(first.status_code, status.HTTP_204_NO_CONTENT)
        self.assertEqual(second.status_code, status.HTTP_204_NO_CONTENT)


class RecommendationTests(BaseAuthAPITestCase):
    def setUp(self):
        super().setUp()
        self.watched = Asset.objects.create(
            symbol='AAPL', name='苹果', market='US', currency='USD', sector='科技', tags='科技,AI,消费'
        )
        self.candidate_same_tag = Asset.objects.create(
            symbol='NVDA', name='英伟达', market='US', currency='USD', sector='科技', tags='科技,AI,芯片'
        )
        self.candidate_same_sector = Asset.objects.create(
            symbol='MSFT', name='微软', market='US', currency='USD', sector='科技', tags='云计算,软件'
        )
        self.watched2 = Asset.objects.create(
            symbol='0700.HK', name='腾讯', market='HK', currency='HKD', sector='科技', tags='互联网,游戏'
        )
        WatchlistItem.objects.create(user=self.user, asset=self.watched)

    def test_recommendations_include_reason_and_exclude_watched(self):
        resp = self.client.get(reverse('recommendations'))
        self.assertEqual(resp.status_code, status.HTTP_200_OK)
        symbols = [row['symbol'] for row in resp.data]

        self.assertNotIn(self.watched.symbol, symbols)
        self.assertIn('NVDA', symbols)
        self.assertTrue(all('reason' in row and row['reason'] for row in resp.data))
