#include <iostream>
using namespace std;

/*继承
 *继承是代码可以复用的最重要手段，其允许在保持原有类的特性的基础上进行扩展，增加功能
 *通过继承产生的新类叫做子类或派生类，被继承的叫父类或基类
 *
 *1.定义方法： class 新类名:继承方式 继承类名    class Son : public Parent {}
 *2.继承方法：几乎不使用protected继承或public继承，通常使用public继承
 *      public继承：父类成员在子类中保持原有访问级别
 *      private继承：父类成员在子类成员全部变成private成员
 *      protected继承：父类中public成员变成protected，其余的不变
 *3.private成员在子类中依然存在，但是无法访问，不论任何方法子类都不能直接使用父类的私有成员，需要friend声明才可用
 *4.父类中原来的各种成员都会继承给子类，只要是public或者protected属性子类都可以直接用
 *5.父类有（多个）构造函数时，子类需要实现与父类相对应的（多个）构造函数，推荐使用初始化列表的方式
 *      定义方法：
 *      父类：
 *      {
 *          int a, b, c;
 *          构：Pare(int a_, int b_, int c_) : a(a_), b(b_), c(c_){构造函数其他内容}
 *      }
 *      //a(a_)的意思是，将Pare()中传入的形参 a_赋值给 Pare的 a, 复制的顺序会按照声明顺序int a, b, c来，而不是：后的顺序
 *
 *      子类：
 *      {
 *          int d;
 *          构：Son(int a_, int b_, int c_, int d_) : Pare(int a_, int b_, int c_), d(d_) {构造函数其他内容}
 *      }
 *      //这样做会先实例化父类再实例化子类，初始化列表会按照被声明的顺序进行，先创建父类的Pare，再创建子类的d
 *
 *      创建子类：
 *      Son sss(1，2，3，4)；
 *
 *多继承：
 *多继承容易让代码逻辑复杂，不建议使用
 *效果是让一个子类继承多个父类的属性
 *
 *1.定义方法：class D: public A, private B, protected C {};将多个基类用逗号隔开，前面加属性
 *2.二义性问题：当两个父类都有同一个名字的变量或函数时，就会出现歧义
 *      解决方法1：利用作用域限定符：： Son.Pare_A::show();
 *      解决方法2：在子类中重写同名成员，覆盖掉父类的相关成员
 *3.二义性问题：虚基类：当一个祖父类被两个父类继承，两个祖父类都有同名变量a，也会出现歧义
 *      解决方法1.2.也适用
 *      解决方法3.将父类对祖父类的继承方式改为虚继承，子类访问从组父类继承过来的成员就不会再有二义性问题
 *
 *
*/

class Pa
{
public:
    int a;
    /*
        Pa(int xa, int xb, int xc)
        {
            a = xa;
            b = xb;
            c = xc;
        }
        用构造函数内部赋值是错误的，赋值在成员初始化完成之后再做操作，但子类构造开始时会默认调用父类无参构造，但是父类是有参构造，会造成错误
        但如果使用初始化列表，变量就可以在对象内存刚分配完成时就初始化成员变量，优先级最高
    */
    Pa(int xa, int xb, int xc) : a(xa), b(xb), c(xc)
    {
    } //这样就可以完成赋值, 构造函数里面可以不放东西

    void Show()
    {
        cout << "Pa_Show:" << "a = " << a << endl;
    }

protected:
    int b;

private:
    int c;
};

class Pb
{
public:
    int a;

    Pb(int xa, int xb, int xc) : a(xa), b(xb), c(xc)
    {
    }

    void Show()
    {
        cout << "Pb_Show: " << "b = " << c << endl;
    }

protected:
    int b;

private:
    int c;
};

class Sa : public Pa
{
public:
    int sd;

    Sa(int xa, int xb, int xc, int xd) : Pa(xa, xb, xc), sd(xd)
    {
        cout << "Sa created" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c is private" << endl;
    } //子类传入形参xa, xb, xc, xd后，先把 xa, xb, xc传给父类构造函数，然后再把xd传给sd，该过程不会创建一个父类对象
};

class Sb : protected Pb
{
public:
    int sd;

    Sb(int xa, int xb, int xc, int xd) : Pb(xa, xb, xc), sd(xd)
    {
        cout << "Sb created" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c is private" << endl;
    }
};

class Sc : private Pa
{
public:
    Sc(int xa, int xb, int xc) : Pa(xa, xb, xc)
    {
        cout << "Sc created" << endl;
        cout << "Sc all private" << endl;
    }
};

class Sab : public Pa, public Pb
{
    //Pa和Pb都有相同的a, b, c变量，因此子类也会存有两份来自不同父类的a, b, c变量，需要分别访问
public:
    int a;

    Sab(int spaa, int spab, int spac, int spba, int spbb, int spbc, int saba) : Pa(spaa, spab, spac),
        Pb(spba, spbb, spbc), a(saba)
    {
        cout << "Sab created" << endl;
        cout << "Pa::a = " << Pa::a << endl; //在类内，对象还没有创建，不能使用对象Pa.a来访问，且Pa是类名而不是对象名
        cout << "Pb::a = " << Pb::a << endl; //在类内的成员函数作用域内可以使用Pa::来访问值，因为类内使用::默认带有this->Pa::a的效果
        cout << "Sab::a = " << a << endl; //子类重写的a不用限定符，不过也不会覆盖父类的同名变量，默认调用重写变量，不歧义
    }

    void Show() //子类重写的函数也不会覆盖父类原有的函数，但是直接调用sab1.Show()不会再有歧义，默认调用重写函数
    {
        cout << "Sab_Show: " << "a = " << a << ", b = " << Pb::b << endl;
    }
};


int main()
{
    Sa sa1(1, 2, 3, 4);
    Sb sb1(5, 6, 7, 8);
    Sc sc1(9, 10, 11);
    Sab sab1(12, 13, 14, 15, 16, 17, 18);

    cout << "sa1 public Pa" << endl;
    cout << "sa1.a = " << sa1.a << endl;
    cout << "sa1.b is protected" << endl;
    cout << "sa1.c is private" << endl;

    cout << "sb1 protected Pb" << endl;
    cout << "sb1.a is turned protected" << endl;
    cout << "sb1.b is protected" << endl;
    cout << "sb1.c is private" << endl;

    cout << "sc1 private Pa" << endl;
    cout << "sc1 all is private" << endl;

    sa1.Show();
    cout << "sb1.Show() failed for protected" << endl;
    sab1.Show();
    sab1.Pa::Show();
    sab1.Pb::Show();


    system("pause");
    return 0;
}
