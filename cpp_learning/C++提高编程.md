# C++提高编程

- 本阶段主要针对C++泛型编程和STL技术做详细讲解，探讨C++更深层的使用





## 1 模版

### 1.1 模版的概念



模版就是建立**通用的模具**，大大提高**复用性**





模板的特点：

- 模板不可以直接使用，它只是一个框架
- 模板的通用并不是万能的



### 1.2 函数模板

- C++另一种编程思想称为 泛型变成，主要利用的技术就是模板
- C++提供两种模板机制：**函数模板**和**类模板**



#### 1.2.1 函数模板语法

函数模板作用：

建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表。



**语法：**

```c++
template<typename T>
函数声明或定义
```



**解释：**

template --- 声明创建模板

typename --- 表明其后面的符号是一种数据类型，可以用class代替

T --- 通用的数据类型，名称可以替换，通常为大写字母



```c++
template <typename T>//声明一个模板,T是一个通用数据类型
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}


void test01(){
    //两种方式
    //1、自动类型推导
    int a = 10;
    int b = 20;
    mySwap(a,b);
    //2、显示指定类型
    mySwap<int>(a,b);
}
```



- 模板的目的是为了提高复用性，将类型参数化





#### 1.2.2 函数模板注意事项

注意事项：

- 自动类型推导，必须推导出一致的数据类型T，才可以使用
- 模板必须要确定出T的数据类型，才可以使用





#### 1.2.3 函数模板案例

案例描述：

- 利用函数模板封装一个排序的函数，可以对**不同数据类型**进行排序
- 排序规则从大到小，排序算法为选择排序
- 分别利用**char数组**和**int数组**进行测试



```c++
template <typename T>//声明一个模板,T是一个通用数据类型
void myswap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void mySort(T arr[],int len){
    for (int i = 0; i < len; ++i) {
        int  max = i;
        for (int j = i+1; j <len ; ++j) {
            max = j;
        }
        if (max != i){
            myswap(arr[max],arr[i]);
        }
    }
}
```





#### 1.2.4 普通函数与函数模板的区别



普通函数与函数模板区别：

- 普通函数调用时可以发生自动类型转换（隐式类型转换）
- 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
- 如果利用指定类型方式，可以发生隐式类型转换





#### 1.2.5 普通函数与函数模板的调用规则



1. 如果函数模板和普通函数都可以实现，优先调用普通函数
2. 可以通过空模板参数列表来强制调用函数模板
3. 函数模板也可以发生重载
4. 如果函数模板可以产生更好的匹配，优先调用函数模板

总结：既然提供了函数模板，最好不要使用普通函数，容易产生二义性





#### 1.2.6 模板的局限性



```c++
class person{
public:
    person(int age,string name){
        this->m_age = age;
        this->m_name = name;
    }
    int m_age;
    string m_name;
};


template <typename T>
bool myCompare(T& a,T&b){
    return a==b;
}

template<> bool myCompare(person &p1,person &p2 ){
    if (p1.m_age == p2.m_age && p1.m_name==p2.m_name){
        return true;
    }else{
        return false;
    }
}
```



总结：

- 利用具体化的模板，可以解决自定义类型的通用化
- 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板





### 1.3 类模板

#### 1.3.1 类模板语法



类模板作用：

- 建立一个通用类，类中的成员 数据类型可以不具体指定，用一个**虚拟的类型**来代表



语法：

```c++
template<typename T>
类
```

**解释：**

template --- 声明创建模板

typename --- 表明其后面的符号是一种数据类型，可以用class代替

T --- 通用的数据类型，名称可以替换，通常为大写字母



```c++
template<class NameType,class AgeType>
class person{
public:
    person(NameType name,AgeType age){
        this->m_age = age;
        this->m_name = name;
    }
    AgeType m_age;
    NameType m_name;
};

void test01() {
    person<string,int> p1("盖瑞",99);
}
```





#### 1.3.2 类模板与函数模板区别



类模板与函数模板区别主要有两点：

1. 类模板没有自动类型推导的使用方式
2. 类模板在参数列表中可以有默认参数





#### 1.3.3 类模板中成员函数创建时机



类模板中成员函数和普通类中成员函数创建时机是有区别的：

- 普通类中的成员函数一开始就可以创建
- 类模板中的成员函数在调用时才创建



#### 1.3.4 类模板对象做函数参数

学习目标：

- 类模板实例化出的对象，向函数传参的方式



一共有三种传入方式：

1. 指定传入的类型  --- 直接显示对象的数据类型
2. 参数模板化          --- 将对象中的参数变为模板进行传递
3. 整个类模板化      --- 将这个对象类型 模板化进行传递



总结：

- 使用比较广泛的是第一种

#### 1.3.5 类模板与继承



当类模板碰到继承时，需要注意以下几点：

