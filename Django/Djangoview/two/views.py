import hashlib
import random
import time

from django.http import HttpResponse, JsonResponse
from django.shortcuts import render, redirect
from django.urls import reverse

from two.models import Student


def hello(request):
    return HttpResponse('hello')


def login(request):
    if request.method == 'GET':
        return render(request, 'two_login.html')

    elif request.method == 'POST':

        username = request.POST.get('username')

        request.session['username'] = username

        return HttpResponse('登录成功')


def mine(request):
    username = request.session.get('username')

    return render(request, 'two_mine.html', context=locals())


def logout(request):
    response = redirect(reverse('two:mine'))

    # response.delete_cookie('sessionid') 只删 cookie

    # del request.session['username'] 只删session

    # session cookie一起删
    request.session.flush()

    return response


def register(request):
    if request.method == 'GET':
        return render(request, 'student_register.html')
    elif request.method == 'POST':
        username = request.POST.get('username')

        password = request.POST.get('password')

        try:
            student = Student()
            student.s_name = username
            student.s_password = password
            student.save()

        except Exception as e:
            return redirect(reverse('two:register'))

        return HttpResponse('注册成功')


def student_login(request):  # 登录页面
    if request.method == 'GET':  # 用户请求页面就返回页面
        return render(request, 'student_login.html')
    elif request.method == 'POST':  # 用户在页面中输入用户名和密码
        username = request.POST.get('username')
        password = request.POST.get('password')
        students = Student.objects.filter(s_name=username).filter(s_password=password)  # 根据用户名密码在数据库中筛选出用户信息

        if students.exists():  # 如果用户存在
            student = students.first()  # 肯定是在第一个中

            ip = request.META.get('REMOTE_ADDR')  # 获取用户的IP地址

            token = generate_token(ip, username)  # 生成token

            student.s_token = token  # 把token传入数据库

            student.save()  # 上传

            # response = HttpResponse('用户登录成功')  # 返回部分
            #
            # response.set_cookie('token', token)  # 返回时把cookie设置成token
            #
            # return response

            data = {
                'status': 200,
                "msg": 'login success',
                'token': token
            }
            return JsonResponse(data=data)
        # return redirect(reverse('two:student_login'))
        data = {
            'status': 800,
            "msg": 'verify fail',
        }
        return JsonResponse(data=data)


def generate_token(ip, username):  # 生成token的函数 用ip+时间+用户名通过哈希算法生成
    c_time = time.ctime()

    r = username

    return hashlib.new('md5', (ip + c_time + r).encode('utf-8')).hexdigest()


def student_mine(request):
    #token = request.COOKIES.get('token')
    token = request.GET.get('token')

    try:
        student = Student.objects.get(s_token=token)

    except Exception as e:
        return redirect(reverse('two:student_login'))

    # return HttpResponse(student.s_name)
    data = {
        'msg': 'ok',
        'status': 200,
        'data': {
            'username': student.s_name
        }
    }
    return JsonResponse(data=data)
