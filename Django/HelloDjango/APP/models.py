from django.db import models


# Create your models here.
class Student(models.Model):
    s_name = models.CharField(max_length=16)
    s_age = models.IntegerField(default=1)
    s_hobby = models.CharField(max_length=32, null=True, blank=True)

    @classmethod
    def creat(cls, s_name, s_age=100, s_hobby='gaming'):
        return cls(s_name, s_age, s_hobby)
