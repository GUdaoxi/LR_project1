from datetime import date
from unittest.mock import patch

from django.core.management import call_command
from django.test import TestCase

from apps.assets.models import Asset
from apps.marketdata.models import PriceBar
from apps.marketdata.services.providers.stooq import StooqProvider

SAMPLE_CSV = """Date,Open,High,Low,Close,Volume
2024-01-02,100,110,99,108,1200000
2024-01-03,108,112,107,111,1300000
"""


class StooqProviderTests(TestCase):
    @patch('apps.marketdata.services.providers.stooq.requests.get')
    def test_fetch_daily_parse_csv(self, mock_get):
        mock_get.return_value.status_code = 200
        mock_get.return_value.text = SAMPLE_CSV

        provider = StooqProvider()
        bars = provider.fetch_daily('aapl.us', date(2024, 1, 1), date(2024, 1, 5))

        self.assertEqual(len(bars), 2)
        self.assertEqual(bars[0].adj_close, 108.0)
        self.assertEqual(bars[1].volume, 1300000)


class FetchPricesCommandTests(TestCase):
    @patch('apps.marketdata.services.providers.stooq.requests.get')
    def test_fetch_prices_writes_rows(self, mock_get):
        mock_get.return_value.status_code = 200
        mock_get.return_value.text = SAMPLE_CSV

        Asset.objects.create(symbol='AAPL', name='Apple', market='US', currency='USD')
        call_command('fetch_prices', symbols='AAPL', lookback=30, sleep=0)

        self.assertEqual(PriceBar.objects.count(), 2)
