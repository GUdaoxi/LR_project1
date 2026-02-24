from datetime import date

from django.contrib.auth import get_user_model
from django.urls import reverse
from rest_framework import status
from rest_framework.test import APITestCase
from rest_framework_simplejwt.tokens import RefreshToken

from apps.assets.models import Asset
from apps.marketdata.models import PriceBar
from apps.quant.services.returns import build_returns_matrix


class QuantBaseCase(APITestCase):
    def setUp(self):
        self.user = get_user_model().objects.create_user(username='quant', password='pass1234')
        token = RefreshToken.for_user(self.user).access_token
        self.client.credentials(HTTP_AUTHORIZATION=f'Bearer {token}')

        self.aapl = Asset.objects.create(symbol='AAPL', name='Apple', market='US', currency='USD')
        self.msft = Asset.objects.create(symbol='MSFT', name='Microsoft', market='US', currency='USD')
        self.hk = Asset.objects.create(symbol='0700.HK', name='Tencent', market='HK', currency='HKD')

        prices = [
            (date(2024, 1, 2), 100, 50),
            (date(2024, 1, 3), 101, 51),
            (date(2024, 1, 4), 102, 50.5),
            (date(2024, 1, 5), 103, 51.5),
        ]
        for dt, pa, pm in prices:
            PriceBar.objects.create(asset=self.aapl, date=dt, close=pa, adj_close=pa)
            PriceBar.objects.create(asset=self.msft, date=dt, close=pm, adj_close=pm)


class ReturnsTests(QuantBaseCase):
    def test_intersection_and_filtering(self):
        matrix = build_returns_matrix(['AAPL', 'MSFT', '0700.HK'], start=date(2024, 1, 2), end=date(2024, 1, 5))
        self.assertEqual(matrix['symbols'], ['AAPL', 'MSFT'])
        self.assertEqual(len(matrix['dates']), 4)
        self.assertEqual(matrix['returns'].shape, (3, 2))

    def test_default_end_uses_latest_available_price_date(self):
        matrix = build_returns_matrix(['AAPL', 'MSFT'], lookback_days=365)
        self.assertEqual(matrix['symbols'], ['AAPL', 'MSFT'])
        self.assertEqual(len(matrix['dates']), 4)
        self.assertTrue(any('未指定结束日期' in note for note in matrix['notes']))


class OptimizeApiTests(QuantBaseCase):
    def test_optimize_weights_non_negative_and_sum_to_one(self):
        resp = self.client.post(
            reverse('portfolio-optimize'),
            {'symbols': ['AAPL', 'MSFT'], 'method': 'equal_weight', 'lookback_days': 365, 'risk_free': 0.02},
            format='json',
        )
        self.assertEqual(resp.status_code, status.HTTP_200_OK)
        weights = resp.data['weights']
        self.assertTrue(weights)
        total = sum(float(x['w']) for x in weights)
        self.assertAlmostEqual(total, 1.0, places=6)
        self.assertTrue(all(float(x['w']) >= 0 for x in weights))
        self.assertIn('metrics', resp.data)


class BacktestApiTests(QuantBaseCase):
    def test_backtest_output_shape(self):
        resp = self.client.post(
            reverse('backtest-run'),
            {
                'symbols': ['AAPL', 'MSFT'],
                'weights': {'AAPL': 0.5, 'MSFT': 0.5},
                'start': '2024-01-02',
                'end': '2024-01-05',
                'rebalance': 'monthly',
                'cost_bps': 10,
            },
            format='json',
        )
        self.assertEqual(resp.status_code, status.HTTP_200_OK)
        equity = resp.data['equity_curve']
        self.assertGreaterEqual(len(equity), 2)
        self.assertAlmostEqual(equity[0]['nav'], 1.0, places=6)
        self.assertLessEqual(resp.data['stats']['max_dd'], 0.0)