- 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
- 如果不指定，编译器无法给子类分配内存
- 如果想灵活指定出父类中T的类型，子类也需变为类模板





#### 1.3.6 类模板成员函数的类外实现



```c++
template<class NameType,class AgeType>
class person{
public:
    person(NameType name,AgeType age);
    void showperson();
    
    AgeType m_age;
    NameType m_name;
};

template<class NameType,class AgeType>
person<NameType,AgeType>::person(NameType name,AgeType age){
    this->m_age = age;
    this->m_name = name;
}

template<class NameType,class AgeType>
void person<NameType,AgeType>::showperson(){
    
}
```





#### 1.3.7 类模板分文件编写



问题

- 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决：

- 解决方式1：直接包含.cpp源文件
- 解决方式2：将声明和实现**写到同一个文件中**，并更改后缀名为.hpp，hpp是约定名称，并不是强制





#### 1.3.8 类模板与友元



全局函数类内实现 - 直接在类内声明友元即可

全局函数类外实现 - 需要提前让编译器知道全局函数的存在 













## 2 STL初识

### 2.1 STL诞生



- 长久以来，软件界一直希望建立一种可重复利用的东西
- C++的**面向对象**和**泛型编程**思想，目的就是**复用性的提升**
- 大多数情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
- 为了建立数据结构和算法的一套标准，诞生了**STL**



### 2.2 STL基本概念

- STL(Standard Template Libeary,标准模板库)
- STL从广义上分为：**容器(container)算法(algorithm)迭代器(iterator)**
- **容器**和**算法****之间通过迭代器进行无缝连接**
- STL几乎所有的代码都采用了模板类或模板函数





### 2.3 STL六大组件

STL大体分为六大组件，分别是：**容器，算法，迭代器，仿函数，适配器（配接器），空间配置器**



1. 容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据
2. 算法：各种常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂。
4. 仿函数：行为类似函数，可作为算法的某种策略。
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
6. 空间适配器：负责空间的配置与管理。



### 2.4 STL中容器、算法、迭代器

**容器：**置物之所也

STL**容器**就是将运用**最广泛的一些数据结构**实现出来

常用的数据结构：数组，链表，树，栈，队列，集合，哈希表等

这些容器分为**序列式容器**和**关联式容器**两种：

​		**序列式容器**：强调值的排序，序列式容器中的每个元素均有固定的位置。

​		**关联式容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系



**算法：**问题之解法也

有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)

算法分为：**质变算法**和**非质变算法**。

质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等

非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找，计数，遍历，寻找极值等等



**迭代器：**容器和算法之间粘合剂

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无须暴露该容器的内部表示方式。

每个容器都有自己专属的迭代器

迭代器使用非常类似于指针，初雪阶段我们可以先理解迭代器为指针



迭代器种类：

| 种类           | 功能                                                     | 支持运算                                |
| -------------- | -------------------------------------------------------- | --------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                         | 只读，支持++、==、！=                   |
| 输出迭代器     | 对数据的只写访问                                         | 只写，支持++                            |
| 前向迭代器     | 读写操作，并能向前推进迭代器                             | 读写，支持++、==、！=                   |
| 双向迭代器     | 读写操作，并能向前和向后操作                             | 读写，支持++、--                        |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>=、> |

常用的容器中迭代器种类为双向迭代器和随机访问迭代器	









### 2.5容器算法迭代器初识



#### 2.5.1 vector存放内置数据类型

容器：`vector`

算法：`for_each`

迭代器：`vector<int>::iterator`





```c++
#include <vector>
#include <algorithm>

void myPrint(int val){
    cout<<val<<endl;
}

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();//起始迭代器，指向容器中最后一个元素的下一个位置

    while (itBegin != itEnd){
        cout<< *itBegin <<endl;
        itBegin ++;
    }

    for(vector<int>::iterator it = v.begin();it !=v.end();it++){
        cout<<*it<<endl;
    }

    for_each(v.begin(),v.end(),myPrint);
}
```





#### 2.5.2 Vector存放自定义数据类型



```c++
#include <vector>
#include <algorithm>

class Person{
public:
    Person(string name,int age){
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};


void test01(){
    vector<Person>v;
    Person p1("a",10);
    Person p2("b",20);
    Person p3("c",30);
    Person p4("d",40);
    Person p5("e",50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for(vector<Person>::iterator it = v.begin(); it!=v.end();it++){
        cout<<"姓名："<< it->m_name <<"年龄："<<it->m_age<<endl;
    }
}
```





#### 2.5.3 Vector容器嵌套容器





```c++
vector<vector<int>v;
```





## 3 STL- 常用容器

### 3.1 string容器





#### 3.1.1 string基本概念

本质：

- string是C++风格的字符串，而string本质上是一个类



