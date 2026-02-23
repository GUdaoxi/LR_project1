# LR Project1 Monorepo (Iteration 1)

本仓库在 **Windows + WSL2 (Ubuntu)** 环境下，提供以下基础栈：

- backend: Django + DRF + SimpleJWT
- db: PostgreSQL (Docker)
- frontend: Vue 3 + Vite + TypeScript（本地 dev server）
- compose: `docker compose` 一键启动至少 db + backend

## 目录结构

```text
.
├── backend/        # Django + DRF + SimpleJWT
├── frontend/       # Vue3 + Vite + TS
└── compose/        # docker-compose.yml + .env
```

## WSL2 Ubuntu 前置准备

在 WSL2 Ubuntu 中确认：

1. Docker Desktop 已安装并开启 WSL 集成。
2. Ubuntu 内可执行 `docker` 与 `docker compose`。
3. Node.js 18+（建议 20+）用于前端本地调试。

## 一键启动 backend + postgres

> 以下命令都在 **WSL2 Ubuntu 终端**、仓库根目录执行。

```bash
cd /workspace/LR_project1
cd compose
docker compose up --build -d
```

服务启动后：

- Django backend: <http://localhost:8000>
- 健康检查: <http://localhost:8000/healthz>

验证健康接口：

```bash
curl http://localhost:8000/healthz
# {"status":"ok"}
```

## JWT 获取接口

SimpleJWT 默认获取 token 接口：

- `POST /api/auth/token/`

示例（先创建一个 Django 用户后再调用）：

```bash
cd /workspace/LR_project1/compose
docker compose exec backend python manage.py createsuperuser

curl -X POST http://localhost:8000/api/auth/token/ \
  -H 'Content-Type: application/json' \
  -d '{"username":"<your_user>","password":"<your_password>"}'
```

返回示例：

```json
{
  "refresh": "...",
  "access": "..."
}
```

## 运行后端测试

```bash
cd /workspace/LR_project1/compose
docker compose exec backend python manage.py test
```

## 前端本地开发（Vite）

```bash
cd /workspace/LR_project1/frontend
npm install
npm run dev -- --host 0.0.0.0 --port 5173
```

浏览器访问：<http://localhost:5173>

## 环境变量（compose/.env）

数据库与 Django 配置使用 `compose/.env` 管理：

- `POSTGRES_DB`
- `POSTGRES_USER`
- `POSTGRES_PASSWORD`
- `POSTGRES_HOST`
- `POSTGRES_PORT`
- `DJANGO_SECRET_KEY`
- `DJANGO_DEBUG`
- `DJANGO_ALLOWED_HOSTS`

可按需修改后，重新执行：

```bash
cd /workspace/LR_project1/compose
docker compose up -d --build
```
