from __future__ import annotations

from datetime import date

import numpy as np

from .returns import build_returns_matrix


def run_backtest(symbols: list[str], weights: dict[str, float], start: date, end: date, rebalance: str = 'monthly', cost_bps: float = 10):
    matrix = build_returns_matrix(symbols=symbols, start=start, end=end)
    notes = matrix['notes']
    dates = matrix['dates']
    returns = matrix['returns']
    cleaned = matrix['symbols']

    if len(cleaned) == 0 or returns.size == 0:
        return {'equity_curve': [], 'drawdown_curve': [], 'stats': _empty_stats(), 'notes': notes + ['有效资产不足']}

    w = np.array([max(float(weights.get(s, 0.0)), 0.0) for s in cleaned], dtype=float)
    if np.sum(w) <= 1e-12:
        w = np.ones(len(cleaned)) / len(cleaned)
        notes.append('输入权重无效，已回退等权')
    else:
        w /= np.sum(w)

    cost = cost_bps / 10000
    nav = 1.0
    peak = 1.0
    equity_curve = [{'date': dates[0].isoformat(), 'nav': nav}]
    drawdown_curve = [{'date': dates[0].isoformat(), 'dd': 0.0}]

    current_w = w.copy()
    turnover_total = 0.0
    rebalance_count = 0

    for idx in range(returns.shape[0]):
        dt = dates[idx + 1]
        day_ret = returns[idx]
        port_ret = float(current_w @ day_ret)
        nav *= (1 + port_ret)

        grown = current_w * (1 + day_ret)
        if np.sum(grown) > 1e-12:
            current_w = grown / np.sum(grown)

        do_rebalance = rebalance == 'monthly' and dt.month != dates[idx].month
        if do_rebalance:
            traded = float(np.sum(np.abs(w - current_w)))
            turnover_total += traded
            nav *= max(0.0, 1 - traded * cost)
            current_w = w.copy()
            rebalance_count += 1

        peak = max(peak, nav)
        dd = nav / peak - 1
        equity_curve.append({'date': dt.isoformat(), 'nav': float(nav)})
        drawdown_curve.append({'date': dt.isoformat(), 'dd': float(dd)})

    stats = _calc_stats(np.array([x['nav'] for x in equity_curve]), returns, w, turnover_total, rebalance_count)
    return {'equity_curve': equity_curve, 'drawdown_curve': drawdown_curve, 'stats': stats, 'notes': notes}


def _calc_stats(nav_series: np.ndarray, returns: np.ndarray, w: np.ndarray, turnover: float, rebalance_count: int):
    total_days = max(len(nav_series) - 1, 1)
    cagr = float(nav_series[-1] ** (252 / total_days) - 1)
    port_daily = returns @ w
    ann_vol = float(np.std(port_daily) * np.sqrt(252))
    sharpe = float(cagr / ann_vol) if ann_vol > 1e-12 else 0.0
    peaks = np.maximum.accumulate(nav_series)
    dds = nav_series / peaks - 1
    max_dd = float(np.min(dds))
    return {
        'CAGR': cagr,
        'ann_vol': ann_vol,
        'max_dd': max_dd,
        'sharpe': sharpe,
        'turnover': float(turnover),
        'rebalance_count': rebalance_count,
    }


def _empty_stats():
    return {'CAGR': 0.0, 'ann_vol': 0.0, 'max_dd': 0.0, 'sharpe': 0.0, 'turnover': 0.0, 'rebalance_count': 0}
