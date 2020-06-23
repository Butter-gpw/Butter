import random

from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
from APP.models import Student


def hello(request):
    return HttpResponse('hello world')


def add_person(request):
    for i in range(15):
        person = Student()
        flag = random.randrange(100)
        person.s_name = 'Tom%d' % flag
        person.s_age = flag
        person.save()
    return HttpResponse('批量创建成功')


def get_person(request):
    person = Student.objects.all().order_by('s_age')
    person_value = person.values()
    print(person_value)
    context = {
        'person': person
    }
    return render(request, 'personlist.html', context=context)