string和char* 区别：

- char* 是一个指针
- string是一个类，类内部封装了char*，管理这个字符串，是一个char *型的容器。



特点：

string类内部封装了很多成员方法

例如：查找find，拷贝copy，删除delet， 替换replace，插入insert



string管理char * 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责



#### 3.1.2 string构造函数

构造函数圆形：

- `string();`                             //创建一个空的字符串 例如：string str；

  `string(const char* s);`     //使用字符串s初始化

- `string(const string& s);` //使用一个string对象初始化另一个string对象

- `string(int n,char c);`       //使用n个字符c初始化



```c++
#include <string>

void test01(){
    string s1;

    const char* str ="hello world";
    string s2(str);

    cout<<"s2="<<s2<<endl;

    string s3(s2);

    cout<<"s3="<<s3<<endl;

    string s4(10,'a');

    cout<<"s4="<<s4<<endl;

}
```





#### 3.1.3 string赋值操作



- `string& operator = (const char*s);`        //char * 类型字符串复制给当前的字符串
- `string& operator = (const string &s);`        //把字符串s赋给当前的字符串
- `string& operator = (char c);`                     //字符赋值给当前的字符串
- `string& assign(const char *s);`              //把字符串s赋给当前的字符串
- `string& assign(const char *s, int n);`              //把字符串s的前n个字符赋给当前的字符串
- `string& assign(const string &s);`              //把字符串s赋给当前的字符串
- `string& assign(int n, char c);`              //用n个字符赋c给当前字符串



```c++
void test01(){
    string str1;
    str1 = "hello world";

    string str2;
    str2 = str1;

    string str3;
    str3 = 'a';

    string str4;
    str4.assign("hello C++");

    string str5;
    str5.assign("hello C++",5);

    string str6;
    str6.assign(str5);

    string str7;
    str7.assign(10,'w');
}
```





#### 3.1.4 string字符串拼接



**函数原型：**

- `string& operator += (const char* str);`        //重载+=操作符
- `string& operator += (const char c);`        //重载+=操作符
- `string& operator += (const string& str);`                     //重载+=操作符
- `string& append(const char *s);`              //把字符串s连接到当前字符串结尾
- `string& append(const char *s, int n);`              //把字符串s的前n个字符连接到当前字符串结尾
- `string& append(const string &s);`              //同operator += (const string& str);   
- `string& append(const string &s,int pos,int n);`              //字符串s中从pos开始n个字符连接到字符串结尾



```c++
#include <string>

void test01(){
    string str1= "我";
    str1 += "爱玩游戏";
    str1 += ':';


    string str2 = "DOTA2";
    str1 += str2;


    string str3;
    str3 = 'I';
    str3.append("Love");
    str3.append("game abced",4);
    str3.append(str2);
    str3.append(str2,2,3);
    
    cout<<str3<<endl;
}
```





#### 3.1.5 string查找和替换

**功能描述：**

- 查找：查找指定字符串是否存在
- 替换：在指定的位置替换字符串



**函数原型：**

- `int find(const string& str, int pos = 0) const;`  //查找str第一次出现位置，从pos开始查找
- `int find(const char* s,int pos = 0) const;`  //查找s第一次出现位置，从pos开始找
- `int find(const char* s,int pos, int n) const;`  //从pos位置查找s的前n个字符第一次出现位置
- `int find(const char c, int pos = 0) const;`  //查找字符c第一次出现位置
- `int rfind(const string& str,int pos = npos) const;`  //查找str最后一次出现位置，从pos开始查找
- `int rfind(const char* s,int pos,int pos = npos) const;`  //查找s最后一次出现位置，从pos开始查找
- `int rfind(const char* s,int pos,int n) const;`  //从pos查找s的前n个字符最后一次位置
- `int rfind(const char c,int pos = 0) const;`  //查找字符c最后一次出现位置
- `string& replace(int pos,int n,const string& str);`  //替换从pos开始n个字符为字符串str
- `string& replace(int pos ,int n, const char* s);`  //替换从pos开始的n个字符串为字符串s





#### 3.1.6 string字符串比较

比较方式：

- 字符串比较是按字符的ASCII码进行对比

 =返回 0

 \>返回 1

 \< 返回 -1



函数原型：

- `int compare(const string &s) const;`    //与字符串s比较
- `int compare(const char *s) const;`    //与字符串s比较





#### 3.1.7 string字符存取



- char& operator\[](int n);  //通过[]方式取字符
- char& at(int n);   //通过at方法获取字符





#### 3.1.8 string插入和删除



- `string& insert(int pos, const char* s);`     //插入字符串
- `string& insert(int pos, const string& str);`  //插入字符串
- `string& insert(int pos,int n,char c);`    //在指定位置插入n个字符c
- `string& erase(int pos, int n  = npos);`  //删除从pos开始的n个字符





