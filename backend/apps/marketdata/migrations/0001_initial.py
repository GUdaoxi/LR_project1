from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        ('assets', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='PriceBar',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('date', models.DateField()),
                ('open', models.FloatField(blank=True, null=True)),
                ('high', models.FloatField(blank=True, null=True)),
                ('low', models.FloatField(blank=True, null=True)),
                ('close', models.FloatField(blank=True, null=True)),
                ('adj_close', models.FloatField()),
                ('volume', models.BigIntegerField(blank=True, null=True)),
                ('source', models.CharField(default='stooq', max_length=32)),
                ('created_at', models.DateTimeField(auto_now_add=True)),
                ('updated_at', models.DateTimeField(auto_now=True)),
                ('asset', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='price_bars', to='assets.asset')),
            ],
            options={
                'ordering': ['asset_id', 'date'],
            },
        ),
        migrations.AddConstraint(
            model_name='pricebar',
            constraint=models.UniqueConstraint(fields=('asset', 'date'), name='unique_asset_date_pricebar'),
        ),
    ]
