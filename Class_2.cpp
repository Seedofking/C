#include <iostream>
using namespace std;

//构造函数需放在public，不然也会没权限访问的
//类的定义过程即构造函数的执行，定义即构造

class Man
{
public:
    int Age, Rank;

public:
    Man() //默认构造函数
    {
        Age = 18;
        Rank = 1;
        cout << "触发默认构造函数调用" << endl;
        cout << "已将参数初始化为Age=18, Rank = 1" << endl;
    }

    Man(const int Age, const int Rank) //含参构造函数
    {
        this->Age = Age; //使用 this指向该作用域的类，此时可以让传入的数据名跟类的数据同名而没有歧义
        this->Rank = Rank;
        cout << "触发含参构造函数调用" << endl;
        cout << "已将参数初始化为Age=" << Age << ", Rank=" << Rank << endl;
    }

    Man(const Man& ma) //拷贝构造函数，参数须要是 const 类 &名
    {
        Age = ma.Age;
        Rank = ma.Rank;
        cout << "触发拷贝函数调用" << endl;
        cout << "已将参数拷贝为Age=" << Age << ", Rank=" << Rank << endl;
    }

    ~Man() { cout << "类的生命周期已结束, 析构函数已触发" << endl; }
    //析构函数会在类的生命周期结束时自动触发，无需手动调用
};

void Dowork1(const Man& a)
{
    cout << "test1" << endl;
    cout << "clear warning " << a.Age << endl;
}

void Fun1()
{
    cout << "创建Man b" << endl;
    const Man b;
    Dowork1(b); //函数传入参数时会触发拷贝构造函数
}

Man Dowork2()
{
    Man c;
    return c; //函数返回参数时会触发拷贝构造函数
}

void Fun2()
{
    cout << "test2" << endl;
    Man d = Dowork2();
    //但是现代编译器默认开启 RVO (返回值优化)：直接把对象构造到外部接收变量d的内存空间，直接省略拷贝构造调用，所以控制台看不到拷贝打印。
}

int main()
{
    Man one;
    Man two(22, 5);
    Man three(two);

    Fun1();
    Fun2();

    system("pause");
    return 0;
}
