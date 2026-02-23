from django.core.management.base import BaseCommand

from apps.assets.models import Asset


class Command(BaseCommand):
    help = 'Seed sample US/HK assets for demo.'

    def handle(self, *args, **options):
        assets = [
            ('AAPL', '苹果', 'US', 'USD', 'NASDAQ', '科技', '消费电子', '科技,消费,硬件,AI'),
            ('MSFT', '微软', 'US', 'USD', 'NASDAQ', '科技', '软件', '科技,云计算,AI,企业服务'),
            ('NVDA', '英伟达', 'US', 'USD', 'NASDAQ', '科技', '半导体', '科技,芯片,AI'),
            ('TSLA', '特斯拉', 'US', 'USD', 'NASDAQ', '可选消费', '汽车', '新能源,汽车,科技'),
            ('AMZN', '亚马逊', 'US', 'USD', 'NASDAQ', '可选消费', '电商', '消费,电商,云计算'),
            ('GOOGL', '谷歌', 'US', 'USD', 'NASDAQ', '通信服务', '互联网', '互联网,广告,AI'),
            ('META', 'Meta', 'US', 'USD', 'NASDAQ', '通信服务', '社交媒体', '互联网,社交,广告'),
            ('JPM', '摩根大通', 'US', 'USD', 'NYSE', '金融', '银行', '金融,银行,价值'),
            ('UNH', '联合健康', 'US', 'USD', 'NYSE', '医疗保健', '保险', '医疗,保险,防御'),
            ('XOM', '埃克森美孚', 'US', 'USD', 'NYSE', '能源', '石油天然气', '能源,周期,分红'),
            ('0700.HK', '腾讯控股', 'HK', 'HKD', 'HKEX', '科技', '互联网', '科技,互联网,游戏,AI'),
            ('9988.HK', '阿里巴巴', 'HK', 'HKD', 'HKEX', '可选消费', '电商', '消费,电商,云计算'),
            ('3690.HK', '美团', 'HK', 'HKD', 'HKEX', '可选消费', '本地生活', '消费,互联网,平台经济'),
            ('1810.HK', '小米集团', 'HK', 'HKD', 'HKEX', '科技', '消费电子', '科技,手机,AIoT'),
            ('9618.HK', '京东集团', 'HK', 'HKD', 'HKEX', '可选消费', '电商', '消费,物流,电商'),
            ('9999.HK', '网易云音乐', 'HK', 'HKD', 'HKEX', '通信服务', '在线娱乐', '互联网,音乐,内容'),
            ('2382.HK', '舜宇光学', 'HK', 'HKD', 'HKEX', '科技', '光学元件', '科技,硬件,汽车电子'),
            ('0005.HK', '汇丰控股', 'HK', 'HKD', 'HKEX', '金融', '银行', '金融,银行,分红'),
            ('1299.HK', '友邦保险', 'HK', 'HKD', 'HKEX', '金融', '保险', '金融,保险,长期配置'),
            ('2318.HK', '中国平安', 'HK', 'HKD', 'HKEX', '金融', '保险', '金融,保险,综合金融'),
        ]

        created_count = 0
        for symbol, name, market, currency, exchange, sector, industry, tags in assets:
            _, created = Asset.objects.update_or_create(
                symbol=symbol,
                defaults={
                    'name': name,
                    'market': market,
                    'currency': currency,
                    'exchange': exchange,
                    'sector': sector,
                    'industry': industry,
                    'tags': tags,
                    'description': f'{name}（{symbol}）示例数据',
                },
            )
            if created:
                created_count += 1

        self.stdout.write(self.style.SUCCESS(f'Seed completed. total={len(assets)}, created={created_count}'))
