from django.conf.urls import url

from App import views

urlpatterns=[
    url(r'^hello/', views.hello),
    url(r'^index/', views.index),
    url(r'^getstudents/', views.get_student),
    url(r'^temp/', views.temp),
    url(r'^home/', views.home)
]