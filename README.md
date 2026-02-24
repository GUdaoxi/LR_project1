# LR Project1 Monorepo (Iteration 3 Quant MVP)

本仓库包含：

- backend：Django + DRF + SimpleJWT + PostgreSQL
- frontend：Vue3 + Vite + TypeScript + TailwindCSS
- 新增：`marketdata`（美股日线入库）+ `quant`（组合优化/回测）+ 前端“组合实验室”

## 启动方式

### 1) 启动后端与数据库

```bash
cd /workspace/LR_project1/compose
docker compose up --build -d
```

### 2) 初始化演示资产数据

```bash
cd /workspace/LR_project1/compose
docker compose exec backend python manage.py seed_assets
```

### 3) 拉取美股日线数据（Stooq）

```bash
cd /workspace/LR_project1/compose
docker compose exec backend python manage.py fetch_prices --symbols AAPL,MSFT,NVDA --lookback 730 --source stooq
docker compose exec backend python -c "from apps.marketdata.models import PriceBar; print(PriceBar.objects.count())"
```

> 说明：仅支持 `market=US`；MVP 的 `adj_close = close`。

### 4) 启动前端

```bash
cd /workspace/LR_project1/frontend
npm install
npm run dev
```

## 访问地址

- 后端：<http://localhost:8000>
- 健康检查：<http://localhost:8000/healthz>
- 前端：<http://localhost:5173>
- 组合实验室：<http://localhost:5173/lab/portfolio>

## API 简述（JWT 保护）

- `POST /api/auth/token/` 获取 JWT
- `GET /api/assets/` 资产检索（query/market/tag/ordering）
- `GET /api/assets/<id>/` 资产详情
- `GET/POST /api/watchlist/` 查询/添加关注
- `DELETE /api/watchlist/<asset_id>/` 取消关注
- `GET /api/recommendations/` 推荐列表
- `POST /api/portfolio/optimize/` 组合优化
- `POST /api/backtest/run/` 回测

## 组合优化 / 回测示例

```bash
# 获取 token
curl -X POST http://localhost:8000/api/auth/token/ \
  -H 'Content-Type: application/json' \
  -d '{"username":"tester","password":"pass1234"}'

# 组合优化（等权）
curl -X POST http://localhost:8000/api/portfolio/optimize/ \
  -H 'Authorization: Bearer <ACCESS_TOKEN>' \
  -H 'Content-Type: application/json' \
  -d '{"symbols":["AAPL","MSFT","NVDA"],"method":"equal_weight","lookback_days":252,"risk_free":0.02}'

# 回测
curl -X POST http://localhost:8000/api/backtest/run/ \
  -H 'Authorization: Bearer <ACCESS_TOKEN>' \
  -H 'Content-Type: application/json' \
  -d '{"symbols":["AAPL","MSFT","NVDA"],"weights":{"AAPL":0.34,"MSFT":0.33,"NVDA":0.33},"start":"2022-01-01","end":"2025-12-31","rebalance":"monthly","cost_bps":10}'
```

## 后端测试

```bash
cd /workspace/LR_project1/backend
python -m pip install -r requirements.txt
python manage.py test
```

## 验收清单命令

```bash
curl http://localhost:8000/healthz

docker compose exec backend python manage.py fetch_prices --symbols AAPL,MSFT,NVDA --lookback 730 --source stooq

docker compose exec backend curl -s -X POST http://localhost:8000/api/portfolio/optimize/ \
  -H "Authorization: Bearer <ACCESS_TOKEN>" -H "Content-Type: application/json" \
  -d '{"symbols":["AAPL","MSFT","NVDA"],"method":"equal_weight"}'

docker compose exec backend curl -s -X POST http://localhost:8000/api/backtest/run/ \
  -H "Authorization: Bearer <ACCESS_TOKEN>" -H "Content-Type: application/json" \
  -d '{"symbols":["AAPL","MSFT","NVDA"],"weights":{"AAPL":0.34,"MSFT":0.33,"NVDA":0.33},"start":"2022-01-01","end":"2025-12-31","rebalance":"monthly","cost_bps":10}'
```
