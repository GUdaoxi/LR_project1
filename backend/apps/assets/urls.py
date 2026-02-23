from django.urls import path

from .views import (
    AssetDetailView,
    AssetListView,
    RecommendationView,
    WatchlistDeleteView,
    WatchlistView,
)

urlpatterns = [
    path('assets/', AssetListView.as_view(), name='asset-list'),
    path('assets/<int:pk>/', AssetDetailView.as_view(), name='asset-detail'),
    path('watchlist/', WatchlistView.as_view(), name='watchlist'),
    path('watchlist/<int:asset_id>/', WatchlistDeleteView.as_view(), name='watchlist-delete'),
    path('recommendations/', RecommendationView.as_view(), name='recommendations'),
]
