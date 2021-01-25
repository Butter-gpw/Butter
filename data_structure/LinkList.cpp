//
// Created by Butter on 2020/8/23.
//

#include <iostream>
using namespace std;

class Node{//单链表节点声明
public:
    Node(){};
    Node(int x):data(x), next(nullptr){}
    int data;
    Node *next;
};

class LinkList{
public:
    LinkList();
    ~LinkList();
    int CreateLinkList(int n);//初始化链表
    int ByeLinkedList();//删除链表所有内容，释放堆区内存
    int TravelLinkList();//遍历链表
    Node* GetNode(int n);//获取链表第n个节点
    int GetData(int n);//获取链表第n个节点的值
    int InsertLinkList(Node* data,int n);//在第n个位置插入节点data
    int RemoveNode(int n);//移除链表第n个节点
    int Getlen();//获取链表长度
    bool IsEmpty();//判断链表是否为空

    Node *head;
    Node *tail;
    int size;
};

LinkList::LinkList() {
    head = new Node(0);
    tail = head;
    size = 0;
}


LinkList::~LinkList() {
    delete head;
    head = nullptr;
    tail = nullptr;
}


int LinkList::CreateLinkList(int n) {
    if(n<0){
        printf("error\n");
        return -1;
    }

    Node *ptemp = nullptr;
    Node *pnew = nullptr;

    this->size = n;
    ptemp = this->head;
    for(int i=0;i<n;i++){
        pnew = new Node(0);
        cout<<"请输入第"<<i+1<<"个节点值"<<endl;
        cin>>pnew->data;
        ptemp->next = pnew;
        ptemp = pnew;
        this->tail = pnew;
    }
    cout<<"创建完成"<<endl;
    return 0;
}


int LinkList::ByeLinkedList() {
    Node* temp;
    if(this->head == nullptr){
        cout<<"链表原本就为空"<<endl;
        return -1;
    }
    while (this->head){
        temp = head->next;
        delete head;
        head = temp;
    }
    this->tail = nullptr;
    cout<<"链表销毁完成"<<endl;
    return 0;
}


int LinkList::TravelLinkList() {
    Node* ptemp = this->head;
    if (this->head == nullptr){
        cout<<"链表为空"<<endl;
        return -1;
    }

    while(ptemp){
        cout<<ptemp->data<<"->";
        ptemp = ptemp->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}


Node *LinkList::GetNode(int n) {
    int i = n;
    if (this->head == nullptr){
        cout<<"链表为空"<<endl;
        return nullptr;
    }
    Node* ptemp = head;
    while(i>0 && ptemp){
        ptemp = ptemp->next;
        i--;
    }

    if (i!=0 && !ptemp){
        cout<<"请求节点数量过大"<<endl;
    }
    return ptemp;
}


int LinkList::GetData(int n) {
    Node* ptemp = this->GetNode(n);
    if(!ptemp) return -1;
    return ptemp->data;
}


int LinkList::InsertLinkList(Node *data, int n) {
    if (this->head == nullptr){
        cout<<"链表为空"<<endl;
        return -1;
    }

    if (!data){
        cout<<"插入节点为空"<<endl;
        return -1;
    }

    Node* ptemp;
    Node* pnew = new Node;
    pnew->data = data->data;

    //头插
    if(n<2){
        pnew->next = this->head->next;
        this->head->next = pnew;
        this->size++;
        if (this->size == 1){
            this->tail = head->next;
        }
    }
    //尾插
    else if(n>=this->size){
        this->tail->next = pnew;
        this->tail = pnew;
        this->size++;
    }
    else{//中间插
        ptemp = this->GetNode(n-1);
        pnew->next = ptemp->next;
        ptemp->next = pnew;
        this->size++;
    }
    return 0;
}


int LinkList::RemoveNode(int n) {
    if (this->head == nullptr){
        cout<<"链表为空"<<endl;
        return -1;
    }

    if(n>this->size){
        cout<<"输入值超出链表长度"<<endl;
        return -1;
    }

    Node* ptemp;
    if (n<2){//头删除
        ptemp = this->head->next;
        this->head = ptemp->next;
        delete ptemp;
        this->size --;
        if(this->size ==0){
            this->tail = nullptr;}
    }
    else{
        ptemp = GetNode(n-1);
        Node* pcur = ptemp->next;
        if (n==this->size) {
            this->tail = ptemp;
            ptemp->next = nullptr;
            delete pcur;
            return 0;
        }

        ptemp->next = pcur->next;
        delete pcur;
        pcur = nullptr;
    }
    return 0;
}


int LinkList::Getlen() {
    int length = this->size;
    return length;
}


bool LinkList::IsEmpty() {
    return !this->head;
}