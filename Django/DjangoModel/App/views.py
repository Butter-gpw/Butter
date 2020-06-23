from django.http import HttpResponse
from django.shortcuts import render

from App.models import Person, IDCard


def hello(request):
    return HttpResponse('hello')


def add_person(request):

    username = request.GET.get('username')

    person = Person()

    person.p_name = username

    person.save()
    return HttpResponse('Person创建成功 %d' %person.id)


def add_idcard(request):
    id_num = request.GET.get('idnum')
    idcard = IDCard()
    idcard.id_num = id_num
    idcard.save()

    return HttpResponse('IDCard %d' %idcard.id)


def bind_card(request):

    person = Person.objects.last()

    idcard = IDCard.objects.last()

    idcard.id_person = person

    idcard.save()

    return HttpResponse('绑定成功')