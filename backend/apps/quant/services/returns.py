from __future__ import annotations

from datetime import date, timedelta

import numpy as np

from apps.assets.models import Asset
from apps.marketdata.models import PriceBar


MIN_COVERAGE = 0.8


def build_returns_matrix(symbols: list[str], start: date | None = None, end: date | None = None, lookback_days: int | None = None):
    clean_symbols = [s.upper() for s in symbols]
    notes: list[str] = []
    if end is None:
        end = date.today()
    if start is None:
        days = lookback_days or 252
        start = end - timedelta(days=days)

    assets = {a.symbol: a for a in Asset.objects.filter(symbol__in=clean_symbols, market=Asset.Market.US)}
    missing = [s for s in clean_symbols if s not in assets]
    for symbol in missing:
        notes.append(f'{symbol} 非 US 资产或不存在，已剔除')

    symbol_dates: dict[str, set] = {}
    series: dict[str, dict] = {}

    for symbol, asset in assets.items():
        rows = list(
            PriceBar.objects.filter(asset=asset, date__gte=start, date__lte=end)
            .values('date', 'adj_close')
            .order_by('date')
        )
        if not rows:
            notes.append(f'{symbol} 在区间内无价格数据，已剔除')
            continue
        series[symbol] = {r['date']: float(r['adj_close']) for r in rows if r['adj_close'] is not None}
        symbol_dates[symbol] = set(series[symbol].keys())

    if not symbol_dates:
        return {'symbols': [], 'dates': [], 'prices': np.array([]), 'returns': np.array([]), 'notes': notes}

    full_union = set().union(*symbol_dates.values())
    keep_symbols = []
    for symbol, dates_set in symbol_dates.items():
        coverage = len(dates_set) / len(full_union) if full_union else 0
        if coverage < MIN_COVERAGE:
            notes.append(f'{symbol} 可用数据覆盖率 {coverage:.1%} < 80%，已剔除')
            continue
        keep_symbols.append(symbol)

    if not keep_symbols:
        return {'symbols': [], 'dates': [], 'prices': np.array([]), 'returns': np.array([]), 'notes': notes}

    intersect_dates = set.intersection(*(symbol_dates[s] for s in keep_symbols))
    dates = sorted(intersect_dates)
    if len(dates) < 2:
        notes.append('交集交易日不足 2 天，无法计算收益率')
        return {'symbols': [], 'dates': [], 'prices': np.array([]), 'returns': np.array([]), 'notes': notes}

    prices = np.array([[series[s][d] for s in keep_symbols] for d in dates], dtype=float)
    returns = prices[1:] / prices[:-1] - 1.0

    return {'symbols': keep_symbols, 'dates': dates, 'prices': prices, 'returns': returns, 'notes': notes}
