//
// Created by Butter on 2021/1/6.
//
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"


workerManager::workerManager() {
    //1文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //2文件存在数据为空
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //文件为空
        cout<<"文件为空"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //3文件存在不为空
    int num = this->get_EmpNum();
//    cout<<"职工人数为: "<<num<<endl;
    this->m_EmpNum = num;

    //开辟空间
    this->m_EmpArray = new worker*[this->m_EmpNum];
    //将文件中的数据，存到数组中
    this->init_Emp();
    this->m_FileIsEmpty = false;

//    for (int i = 0;i< this->m_EmpNum;i++){
//        cout<<"职工编号："<<this->m_EmpArray[i]->m_Id
//        <<"姓名："<<this->m_EmpArray[i]->m_Name
//        <<"部门编号："<<this->m_EmpArray[i]->m_DeptId<<endl;
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
    cout<<"欢迎使用职工管理系统"<<endl;
    cout<<"0.退出管理程序"<<endl;
    cout<<"1.增加员工信息"<<endl;
    cout<<"2.显示职工信息"<<endl;
    cout<<"3.删除离职职工"<<endl;
    cout<<"4.修改职工信息"<<endl;
    cout<<"5.查找职工信息"<<endl;
    cout<<"6.按照编号排序"<<endl;
    cout<<"7.清空所有文档"<<endl;
    cout<<endl;

}


void workerManager::ExitSystem() {
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}


void workerManager::Add_Emp() {
    cout<<"请输入添加职工数量："<<endl;
    int addNum = 0;//保存用户的输入数量
    cin>>addNum;

    if(addNum>0){
        //添加
        //计算添加新空间大小
        int newSize = this->m_EmpNum + addNum;//新空间大小

        //开辟新空间
        worker** newSpace = new worker*[newSize];

        //将原来空间下数据，拷贝到新空间下
        if(this->m_EmpArray!= nullptr){
            for (int i = 0; i < this->m_EmpNum ; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //添加新数据
        for (int i = 0;i<addNum;i++){
            int id;//职工编号
            string name;//职工姓名
            int dSelect;//部门选择

            cout<<"请输入第"<<i+1<<"个新职工编号："<<endl;
            cin>>id;

            cout<<"请输入第"<<i+1<<"个新职工姓名："<<endl;
            cin>>name;

            cout<<"请选择该职工岗位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
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

            //将创建职工指针，保存到数组中
            newSpace[this->m_EmpNum+i] = worker;
        }

        //释放原有空间
        delete[] this->m_EmpArray;

        //更改新空间指向
        this->m_EmpArray = newSpace;

        //更新新的职工人数
        this->m_EmpNum = newSize;


        //更新职工不为空
        this->m_FileIsEmpty = false;
        //成功添加后保存到文件中

        //提示
        cout<<"添加成功"<<endl;

        //保存数据到文件中
        this->save();

    } else{
        cout<<"输入有误"<<endl;
    }

    //按任意键后回，清屏回到上级目录
    system("pause");
    system("cls");
}

void workerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//写文件

    //将每个人的数据写入到文件中
    for(int i = 0;i<this->m_EmpNum;i++){
        ofs<< this->m_EmpArray[i]->m_Id<<" "
        <<this->m_EmpArray[i]->m_Name<<" "
        <<this->m_EmpArray[i]->m_DeptId<<endl;
    }

    //关闭文件

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

    //关闭文件
    ifs.close();
}


void workerManager::show_Emp(){
    //判断文件是否为空
    if (this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
    }else{
        for (int i=0;i<m_EmpNum;i++){
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}


//删除职工
void workerManager::Del_Emp(){
    if (this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
    } else{
        cout<<"请输入要删除职工编号："<<endl;
        int id = 0;
        cin>>id;

        int index = this->IsExist(id);
        if (index !=-1){//说明职工存在
            for (int i = index ; i <this->m_EmpNum-1 ; i++) {
                //数据前移
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            //数据同步更新到文件中
            this->save();
            cout<<"删除成功"<<endl;
        }else{
            cout<<"删除失败，未找到该职工"<<endl;
        }
    }
    system("pause");
    system("cls");
}

//判断职工是否存在,如果存在返回职工所在数组位置，不存在返回-1
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
        cout<<"文件不存在或记录为空"<<endl;
    }else{
        cout<<"请输入修改职工编号："<<endl;
        int id;
        cin>>id;

        int ret = this->IsExist(id);
        if(ret != -1){
            //查找编号的职工
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newname = "";
            int dSelect = 0;

            cout<<"查到："<<id<<"号职工，请输入新职工号："<<endl;
            cin>>newId;

            cout<<"请输入新的姓名"<<endl;
            cin>>newname;

            cout<<"请输入岗位:"<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;

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

            cout<<"修改成功"<<endl;

            this->save();
        }else{
            cout<<"修改失败，查无此人"<<endl;
        }

    }
    system("pause");
    system("cls");

}


void workerManager::Find_Emp(){
    if (this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
    }else {
        cout<<"请输入查找方式："<<endl;
        cout<<"1、按照职工编号查找"<<endl;
        cout<<"2、按照职工姓名查找"<<endl;

        int select = 0;
        cin>>select;

        if(select==1){
            //按照编号来查
            int id;
            cout<<"请输入查找职工编号:"<<endl;
            cin>>id;

            int ret = IsExist(id);
            if (ret != -1){
                //找到职工
                cout<<"查找成功！该职工信息如下："<<endl;
                this->m_EmpArray[ret]->showInfo();
            }else{
                cout<<"查找失败，查无此人"<<endl;
            }
        }else if(select==2){
            //按照姓名来查
            cout<<"请输入职工姓名："<<endl;
            string name;
            cin>>name;

            //加入是否查到的标致
            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; ++i) {
                if (this->m_EmpArray[i]->m_Name == name){
                    cout<<"查找成功，职工编号为 "
                    <<this->m_EmpArray[i]->m_Id
                    <<"号职工信息如下："<<endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if(!flag){
                cout<<"查找失败，查无此人"<<endl;
            }
        }else{
            cout<<"输入选项有误！"<<endl;
        }
    }
    system("pause");
    system("cls");

}


void workerManager::Sort_Emp(){
    if (this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
        system("pause");
        system("cls");
    }else {
        cout<<"请选择排序方式："<<endl;
        cout<<"1、按职工号进行升序"<<endl;
        cout<<"2、按职工号进行降序"<<endl;

        int select = 0;
        cin>>select;

        for (int i = 0; i < this->m_EmpNum; ++i) {
            int MinOrMax = i;

            for (int j = i+1; j <this->m_EmpNum ; ++j) {
                if (select==1){//升序
                    if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id){
                        MinOrMax = j;
                    }
            } else{//降序
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
    cout<<"排序成功！排序后的结果为："<<endl;
    this->save();//排序后结果保存到文件中
    this->show_Emp();
}


void workerManager::Clean_File(){
    cout<<"确认清空："<<endl;
    cout<<"1、确认"<<endl;
    cout<<"2、返回"<<endl;

    int select = 0;
    cin>>select;

    if (select == 1){
        //清空文件
        ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
        ofs.close();

        if (this->m_EmpArray){
            //删除堆区的每个职工对象
            for (int i = 0; i < this->m_EmpNum; ++i) {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = nullptr;
            }

            //删除堆区数组指针
            delete [] m_EmpArray ;
            this->m_EmpArray = nullptr;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }

        cout<<"清空成功"<<endl;
    }
    system("pause");
    system("cls");
}