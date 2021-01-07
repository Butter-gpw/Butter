//
// Created by Butter on 2021/1/6.
//

#ifndef STAFF_MANAGEMENT_SYSTEM_WORKERMANAGER_H
#define STAFF_MANAGEMENT_SYSTEM_WORKERMANAGER_H
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"


class workerManager {
public:
    workerManager();

    //显示菜单
    void show_Menu();

    //退出接口
    void ExitSystem();

    //记录职工人数
    int m_EmpNum;

    //记录数组指针
    worker** m_EmpArray;

    //添加职工
    void Add_Emp();

    //保存文件
    void save();

    //判断文件是否为空
    bool m_FileIsEmpty;

    //统计文件中人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工
    void show_Emp();

    //删除职工
    void Del_Emp();

    //判断职工是否存在,如果存在返回职工所在数组位置，不存在返回-1
    int IsExist(int id);

    //修改职工
    void Mod_Ecp();

    //查找职工
    void Find_Emp();

    //排序职工
    void Sort_Emp();

    //清空文件
    void Clean_File();

    ~workerManager();

};


#endif //STAFF_MANAGEMENT_SYSTEM_WORKERMANAGER_H
