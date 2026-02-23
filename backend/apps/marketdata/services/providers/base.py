from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass
from datetime import date


@dataclass
class Bar:
    date: date
    open: float | None
    high: float | None
    low: float | None
    close: float | None
    adj_close: float
    volume: int | None


class BasePriceProvider(ABC):
    @abstractmethod
    def normalize_symbol(self, asset_symbol: str) -> str:
        raise NotImplementedError

    @abstractmethod
    def fetch_daily(self, symbol: str, start: date, end: date) -> list[Bar]:
        raise NotImplementedError
