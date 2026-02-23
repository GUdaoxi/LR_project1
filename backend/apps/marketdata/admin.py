from django.contrib import admin

from .models import PriceBar


@admin.register(PriceBar)
class PriceBarAdmin(admin.ModelAdmin):
    list_display = ('asset', 'date', 'adj_close', 'close', 'source', 'updated_at')
    list_filter = ('asset', 'date', 'source')
    search_fields = ('asset__symbol',)
    ordering = ('-date',)