#### 3.1.9 string子串



string substr(int pos = 0,int n = npos) const;     //返回由pos开始的n个字符组成的字符串







### 3.2 vector容器



#### 3.2.1 vector基本概念

**功能：**

- vector数据结构和**数组非常相似**，也称为**单端数组**



**vector与普通数组区别：**

- 不同之处在于数组是静态空间，而vector可以**动态扩展**



**动态扩展：**

- 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间





- vector容器的迭代器是支持随机访问的迭代器



#### 3.2.2 vector构造函数

- `vector<T> v;`     //采用模版实现类实现，默认构造函数
- `vector(v.begin(),v.end());`   //将v[beg,end)区间中的元素拷贝给本身
- `vector(n,elem);`     //构造函数将n个elem拷贝给本身
- `vector(const vector &vec);`   //拷贝构造函数。





#### 3.2.3 vector赋值操作

**函数原型：**

- `vector& operator=(const vector &vec);`  //重载等号操作符
- `assign(beg,end);`     //将[beg,end]区间中的数据拷贝赋值给本身。
- `assign(n,elem);`    //将n个elem拷贝赋值给本身。





#### 3.2.4 vector容量和大小



**函数原型：**

- `empty();`      //判断容器是否为空
- `capacity();`   //容器的容量
- `size();`           //返回容器中元素的个数
- `resize(int num);`        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。  如果容器变短，则末尾超出容器长度的元素被删除
- `resize(int num, elem);`    //重新指定容器的长度为num，若容器变长，则以elem填充新位置。  如果容器变短，则末尾超出容器长度的元素被删除



#### 3.2.5 vector插入和删除



**函数原型：**

- `push_back(ele);`                            //尾部插入元素ele
- `pop_back();`                                   //删除最后一个元素
- `insert(const_iterator pos, ele);`    //迭代器指向位置pos插入元素ele
- `insert(const_iterator pos,int count,ele);`  //迭代器指向位置pos插入count个元素ele
- `erase(const_itersator pos);`            //删除迭代器指向的元素
- `erase(const_itersator start,const_iterator end);`   //删除迭代器从start到end之间的元素
- `clear();`                                                //删除容器中所有元素





#### 3.2.6 vector数据存取



**函数原型：**

- `at(int idx);`   //返回索引idx所指的数据
- `operator[];`  //返回索引idx所指的数据
- `front();`         //返回容器中第一个数据元素
- `back();`         //返回容器中最后一个数据元素





#### 3.2.7 vector互换容器



- `swap(vec);`      //将vec与本身的元素互换



巧用swap可收缩空间





#### 3.2.8 vector预留空间

**功能描述：**

- 减少vector在动态扩展容量时的扩展次数



**函数原型：**

- `reserve(int len);`  //容器预留len个元素长度，预留位置不初始化，元素不可访问。





### 3.3 deque容器

#### 3.3.1 deque容器基本概念



功能：

双端数组，可以对头端进行插入删除操作



deque与vector区别：

- vector对于头部的插入删除效率低，数据量大，效率低
- deque相对而言，对头部的插入删除速度会比vector快
- vector访问元素时的速度会比deque快，这和两者内部实现有关





deque内部工作原理：

deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间



- deque容器的迭代器也是支持随机访问的





#### 3.3.2 deque构造函数

功能描述：

- deque容器构造



**函数原型：**

- `deque<T> deT;`           //默认构造形式
- `deque(beg,end);`          //构造函数将[beg,end]区间中的元素拷贝给本身。
- `deque(n,elem);`            //构造函数将n个elem拷贝给本身。
- `deque(const deque &deq);`  //拷贝构造函数



#### 3.3.3 deque赋值操作



**函数原型：**

- `deque& operator=(const deque &deq);` //重载等号操作符
- `assign(beg,end);`                              //将[beg,end)区间中的数据拷贝赋值给本身。
- `assign(n,elem);`                                //将n个elem拷贝赋值给本身。







#### 3.3.4 deque大小操作

- `empty();`      //判断容器是否为空
- `size();`           //返回容器中元素的个数
- `resize(int num);`        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。  如果容器变短，则末尾超出容器长度的元素被删除
- `resize(int num, elem);`    //重新指定容器的长度为num，若容器变长，则以elem填充新位置。  如果容器变短，则末尾超出容器长度的元素被删除





#### 3.3.5 deque插入和删除



**函数原型：**

两端插入操作：

- `push_back(elem);`     //在容器尾部添加一个数据
- `push_front(elem);`    //在容器头部插入一个数据
- `pop_back();`               //删除容器最后一个数据
- `pop_front();`              //删除容器第一个数据

指定位置操作：

