from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
from django.template import loader

from App.models import Student


def hello(request):
    return HttpResponse('hello')


def index(request):
    # 本质也是返回的HttpResponse，他帮我们把模版和context数据渲染成字符串
    # return render(request, 'index.html')

    # 见名知意
    temp = loader.get_template('index.html')

    content = temp.render()

    return HttpResponse(content)


def get_student(request):
    student = Student.objects.all()

    student_dict = {
        'hobby': 'coding',
        'time': 'one year',
    }

    data = {
        'student': student,
        'student_dict': student_dict,
        'count': 5,
        'code': '''
                <h2>睡着了</h2>
        
        ''',
    }
    return render(request, 'student_list.html', context=data)


def temp(request):
    return render(request, 'home.html', context={'title': 'home'})


def home(request):
    return render(request, 'home_mine.html')
