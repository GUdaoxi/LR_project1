from django.contrib import admin

from .models import Asset, WatchlistItem


@admin.register(Asset)
class AssetAdmin(admin.ModelAdmin):
    list_display = ('symbol', 'name', 'market', 'currency', 'updated_at')
    search_fields = ('symbol', 'name')
    list_filter = ('market',)


@admin.register(WatchlistItem)
class WatchlistItemAdmin(admin.ModelAdmin):
    list_display = ('user', 'asset', 'created_at')
    search_fields = ('user__username', 'asset__symbol', 'asset__name')
    list_select_related = ('user', 'asset')