- `insert(pos,elem);`    //在pos位置插入一个elem元素的拷贝，返回新数据的位置
- `insert(pos,n,elem);` //在pos位置插入n个elem数据，无返回值
- `insert(pos,beg,end);`  //在pos位置插入[beg,end)区间的数据，无返回值。
- `clear();`                        //清空容器的所有数据
- `erase(beg,end);`        //删除[beg,end)区间的数据，返回下一个数据的位置。
- `erase(pos);`                //删除pos位置的数据，返回下一个数据的位置。





#### 3.3.6 deque数据存取

**函数原型：**

- `at(int idx);`       //返回索引idx所指的数据
- `operator[];`     //返回索引idx所指的数据
- `front();`             //返回容器中第一个数据元素
- `back();`             //返回容器中最后一个数据元素





#### 3.3.7 deque排序

- `sort(iterator beg, iterator end)；`  //对beg和end区间内元素进行排序







### 3.5 stack容器

#### 3.5.1 stack基本概念

概念：stack是一种先进后出的数据结构，它只有一个出口

栈中只有顶端元素才可以被外界使用，因此栈不允许有遍历行为

栈中进入数据称为 --- 入栈 `push`

栈中弹出数据称为 --- 出栈 `pop`



#### 3.5.2 stcak常用接口



构造函数：

- `stack<T> stk;`        //stack采用模板类实现，stack对象的默然构造形式
- `stack(const ctack &stk);`     //拷贝构造函数

赋值操作：

- `stack& operator=(const stack &stk);`   //重载等号操作符

数据存取：

- `push(elem);`   //向栈顶添加元素
- `pop();`        //从栈顶移除第一个元素
- `top();`         //返回栈顶元素

大小操作：

- `empty();`    //判断堆栈是否为空
- `size();`         //返回栈的大小



### 3.6 queue容器

#### 3.6.1 queue基本概念

**概念：**Queue是一种先进先出的数据结构，它有两个出口

队列容器允许从一端新增元素，从另一端移除元素

队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为

队列中进数据称为 --- 入队 `push`

队列中出数据称为 --- 出队 `pop`



#### 3.6.2 queue常用接口

构造函数：

- `queue<T> que;`        //queue采用模板类实现，queue对象的默然构造形式
- `queue(const queue &quek);`     //拷贝构造函数

赋值操作：

- `queue& operator=(const queue &que);`   //重载等号操作符

数据存取：

- `push(elem);`   //往队尾添加元素
- `pop();`        //从队头移除第一个元素
- `back();`      //返回最后一个元素
- `front();`   //返回第一个元素

大小操作：

- `empty();`    //判断堆栈是否为空
- `size();`         //返回栈的大小





### 3.7 list容器

#### 3.7.7 list基本概念

功能：将数据进行链式存储

链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的



链表的组成：链表由一系列结点组成



结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域



STL中的链表是一个双向循环链表



由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器



list的有点：

- 采用动态存储分配，不会造成内存浪费和溢出
- 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list的缺点：

- 链表灵活，但是空间（指针域）和时间（遍历）额外耗费较大

List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的实现，这在vector是不成立的。



#### 3.7.2 list构造函数



**函数原型：**

- `list<T> lst;`                                //list采用模板类实现，对象的默认构造形式；
- `list(beg,end);`                           //构造函数将[beg,end)区间中的元素拷贝给本身
- `list(n,elem);`                             //构造函数将n个elem拷贝给本身
- `list(const list &lst);`          //拷贝构造函数



#### 3.7.3 list赋值和交换

- `assign(beg,end);`                             //将[beg,end)区间中的数据拷贝赋值给本身。
- `assign(n,elem);`                               //将n个elem拷贝赋值给本身。
- `list& operator=(const list &list);`   //重载等号操作符
- `swap(lst);`                                         //将lst与本身的元素互换





#### 3.7.4 list大小操作

**函数原型：**

- size();       //返回容器中元素的个数
- empty();     //判断容器是否为空
- `resize(int num);`        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。  如果容器变短，则末尾超出容器长度的元素被删除
- `resize(int num, elem);`    //重新指定容器的长度为num，若容器变长，则以elem填充新位置。  如果容器变短，则末尾超出容器长度的元素被删除





#### 3.7.5 list插入和删除

**函数原型：**

- `push_back(elem);`//在容器尾部加入一个元素。
- `pop_back();`//删除容器中最后一个元素。
- `push_front(elem);`//在容器开头插入一个元素。
- `pop_front();`//从容器开头移除第一个元素。
- `insert(pos,elem);`//在pos位置插elem元素的拷贝，返回新数据的位置。
- `insert(pos,n,elem);` //在pos位置插入n个elem数据，无返回值。
- `insert(pos,beg,end);`//在pos位置插入[beg,end)区间的数据，无返回值。
- `clear();`//移除容器的所有数据。
- `erase(beg,end);`//删除[beg,end)区间的数据，返回下一个数据的位置。
- `erase(pos);`//删除pos位置的数据，返回下一个数据的位置。
- `remove(elem);`//删除容器中所有与elem值匹配的元素。





