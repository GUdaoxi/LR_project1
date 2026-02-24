from __future__ import annotations

import csv
from datetime import date, datetime
from io import StringIO

import requests

from .base import Bar, BasePriceProvider


class StooqProviderError(Exception):
    pass


class StooqProvider(BasePriceProvider):
    base_url = 'https://stooq.com/q/d/l/'

    def normalize_symbol(self, asset_symbol: str) -> str:
        normalized = asset_symbol.strip().lower()
        if normalized.endswith('.us'):
            return normalized
        return f'{normalized}.us'

    def fetch_daily(self, symbol: str, start: date, end: date) -> list[Bar]:
        params = {
            's': symbol,
            'd1': start.strftime('%Y%m%d'),
            'd2': end.strftime('%Y%m%d'),
            'i': 'd',
        }
        try:
            response = requests.get(self.base_url, params=params, timeout=15)
        except requests.RequestException as exc:
            raise StooqProviderError(f'网络请求失败: {exc}') from exc

        if response.status_code != 200:
            raise StooqProviderError(f'请求失败，HTTP {response.status_code}')

        text = response.text.strip()
        if not text:
            raise StooqProviderError('返回内容为空')

        lowered = text.lower()
        if 'captcha' in lowered or 'access denied' in lowered or '<html' in lowered:
            raise StooqProviderError('Stooq 返回了异常页面（可能触发验证或限制）')

        rows = list(csv.DictReader(StringIO(text)))
        if not rows:
            raise StooqProviderError('CSV 无有效数据')

        bars: list[Bar] = []
        for row in rows:
            if not row.get('Date'):
                continue
            try:
                dt = datetime.strptime(row['Date'], '%Y-%m-%d').date()
            except ValueError:
                continue

            close = self._to_float(row.get('Close'))
            if close is None:
                continue

            bars.append(
                Bar(
                    date=dt,
                    open=self._to_float(row.get('Open')),
                    high=self._to_float(row.get('High')),
                    low=self._to_float(row.get('Low')),
                    close=close,
                    adj_close=close,
                    volume=self._to_int(row.get('Volume')),
                )
            )

        if not bars:
            raise StooqProviderError('CSV 解析后无有效日线数据')

        bars.sort(key=lambda x: x.date)
        return bars

    @staticmethod
    def _to_float(value: str | None) -> float | None:
        if not value or value == 'null':
            return None
        try:
            return float(value)
        except ValueError:
            return None

    @staticmethod
    def _to_int(value: str | None) -> int | None:
        if not value or value == 'null':
            return None
        try:
            return int(float(value))
        except ValueError:
            return None
