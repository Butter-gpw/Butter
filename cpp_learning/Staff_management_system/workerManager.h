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

    //��ʾ�˵�
    void show_Menu();

    //�˳��ӿ�
    void ExitSystem();

    //��¼ְ������
    int m_EmpNum;

    //��¼����ָ��
    worker** m_EmpArray;

    //���ְ��
    void Add_Emp();

    //�����ļ�
    void save();

    //�ж��ļ��Ƿ�Ϊ��
    bool m_FileIsEmpty;

    //ͳ���ļ�������
    int get_EmpNum();

    //��ʼ��Ա��
    void init_Emp();

    //��ʾְ��
    void show_Emp();

    //ɾ��ְ��
    void Del_Emp();

    //�ж�ְ���Ƿ����,������ڷ���ְ����������λ�ã������ڷ���-1
    int IsExist(int id);

    //�޸�ְ��
    void Mod_Ecp();

    //����ְ��
    void Find_Emp();

    //����ְ��
    void Sort_Emp();

    //����ļ�
    void Clean_File();

    ~workerManager();

};


#endif //STAFF_MANAGEMENT_SYSTEM_WORKERMANAGER_H
