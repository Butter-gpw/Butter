from django.conf.urls import url

from Two import views

urlpatterns = [
    url(r'^getuser/', views.get_user),
    url(r'^getorder/', views.get_order),
    url(r'^getgrade/', views.get_grade),
    url(r'^getanimals/', views.get_animals),

]