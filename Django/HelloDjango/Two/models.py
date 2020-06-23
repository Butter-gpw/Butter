from django.db import models


# Create your models here.
class User(models.Model):
    u_name = models.CharField(max_length=16)
    u_password = models.CharField(max_length=256)


class Order(models.Model):
    o_num = models.CharField(max_length=16, unique=True)
    o_time = models.DateTimeField(auto_now_add=True)


class Grade(models.Model):
    g_name = models.CharField(max_length=16)


class Student(models.Model):
    s_name = models.CharField(max_length=16)
    s_grade = models.ForeignKey(Grade)


class AnimalManager(models.Manager):

    def get_queryset(self):
        return super(AnimalManager, self).get_queryset().filter(is_delete=False)

    def create_animal(self, a_name='rabbit'):
        a = self.model()
        a.a_name = a_name

        return a


class Animal(models.Model):
    a_name = models.CharField(max_length=16)
    is_delete = models.BooleanField(default=False)

    object = AnimalManager()
