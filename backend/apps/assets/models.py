from django.conf import settings
from django.db import models


class Asset(models.Model):
    """股票/资产基础信息。"""

    class Market(models.TextChoices):
        US = 'US', '美股'
        HK = 'HK', '港股'

    symbol = models.CharField(max_length=32, unique=True)
    name = models.CharField(max_length=128)
    market = models.CharField(max_length=2, choices=Market.choices)
    currency = models.CharField(max_length=8)
    exchange = models.CharField(max_length=64, blank=True)
    sector = models.CharField(max_length=64, blank=True)
    industry = models.CharField(max_length=64, blank=True)
    tags = models.TextField(blank=True, help_text='逗号分隔标签，如 科技,AI')
    description = models.TextField(blank=True)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    class Meta:
        ordering = ['symbol']

    def __str__(self) -> str:
        return f'{self.symbol} - {self.name}'

    @property
    def tags_list(self) -> list[str]:
        return [tag.strip() for tag in self.tags.split(',') if tag.strip()]


class WatchlistItem(models.Model):
    """用户关注资产。"""

    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='watchlist_items')
    asset = models.ForeignKey(Asset, on_delete=models.CASCADE, related_name='watchers')
    created_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        constraints = [
            models.UniqueConstraint(fields=['user', 'asset'], name='unique_user_asset_watch')
        ]
        ordering = ['-created_at']

    def __str__(self) -> str:
        return f'{self.user_id}:{self.asset.symbol}'
