from django.conf.urls import url

from App import views

urlpatterns=[
    url(r'^hello', views.hello, name='hello'),
    url(r'^addperson/', views.add_person, name='add_person'),
    url(r'^addidcard/', views.add_idcard, name='add_idcadr'),
    url(r'^bindcard/', views.bind_card, name='bind_card'),
]