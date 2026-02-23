# LR Project1 Monorepo (Iteration 2 MVP)

本仓库包含：

- backend：Django + DRF + SimpleJWT + PostgreSQL
- frontend：Vue3 + Vite + TypeScript + TailwindCSS + shadcn-vue 风格组件

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

### 3) 启动前端

```bash
cd /workspace/LR_project1/frontend
npm install
npm run dev
```

## 访问地址

- 后端：<http://localhost:8000>
- 健康检查：<http://localhost:8000/healthz>
- 前端：<http://localhost:5173>

## API 简述

- `POST /api/auth/token/` 获取 JWT
- `GET /api/assets/` 资产检索（query/market/tag/ordering）
- `GET /api/assets/<id>/` 资产详情
- `GET/POST /api/watchlist/` 查询/添加关注
- `DELETE /api/watchlist/<asset_id>/` 取消关注
- `GET /api/recommendations/` 推荐列表（含中文 reason）

## 后端测试

```bash
cd /workspace/LR_project1/backend
python -m pip install -r requirements.txt
python manage.py test
```
