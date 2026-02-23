from __future__ import annotations

import numpy as np

from .returns import build_returns_matrix


def _portfolio_metrics(weights: np.ndarray, returns: np.ndarray, risk_free: float):
    port = returns @ weights
    mu_daily = float(np.mean(port))
    vol_daily = float(np.std(port))
    ann_return = (1 + mu_daily) ** 252 - 1
    ann_vol = vol_daily * np.sqrt(252)
    sharpe = (ann_return - risk_free) / ann_vol if ann_vol > 1e-12 else 0.0
    return {'ann_return': ann_return, 'ann_vol': ann_vol, 'sharpe': sharpe}


def _normalize_long_only(weights: np.ndarray):
    w = np.maximum(weights, 0)
    s = float(np.sum(w))
    if s <= 1e-12:
        return np.ones_like(w) / len(w)
    return w / s


def _risk_parity(cov: np.ndarray, max_iter: int = 3000):
    n = cov.shape[0]
    w = np.ones(n) / n
    for _ in range(max_iter):
        port_var = float(w @ cov @ w)
        if port_var <= 1e-12:
            return np.ones(n) / n
        mrc = cov @ w
        rc = w * mrc
        target = port_var / n
        grad = rc - target
        w = _normalize_long_only(w - 0.05 * grad)
        if np.max(np.abs(grad)) < 1e-7:
            break
    return w


def optimize_portfolio(symbols: list[str], method: str, lookback_days: int = 252, risk_free: float = 0.02):
    matrix = build_returns_matrix(symbols=symbols, lookback_days=lookback_days)
    cleaned = matrix['symbols']
    notes = matrix['notes']
    returns = matrix['returns']
    if len(cleaned) == 0 or returns.size == 0:
        return {'weights': [], 'metrics': {'ann_return': 0.0, 'ann_vol': 0.0, 'sharpe': 0.0}, 'notes': notes + ['有效资产不足']}

    n = len(cleaned)
    mu = np.mean(returns, axis=0)
    cov = np.cov(returns, rowvar=False) + np.eye(n) * 1e-8

    if method == 'equal_weight':
        w = np.ones(n) / n
    elif method == 'min_var':
        inv_cov = np.linalg.pinv(cov)
        w = _normalize_long_only(inv_cov @ np.ones(n))
    elif method == 'max_sharpe':
        rf_daily = (1 + risk_free) ** (1 / 252) - 1
        inv_cov = np.linalg.pinv(cov)
        w = _normalize_long_only(inv_cov @ (mu - rf_daily))
    elif method == 'risk_parity':
        w = _risk_parity(cov)
    else:
        raise ValueError('不支持的 method')

    metrics = _portfolio_metrics(w, returns, risk_free)
    payload = [{'symbol': symbol, 'w': float(weight)} for symbol, weight in zip(cleaned, w)]
    return {'weights': payload, 'metrics': metrics, 'notes': notes}
