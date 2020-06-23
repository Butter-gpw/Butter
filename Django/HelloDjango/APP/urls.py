from django.conf.urls import url

from APP import views

urlpatterns = [
    url(r'^addpersons/', views.add_person),
    url(r'^getpersons', views.get_person)

]