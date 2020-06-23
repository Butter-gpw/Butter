# -*- coding: utf-8 -*-
# Generated by Django 1.11.7 on 2020-05-12 21:03
from __future__ import unicode_literals

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('Two', '0002_order'),
    ]

    operations = [
        migrations.CreateModel(
            name='Grade',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('g_name', models.CharField(max_length=16)),
            ],
        ),
        migrations.CreateModel(
            name='Student',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('s_name', models.CharField(max_length=16)),
                ('s_grade', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='Two.Grade')),
            ],
        ),
    ]
