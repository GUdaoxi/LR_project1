from __future__ import annotations

import time
from datetime import date, timedelta

from django.core.management.base import BaseCommand, CommandError

from apps.assets.models import Asset
from apps.marketdata.services.ingest import upsert_bars
from apps.marketdata.services.providers.stooq import StooqProvider, StooqProviderError


class Command(BaseCommand):
    help = '从 Stooq 拉取资产日线数据并入库'

    def add_arguments(self, parser):
        parser.add_argument('--symbols', type=str, default='')
        parser.add_argument('--market', type=str, default='US')
        parser.add_argument('--lookback', type=int, default=730)
        parser.add_argument('--source', type=str, default='stooq')
        parser.add_argument('--sleep', type=float, default=0.5)

    def handle(self, *args, **options):
        market = options['market'].upper()
        if market != 'US':
            raise CommandError('当前仅支持 market=US')

        symbols_opt = options['symbols'].strip()
        if symbols_opt:
            symbols = [x.strip().upper() for x in symbols_opt.split(',') if x.strip()]
            assets = list(Asset.objects.filter(symbol__in=symbols, market=Asset.Market.US))
            found = {a.symbol for a in assets}
            missing = [s for s in symbols if s not in found]
            if missing:
                self.stdout.write(self.style.WARNING(f'未在资产表找到: {missing}'))
        else:
            assets = list(Asset.objects.filter(market=Asset.Market.US))

        if not assets:
            raise CommandError('未找到可拉取的 US 资产')

        provider = StooqProvider()
        end = date.today()
        start = end - timedelta(days=options['lookback'])

        failed: list[str] = []
        for asset in assets:
            normalized = provider.normalize_symbol(asset.symbol)
            try:
                bars = provider.fetch_daily(normalized, start, end)
                written = upsert_bars(asset, bars, source=options['source'])
                self.stdout.write(
                    self.style.SUCCESS(
                        f'{asset.symbol}: fetched={len(bars)} written={written} source={options["source"]}'
                    )
                )
            except StooqProviderError as exc:
                reason = f'{asset.symbol}: {exc}'
                failed.append(reason)
                self.stdout.write(self.style.ERROR(reason))
            time.sleep(options['sleep'])

        self.stdout.write(f'完成，总资产={len(assets)}，失败={len(failed)}')
        if failed:
            self.stdout.write('失败列表:')
            for item in failed:
                self.stdout.write(f'- {item}')
