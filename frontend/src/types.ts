export type MarketType = 'US' | 'HK'

export interface Asset {
  id: number
  symbol: string
  name: string
  market: MarketType
  market_display: string
  currency: string
  exchange: string
  sector: string
  industry: string
  tags: string
  tags_list: string[]
  description: string
  created_at: string
  updated_at: string
}

export interface WatchlistItem {
  asset: Asset
  created_at: string
}

export interface Recommendation {
  id: number
  symbol: string
  name: string
  market: MarketType
  market_display: string
  currency: string
  reason: string
}

export interface PaginatedResponse<T> {
  count: number
  next: string | null
  previous: string | null
  results: T[]
}
