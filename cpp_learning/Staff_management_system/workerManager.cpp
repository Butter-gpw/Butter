//
// Created by Butter on 2021/1/6.
//
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"


workerManager::workerManager() {
    //1�ļ�������
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout<<"�ļ�������"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //2�ļ���������Ϊ��
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //�ļ�Ϊ��
        cout<<"�ļ�Ϊ��"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //3�ļ����ڲ�Ϊ��
    int num = this->get_EmpNum();
//    cout<<"ְ������Ϊ: "<<num<<endl;
    this->m_EmpNum = num;

    //���ٿռ�
    this->m_EmpArray = new worker*[this->m_EmpNum];
    //���ļ��е����ݣ��浽������
    this->init_Emp();
    this->m_FileIsEmpty = false;

//    for (int i = 0;i< this->m_EmpNum;i++){
//        cout<<"ְ����ţ�"<<this->m_EmpArray[i]->m_Id
//        <<"������"<<this->m_EmpArray[i]->m_Name
//        <<"���ű�ţ�"<<this->m_EmpArray[i]->m_DeptId<<endl;
//    }
}


workerManager::~workerManager() {
    if (!this->m_EmpArray){
        for (int i = 0; i < this->m_EmpNum; ++i) {
            if(!this->m_EmpArray[i]){
                delete this->m_EmpArray[i];
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
}


void workerManager::show_Menu() {
    cout<<"��ӭʹ��ְ������ϵͳ"<<endl;
    cout<<"0.�˳��������"<<endl;
    cout<<"1.����Ա����Ϣ"<<endl;
    cout<<"2.��ʾְ����Ϣ"<<endl;
    cout<<"3.ɾ����ְְ��"<<endl;
    cout<<"4.�޸�ְ����Ϣ"<<endl;
    cout<<"5.����ְ����Ϣ"<<endl;
    cout<<"6.���ձ������"<<endl;
    cout<<"7.��������ĵ�"<<endl;
    cout<<endl;

}


void workerManager::ExitSystem() {
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);
}


void workerManager::Add_Emp() {
    cout<<"���������ְ��������"<<endl;
    int addNum = 0;//�����û�����������
    cin>>addNum;

    if(addNum>0){
        //���
        //��������¿ռ��С
        int newSize = this->m_EmpNum + addNum;//�¿ռ��С

        //�����¿ռ�
        worker** newSpace = new worker*[newSize];

        //��ԭ���ռ������ݣ��������¿ռ���
        if(this->m_EmpArray!= nullptr){
            for (int i = 0; i < this->m_EmpNum ; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //���������
        for (int i = 0;i<addNum;i++){
            int id;//ְ�����
            string name;//ְ������
            int dSelect;//����ѡ��

            cout<<"�������"<<i+1<<"����ְ����ţ�"<<endl;
            cin>>id;

            cout<<"�������"<<i+1<<"����ְ��������"<<endl;
            cin>>name;

            cout<<"��ѡ���ְ����λ��"<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;
            cin>>dSelect;

            worker* worker = nullptr;
            switch (dSelect) {
                case 1:
                    worker = new employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                default:
                    break;

            }

            //������ְ��ָ�룬���浽������
            newSpace[this->m_EmpNum+i] = worker;
        }

        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;

        //�����¿ռ�ָ��
        this->m_EmpArray = newSpace;

        //�����µ�ְ������
        this->m_EmpNum = newSize;


        //����ְ����Ϊ��
        this->m_FileIsEmpty = false;
        //�ɹ���Ӻ󱣴浽�ļ���

        //��ʾ
        cout<<"��ӳɹ�"<<endl;

        //�������ݵ��ļ���
        this->save();

    } else{
        cout<<"��������"<<endl;
    }

    //���������أ������ص��ϼ�Ŀ¼
    system("pause");
    system("cls");
}

void workerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//д�ļ�

    //��ÿ���˵�����д�뵽�ļ���
    for(int i = 0;i<this->m_EmpNum;i++){
        ofs<< this->m_EmpArray[i]->m_Id<<" "
        <<this->m_EmpArray[i]->m_Name<<" "
        <<this->m_EmpArray[i]->m_DeptId<<endl;
    }

    //�ر��ļ�

    ofs.close();

}

int workerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num = 0;
    while (ifs>>id && ifs>>name && ifs>>dId){
        num++;
    }

    return num;
}


void workerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs>>id && ifs>>name && ifs>>dId){
        worker* worker= nullptr;
        if (dId == 1){
            worker = new employee(id,name,dId);
        }else if (dId==2){
            worker = new Manager(id,name,dId);
        } else{
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }

    //�ر��ļ�
    ifs.close();
}


void workerManager::show_Emp(){
    //�ж��ļ��Ƿ�Ϊ��
    if (this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }else{
        for (int i=0;i<m_EmpNum;i++){
            //���ö�̬���ýӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}


//ɾ��ְ��
void workerManager::Del_Emp(){
    if (this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    } else{
        cout<<"������Ҫɾ��ְ����ţ�"<<endl;
        int id = 0;
        cin>>id;

        int index = this->IsExist(id);
        if (index !=-1){//˵��ְ������
            for (int i = index ; i <this->m_EmpNum-1 ; i++) {
                //����ǰ��
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            //����ͬ�����µ��ļ���
            this->save();
            cout<<"ɾ���ɹ�"<<endl;
        }else{
            cout<<"ɾ��ʧ�ܣ�δ�ҵ���ְ��"<<endl;
        }
    }
    system("pause");
    system("cls");
}

//�ж�ְ���Ƿ����,������ڷ���ְ����������λ�ã������ڷ���-1
int workerManager::IsExist(int id){
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id==id){
            index = i;
            break;
        }
    }
    return index;
}


void workerManager::Mod_Ecp(){
    if (this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }else{
        cout<<"�������޸�ְ����ţ�"<<endl;
        int id;
        cin>>id;

        int ret = this->IsExist(id);
        if(ret != -1){
            //���ұ�ŵ�ְ��
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newname = "";
            int dSelect = 0;

            cout<<"�鵽��"<<id<<"��ְ������������ְ���ţ�"<<endl;
            cin>>newId;

            cout<<"�������µ�����"<<endl;
            cin>>newname;

            cout<<"�������λ:"<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;

            cin>>dSelect;

            worker* worker = nullptr;

            switch (dSelect) {
                case 1:
                    worker = new employee(newId,newname,dSelect);
                    break;
                case 2:
                    worker = new Manager(newId,newname,dSelect);
                    break;
                case 3:
                    worker = new Boss(newId,newname,dSelect);
                    break;
                default:
                    break;
            }
            this->m_EmpArray[ret] = worker;

            cout<<"�޸ĳɹ�"<<endl;

            this->save();
        }else{
            cout<<"�޸�ʧ�ܣ����޴���"<<endl;
        }

    }
    system("pause");
    system("cls");

}


void workerManager::Find_Emp(){
    if (this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }else {
        cout<<"��������ҷ�ʽ��"<<endl;
        cout<<"1������ְ����Ų���"<<endl;
        cout<<"2������ְ����������"<<endl;

        int select = 0;
        cin>>select;

        if(select==1){
            //���ձ������
            int id;
            cout<<"���������ְ�����:"<<endl;
            cin>>id;

            int ret = IsExist(id);
            if (ret != -1){
                //�ҵ�ְ��
                cout<<"���ҳɹ�����ְ����Ϣ���£�"<<endl;
                this->m_EmpArray[ret]->showInfo();
            }else{
                cout<<"����ʧ�ܣ����޴���"<<endl;
            }
        }else if(select==2){
            //������������
            cout<<"������ְ��������"<<endl;
            string name;
            cin>>name;

            //�����Ƿ�鵽�ı���
            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; ++i) {
                if (this->m_EmpArray[i]->m_Name == name){
                    cout<<"���ҳɹ���ְ�����Ϊ "
                    <<this->m_EmpArray[i]->m_Id
                    <<"��ְ����Ϣ���£�"<<endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if(!flag){
                cout<<"����ʧ�ܣ����޴���"<<endl;
            }
        }else{
            cout<<"����ѡ������"<<endl;
        }
    }
    system("pause");
    system("cls");

}


void workerManager::Sort_Emp(){
    if (this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
        system("pause");
        system("cls");
    }else {
        cout<<"��ѡ������ʽ��"<<endl;
        cout<<"1����ְ���Ž�������"<<endl;
        cout<<"2����ְ���Ž��н���"<<endl;

        int select = 0;
        cin>>select;

        for (int i = 0; i < this->m_EmpNum; ++i) {
            int MinOrMax = i;

            for (int j = i+1; j <this->m_EmpNum ; ++j) {
                if (select==1){//����
                    if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id){
                        MinOrMax = j;
                    }
            } else{//����
                    if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id){
                        MinOrMax = j;
                    }
                }

            }
            if(i!=MinOrMax){
                worker* tmep = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
                this->m_EmpArray[MinOrMax] = tmep;
            }
        }
    }
    cout<<"����ɹ��������Ľ��Ϊ��"<<endl;
    this->save();//����������浽�ļ���
    this->show_Emp();
}


void workerManager::Clean_File(){
    cout<<"ȷ����գ�"<<endl;
    cout<<"1��ȷ��"<<endl;
    cout<<"2������"<<endl;

    int select = 0;
    cin>>select;

    if (select == 1){
        //����ļ�
        ofstream ofs(FILENAME,ios::trunc);//ɾ���ļ������´���
        ofs.close();

        if (this->m_EmpArray){
            //ɾ��������ÿ��ְ������
            for (int i = 0; i < this->m_EmpNum; ++i) {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = nullptr;
            }

            //ɾ����������ָ��
            delete [] m_EmpArray ;
            this->m_EmpArray = nullptr;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }

        cout<<"��ճɹ�"<<endl;
    }
    system("pause");
    system("cls");
}