#### 3.7.6 list数据存取

- `front();`      //返回第一个元素。
- `back();`      //返回最后一个元素。





#### 3.7.7 list反转和排序



- `reverse();`     //反转链表
- `sort();`           //链表排序



#### 3.7.8 排序案例

案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序



```c++
#include <iostream>
using namespace std;
#include <string>
#include <list>


class Person{
public:
    Person(string name,int age,int height){
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }


    string m_Name;//名字
    int m_Age;//年龄
    int m_Height;//身高
};



//指定排序规则
bool comparePerson(Person &p1,Person &p2){
    if(p1.m_Age == p2.m_Age){
        return p1.m_Height >p2.m_Height;
    }else{
        return p1.m_Age < p2.m_Age;
    }
}



void test01(){
    list<Person>L;//创建容器

    Person p1("刘备",35,175);
    Person p2("曹操",45,180);
    Person p3("孙权",40,170);
    Person p4("赵云",25,190);
    Person p5("张飞",35,160);
    Person p6("关羽",35,200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);


     for(list<Person>::iterator it = L.begin(); it!= L.end();it++){
         cout<<"姓名："<<it->m_Name<<" 年龄："<<it->m_Age<<" 身高："<<it->m_Height<<endl;
     }

     //排序
     cout<<"--------------------------------"<<endl;
     cout<<"排序后："<<endl;

     L.sort(comparePerson);


    for(list<Person>::iterator it = L.begin(); it!= L.end();it++){
        cout<<"姓名："<<it->m_Name<<" 年龄："<<it->m_Age<<" 身高："<<it->m_Height<<endl;
    }
}
```





### 3.8 set/multiset容器

#### 3.8.1 set容器概念

**简介：**

- 所有元素都会在插入时自动被排序



**本质：**

- set/multiset属于关联式容器，底层结构是用二叉树实现。



**set和multiset区别：**

- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素



#### 3.8.2 set构造和赋值

构造：

- `set<T> st;`     //默认构造函数
- `set(const set &st);`   //拷贝构造函数

赋值：

- `set& operator=(const set &st)`  //重载等号操作符





#### 3.8.3 set大小和交换



**函数原型：**

- `size();`       //返回容器中元素的数目
- `empty();`    //判断容器是否为空
- `swap(st);`   //交换两个集合容器





#### 3.8.4 set插入和删除

**函数原型：**

- `insert(elem);`   //在容器中插入元素
- `clear();`              //清除所有元素
- `erase(pos);`      //删除pos迭代器所指的元素，返回下一个元素的迭代器。
- `erase(beg,end);`  //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
- `erase(elem);`     //删除容器中值为elem的元素。





#### 3.8.5 set查找和统计

功能描述：

- 对set容器进行查找数据以及统计数据

**函数原型：**

- `find(key);`             //查找key是否存在，若存在，返回该键的元素的迭代器，若不存在，返回set.end();
- `count(key);`          //统计key的元素个数





#### 3.8.6 set和multiset区别



区别：

- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据



#### 3.8.7 pair对组创建

- 成对出现的数据，利用对组可以返回两个数据



两种创建方式：

- `pair<type,type> p (value1,value2);`
- `pair<type,type> p =make_pair(value1,value2);`



#### 3.8.8 set容器排序

学习目标：

- set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：

- 利用仿函数，可以改变排序规则



### 3.9 map/multimap容器

#### 3.9.1 map基本概念

简介：

- map中所有元素都是pair
- pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
- 所有元素都会根据元素的键值自动排序

本质：

- map/multimap属于关联式容器，底层结构是用二叉树实现。

优点：

- 可以根据key值快速找到value值

map和multimap区别：

- map不允许容器中有重复key值元素
- multimap允许容器中有重复key值元素



#### 3.9.2 map构造和赋值

**功能描述：**

- 对map容器进行构造和赋值操作

**函数原型：**

**构造：**

- `map<T1,T2> mp;`      //map默认构造函数
- `map(const map &mp);`   //拷贝构造函数

**赋值：**

- `map operator=(const map &mp);`    //重载等号操作符





#### 3.9.3 map大小和交换

**函数原型：**

- size();         //返回容器中元素的数目
- empty();    //判断容器是否为空
- swap(st);   //交换两个集合容器





#### 3.9.4 map插入和删除

**函数原型：**

- `insert(elem);`      //在容器中插入元素
- `clear();`                 //清楚所有元素
- `erase(pos);`         //删除pos迭代器所指的元素，返回下一个元素的迭代器
- `erase(beg,end);` //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
- `erase(key);`          //删除容器中值为key的元素。 



