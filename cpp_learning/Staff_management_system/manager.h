//
// Created by Butter on 2021/1/6.
//
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager : public worker{
public:
    Manager(int id,string name,int dId);

    //显示个人信息
    void showInfo();

    //获取岗位名称
    string getDeptName();
};

