from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='Asset',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('symbol', models.CharField(max_length=32, unique=True)),
                ('name', models.CharField(max_length=128)),
                ('market', models.CharField(choices=[('US', '美股'), ('HK', '港股')], max_length=2)),
                ('currency', models.CharField(max_length=8)),
                ('exchange', models.CharField(blank=True, max_length=64)),
                ('sector', models.CharField(blank=True, max_length=64)),
                ('industry', models.CharField(blank=True, max_length=64)),
                ('tags', models.TextField(blank=True, help_text='逗号分隔标签，如 科技,AI')),
                ('description', models.TextField(blank=True)),
                ('created_at', models.DateTimeField(auto_now_add=True)),
                ('updated_at', models.DateTimeField(auto_now=True)),
            ],
            options={
                'ordering': ['symbol'],
            },
        ),
        migrations.CreateModel(
            name='WatchlistItem',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('created_at', models.DateTimeField(auto_now_add=True)),
                ('asset', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='watchers', to='assets.asset')),
                ('user', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='watchlist_items', to=settings.AUTH_USER_MODEL)),
            ],
            options={
                'ordering': ['-created_at'],
            },
        ),
        migrations.AddConstraint(
            model_name='watchlistitem',
            constraint=models.UniqueConstraint(fields=('user', 'asset'), name='unique_user_asset_watch'),
        ),
    ]