```c++
void test01() {
    map<int, int> m;

    m.insert(pair<int,int>(1,10));

    m.insert(make_pair(2,20));

    m.insert(map<int,int>::value_type(3,30));

    m[4] = 40;
```





#### 3.9.5 map查找和统计

- `find(key);`      //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- `count(key);`   //统计key的元素个数





#### 3.9.6 map容器排序

- 利用仿函数，可以改变排序规则





## 4 STL - 函数对象

### 4.1 函数对象

#### 4.1.1 函数对象概念

**概念：**

- 重载**函数调用操作符**的类，其对象常称为**函数对象**
- **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**

本质：

函数对象（仿函数）是一个**类**，不是一个函数



#### 4.1.2 函数对象使用

**特点：**

- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递



### 4.2 谓词

#### 4.2.1 谓词概念



**概念：**

- 返回bool类型的仿函数称为**谓词**
- 如果operator()接受一个参数，那么叫做一元谓词
- 如果operator()接受两个参数，那么叫做二元谓词



#### 4.2.2 一元谓词



```c++
#include <vector>
#include <algorithm>

class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

void test01() {
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
    if (it == v.end()){
        cout<<"未找到"<<endl;
    }else{
        cout<<"找到了大于5的数字为"<<*it<<endl;
    }
}
```



#### 4.2.3 二元谓词



```c++
#include <vector>
#include <algorithm>

class myCompare{
public:
    bool operator()(int val1,int val2){
        return val1>val2;
    }
};

void test01() {
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(70);
    v.push_back(90);
    v.push_back(30);
    sort(v.begin(),v.end());
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }cout<<endl;
    sort(v.begin(),v.end(),myCompare());
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }cout<<endl;
}
```





### 4.3 内建函数对象

#### 4.3.1 内建函数对象意义

概念：

- STL内建了一些函数对象



分类：

- 算数仿函数
- 关系仿函数
- 逻辑仿函数

用法：

- 这些仿函数所产生的对象，用法和一般函数完全相同
- 使用内建函数对象，需要引入头文件`#include<functional>`



#### 4.3.2 算数仿函数

**功能描述：**

- 实现四则运算
- 其中negate是一元运算，其他都是二元运算

**仿函数原型：**

- `template<class T> T plus<T>`        //加法仿函数
- `template<class T> T minus<T>`      //减法仿函数
- `template<class T> T multiplies<T>`        //乘法仿函数
- `template<class T> T divides<T>`        //除法仿函数
- `template<class T> T modulus<T>`        //取模仿函数
- `template<class T> T negate<T>`        //取反仿函数





#### 4.3.3 关系仿函数

**仿函数原型：**

- `template<class T> bool equal_to<T>`     //等于
- `template<class T> bool not_equal_to<T>`     //不等于
- `template<class T> bool greater<T>`     //大于
- `template<class T> bool greater_equal<T>`     //大于等于
- `template<class T> bool less<T>`     //小于
- `template<class T> bool less_equal<T>`     //小于等于





#### 4.3.4 逻辑仿函数

**仿函数原型：**

- `template<class T> bool logical_and<T>`     //逻辑与
- `template<class T> bool logical_or<T>`     //逻辑或
- `template<class T> bool logical_not<T>`     //逻辑非







## 5 STL - 常用算法



概述：

- 算法主要是由头文件`<algorithm>` `<functional>` `<numeric>`组成。
- `<algorithm>` 是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
- `<numeric>`体积很小，只包括几个在序列上面进行简单数学运算的模板函数
- `<functional>`定义了一些模板类，用以声明函数对象



### 5.1 常用遍历算法

算法简介：

- `for_each`    //遍历容器
- `transform`  //搬运容器到另一个容器中



#### 5.1.1 for_each

**函数原型：**

- `for_each(iterator beg, iterator end,  _func);`

  //遍历算法 遍历容器元素

  //beg 开始迭代器

  //end结束迭代器

  //_func函数或着函数对象

  

```c++
#include <vector>
#include <algorithm>

void myprint(int val){
    cout<<val<<" ";
}

class print01{
public:
    void operator()(int  val){
        cout<<val<<" ";
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(),v.end(),myprint);
    cout<<endl;

    for_each(v.begin(),v.end(),print01());
    cout<<endl;
}
```







#### 5.1.2 transform

**函数原型：**

- `transform(iterator beg1, iterator end1,iterator beg2, _func);`

  //beg1 源容器开始迭代器

  //end1 源容器结束迭代器

  //beg2 目标容器开始迭代器

  //_func 函数或者函数对象





### 5.2 常用查找算法



**算法简介：**

- `find`                            //查找元素
- `find_if`                      //按条件查找元素
- `adjacent_find`              //查找相邻重复元素
- `binary_search`             //二分查找法
- `count`                            //统计元素个数
- `count_if`                        //按条件统计元素个数



