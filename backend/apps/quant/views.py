from __future__ import annotations

from datetime import date

from rest_framework import serializers
from rest_framework.permissions import IsAuthenticated
from rest_framework.response import Response
from rest_framework.views import APIView

from .services.backtest import run_backtest
from .services.portfolio import optimize_portfolio


class OptimizeSerializer(serializers.Serializer):
    symbols = serializers.ListField(child=serializers.CharField(), allow_empty=False)
    method = serializers.ChoiceField(choices=['equal_weight', 'risk_parity', 'min_var', 'max_sharpe'])
    lookback_days = serializers.IntegerField(default=252, min_value=30, max_value=5000)
    risk_free = serializers.FloatField(default=0.02)


class BacktestSerializer(serializers.Serializer):
    symbols = serializers.ListField(child=serializers.CharField(), allow_empty=False)
    weights = serializers.DictField(child=serializers.FloatField(), allow_empty=False)
    start = serializers.DateField()
    end = serializers.DateField()
    rebalance = serializers.ChoiceField(choices=['buy_hold', 'monthly'], default='monthly')
    cost_bps = serializers.FloatField(default=10, min_value=0)

    def validate(self, attrs):
        if attrs['start'] >= attrs['end']:
            raise serializers.ValidationError('start 必须早于 end')
        return attrs


class PortfolioOptimizeView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        serializer = OptimizeSerializer(data=request.data)
        serializer.is_valid(raise_exception=True)
        data = serializer.validated_data
        result = optimize_portfolio(
            symbols=data['symbols'],
            method=data['method'],
            lookback_days=data['lookback_days'],
            risk_free=data['risk_free'],
        )
        return Response(result)


class BacktestRunView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        serializer = BacktestSerializer(data=request.data)
        serializer.is_valid(raise_exception=True)
        data = serializer.validated_data
        result = run_backtest(
            symbols=data['symbols'],
            weights=data['weights'],
            start=data['start'],
            end=data['end'],
            rebalance=data['rebalance'],
            cost_bps=data['cost_bps'],
        )
        return Response(result)
