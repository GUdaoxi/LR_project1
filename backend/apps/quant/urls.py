from django.urls import path

from .views import BacktestRunView, PortfolioOptimizeView

urlpatterns = [
    path('portfolio/optimize/', PortfolioOptimizeView.as_view(), name='portfolio-optimize'),
    path('backtest/run/', BacktestRunView.as_view(), name='backtest-run'),
]
