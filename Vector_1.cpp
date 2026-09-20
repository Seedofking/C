#include <iostream>
#include <vector>   //使用vector需要包含<vector>头文件
#include <algorithm>    //使用算法需要包含<algorithm>头文件
#include <string>
using namespace std;

/*
 *模板简介：
 *对函数做泛型，使得函数的参数 / 返回值可以是任何类型
 *自动推导类型使用：
 *  template <typename T>
 *  T Add(T a, T b) { return a + b; }
 *  Add(a, b);
 *显式指定类型使用：
 *  Add<int>(a, b);
 *
 *STL简介：
 *标准模板库，是一套包含数据结构和算法的标准库，可以大大提高复用性，其中几乎所有代码都采用了模板类或者模板函数
 *包含：容器，算法，迭代器，仿函数，适配器，空间适配器
 *  1.容器：各种数据结构, 如vector, list, deque, set, map等, 用于存放数据
 *  2.算法：各种常用算法, 各种常用算法, 如sort, find, copy, for_each等
 *  3.迭代器: 可以作为访问容器的游标而又无需暴露该容器内部的表示方式, 行为类似指针, 每个容器有自己专属的迭代器
 *  4.仿函数: 行为类似函数,可以作为算法的某种策略
 *  5.适配器: 一种用来修饰容器、仿函数、迭代器接口的东西
 *  6.空间适配器: 用来负责空间的配置和管理
 *
 *容器:
 *序列式容器: 强调值的排序, 序列式容器中的每个元素都有固定的位置
 *关联式容器: 二叉树结构, 各元素之间没有严格的物理上的顺序关系
 *
 *迭代器:
 *输入迭代器: 对数据的只读访问, 支持 ++ == !=
 *输出迭代器: 对数据的只写访问, 支持 ++\
 *前向迭代器: 读写操作, 可以向前推进迭代器, 支持 ++ == !=
 *双向迭代器: 读写操作, 可以向前和向操作, 支持++ --
 *随机访问迭代器: 读写操作,可以跳跃地访问任何数据, 是功能最强的迭代器, 支持 ++ -- [n] -n < <= > >=
 *容器中常用的迭代器为双向迭代器和随机访问迭代器
 *
 *vector
 *本质动态数组
 *特性：
 *边插入变扩展，在插入成员个数要大于容量时，vector就会自动扩展空间，扩展空间会释放掉原有的空间，在另一处开辟更大的空间
 *使用：
 *Vector<int> v;    创建一个容器并通过模板参数指定存放的数据类型
 *
 *
 */
void Print_Vector1(vector<int>& v) //如果传入参数改成const vector<int> &v
{
    //下面的迭代器就要改成for(vector<int>::const_iterator it; .... 是只读的
    //for遍历输出
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) //++it在for
    {
        cout << *it << endl;
    }
}

void Print_Vector2(const vector<int>& v)
{
    //while遍历输出
    vector<int>::const_iterator pBegin = v.begin();
    vector<int>::const_iterator pEnd = v.end();
    while (pBegin != pEnd)
    {
        cout << *pBegin << endl;
        pBegin++;
    }
}

//为for_each准备的输出函数
void One_Print(int a)
{
    cout << a << endl;
}

//for_each遍历
void Print_Vector3(vector<int>& v)
{
    for_each(v.begin(), v.end(), One_Print);
}

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    friend ostream& operator<<(ostream& os, const Person& p);
};

// Person的 << 输出流运算符重载
ostream& operator<<(ostream& os, const Person& p)
{
    os << "name: " << p.name << ", age: " << p.age;
    return os;
}

//遍历输出vector中的person
void Print_Vector_Person(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl; //要弄明白it指的是谁，这里it指的是Person，*it 就是Person，而 cout << Person 触发了输出流重载
        //or    cout << it->name << endl;
        //      cout << it->age << endl;
    }
}

//通过Person*的地址遍历输出vector中的Person
void Print_Vector_Person1(vector<Person*>& v)
{
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        //这里it指向Person*，所以*it就是Person*指针，Person*可以使用->来访问里面的变量，所以这里是(*it)->
        cout << "name: " << (*it)->name;
        cout << ", age: " << (*it)->age << endl;
    }
}

//遍历输出vector嵌套vector
void Print_Vector_Vector(vector<vector<int>>& v)
{
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        //此时*it指向vector<int> 所以(*it)就是vector，作为传入下一个循环的处理的vector
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << endl;
        }
        cout << "next vector" << endl;
    }
}


int main()
{
    //vector存放内置数据类型
    vector<int> v1; //用模板参数可以指定容器中存放的数据的类型
    v1.push_back(10); //push_back可以把数据插在最后面
    v1.push_back(20);
    v1.push_back(30);
    Print_Vector1(v1);

    //vector存放对象
    vector<Person> v2;
    Person p1("AA", 5);
    Person p2("BB", 7);
    Person p3("CC", 8);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    Print_Vector_Person(v2);

    //vector存放对象指针
    cout << "------------" << endl;
    vector<Person*> v3;
    Person p4("DD", 9);
    Person p5("EE", 10);
    Person p6("FF", 11);
    v3.push_back(&p4);
    v3.push_back(&p5);
    v3.push_back(&p6); // for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    Print_Vector_Person1(v3);

    vector<int> v4;
    v4.push_back(40);
    v4.push_back(50);
    v4.push_back(60);
    Print_Vector2(v4);

    vector<int> v5;
    v5.push_back(70);
    v5.push_back(80);
    v5.push_back(90);
    Print_Vector3(v5);

    cout << "------------" << endl;

    vector<vector<int>> vv;
    vv.push_back(v1);
    vv.push_back(v4);
    vv.push_back(v5);
    Print_Vector_Vector(vv);

    system("pause");
    return 0;
}
