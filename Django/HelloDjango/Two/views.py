from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
from Two.models import User, Order, Student, Grade, Animal


def get_user(request):
    username = 'sunker'
    password = '120'
    users = User.objects.filter(u_name=username)

    if users.exit():
        user = users.first()

        if user.u_password == password:
            print('获取用户信息成功')
        else:
            print('密码错误')

    else:
        print('用户不存在')

    return HttpResponse('获取成功')


def get_order(request):
    order = Order.objects.filter(o_time__month=5)

    for order in order:
        print(order.o_num)

    return HttpResponse('获取订单成功')


def get_grade(request):
    grade = Grade.objects.filter(student__s_name='jack')

    for grade in grade:
        print(grade.g_name)

    return HttpResponse('获取成功')


def get_animals(request):

    animal = Animal.object.all()

    for a in animal:
        print(a.a_name)

    Animal.object.create_animal('snack')

    return HttpResponse('成功')
