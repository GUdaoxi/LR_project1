from django.db import models


class PriceBar(models.Model):
    asset = models.ForeignKey('assets.Asset', on_delete=models.CASCADE, related_name='price_bars')
    date = models.DateField()
    open = models.FloatField(null=True, blank=True)
    high = models.FloatField(null=True, blank=True)
    low = models.FloatField(null=True, blank=True)
    close = models.FloatField(null=True, blank=True)
    adj_close = models.FloatField()
    volume = models.BigIntegerField(null=True, blank=True)
    source = models.CharField(max_length=32, default='stooq')
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    class Meta:
        ordering = ['asset_id', 'date']
        constraints = [
            models.UniqueConstraint(fields=['asset', 'date'], name='unique_asset_date_pricebar')
        ]

    def __str__(self) -> str:
        return f'{self.asset.symbol}@{self.date}'
