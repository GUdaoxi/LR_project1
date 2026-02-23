from __future__ import annotations

from apps.marketdata.models import PriceBar


def upsert_bars(asset, bars, source: str = 'stooq') -> int:
    if not bars:
        return 0

    objects = [
        PriceBar(
            asset=asset,
            date=bar.date,
            open=bar.open,
            high=bar.high,
            low=bar.low,
            close=bar.close,
            adj_close=bar.adj_close,
            volume=bar.volume,
            source=source,
        )
        for bar in bars
    ]

    PriceBar.objects.bulk_create(
        objects,
        update_conflicts=True,
        unique_fields=['asset', 'date'],
        update_fields=['open', 'high', 'low', 'close', 'adj_close', 'volume', 'source', 'updated_at'],
    )
    return len(objects)