#### 5.2.1 find

**函数原型：**

- `find(iterator beg,iterator end,value);`

  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

  // beg开始迭代器

  // end结束迭代器

  // value查找的元素



#### 5.2.2 find_if

函数原型：

- `find_if(iterator beg, iterator end, _Pred);`

  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

  // beg开始迭代器

  // end结束迭代器

  // _Pred函数或者谓词（返回bool类型的仿函数）





#### 5.2.3 adjacent_find

- `adjacent_find(iterator beg,iterator end);`

  //查找相邻重复元素，返回相邻元素的第一个位置的迭代器

  //beg 开始迭代器

  //end 结束迭代器



#### 5.2.4 binary_search

- `bool binary_search(iterator beg,iterator end,value);`

  //查找指定的元素，查到返回true 否则返回false

  //注意：在无序序列中不可用

  //beg 开始迭代器

  //end 结束迭代器

  //value 查找的元素





#### 5.2.5 count

- `count(iterator beg,iterator end,value);`

  //统计元素出现次数

  //beg 开始迭代器

  //end 结束迭代器

  //value 统计的元素



#### 5.2.6 count_if

- `count_if(iterator beg,iterator end,_Pred);`

//按条件统计元素出现次数

//beg 开始迭代器

//end 结束迭代器

//_Pred 谓词



### 5.3 常用排序算法

`算法简介：`

- `sort`  							//对容器内元素进行排序
- `random_shuffle`         //洗牌，指定范围内的元素随机调整次序
- `merge`                            //容器元素合并，并存储到另一容器中
- `reverse`                        //反转指定范围的元素





#### 5.3.1 sort

- sort(iterator beg,iterator end,_Pred);





#### 5.3.2 random_shuffle

- `random_shuffle(iterator beg,iterator end);`

  //指定范围内的元素随机调整次序





#### 5.3.3 merge

- `merge(iterator beg1,iterator end1 ,iterator beg2,iterator end2,iterator dest);`

  //容器元素合并，并存储到另一个容器中

  //注意：两个容器必须是有序的

  //beg1 容器1开始迭代器

  //end1 容器1结束迭代器

  //beg2 容器2开始迭代器

  //end2 容器2结束迭代器

  //dest 目标容器开始迭代器



#### 5.3.4 reverse

- `reverse(iterator beg,iterator end);`

  //反转指定范围的元素

  //beg开始迭代器

  //end结束迭代器



### 5.4 常用拷贝和替换算法

**算法简介：**

- `copy`                          //容器内指定范围的元素拷贝到另一个容器中
- `replace`                     //将容器内指定范围的旧元素修改为新元素
- `replave_if`                 //容器内指定范围满足条件的元素替换为新元素

- `swap`                         //互换两个容器的元素





#### 5.4.1 copy

**函数原型：**

- `copy(iterator beg,iterator end,iterator dest);`





#### 5.4.2 replace

- `replace(iterator beg, iterator end, oldvalue, newvalue);`

  // 将区间内旧元素替换成新元素

  // beg开始迭代器

  // end结束迭代器

  // oldvalue 旧元素

  // newvalue 新元素





#### 5.4.3 replace_if

- `replace_if(iterator beg, iterator end ,_Pred, newvalue);`

- // 按条件替换元素，满足条件的替换成新元素

  // beg开始迭代器

  // end结束迭代器

  // _pred 谓词

  // newvalue 新元素





#### 5.4.4 swap

- swap(container c1, container c2);

  //互换两个容器的元素

  //c1容器1

  //c2容器2





### 5.5 常用算术生成算法

- 算术生产算法属于小型算法，使用时包含的头文件为`#include<numeric>`

算法简介：

- `accmulate`      //计算容器元素累计总和
- `fill`                    //向容器中添加元素





#### 5.5.1 accumulate

- `accumulate(iterator beg, iterator end ,value);`

  //计算容器元素累计总和

  //beg 开始迭代器

  //end 结束迭代器

  //value 起始值





#### 5.5.2 fill

- `fill(iterator beg, iterator end, value);`

  //向容器中填充元素

  //value 填充的值





### 5.6 常用集合算法



**算法简介：**

- `set_intersection`        //求两个容器的交集
- `set_union`                       //求两个容器的并集
- `set_difference`             //求两个容器的差集





#### 5.6.1 set_intersection

- `set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`

  //求两个集合的交集

  //**注意：两个容器必须是有序序列**





#### 5.6.2 set_union

- `set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`

  //求两个集合的交集

  //**注意：两个容器必须是有序序列**



#### 5.6.3 set_difference

- `set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`

  //求两个集合的交集

  //**注意：两个容器必须是有序序列**

