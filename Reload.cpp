#include <iostream>
using namespace std;

/*
 *运算符重载
 *规则：
 *  不允许创造新的运算符，只能对C++已有的运算符重载
 *  不能重载 " . * :: sizeof ? "
 *  不能更改单目、双目运算符操作数的个数，比如 + 是双目运算符，需要两个参数; ++是单目运算符就需要一个参数
 *  重载不能改变运算符的优先级别
 *  重载不能改变运算符的结合性
 *  重载的运算符必须和用户自定义类型的对象一起使用，参数至少有一个是类对象或其引用，运算符只对定义了重载的类生效，对其他的变量无影响
 *
 *
 *1.单/双目运算符：
 *  使用：
 *  使用operator关键字，返回类型 operator符号(传入参数){操作 ; return}
 *  A& operator+=(const A& an){this-> x+= an.x  return this*}
 *
 *2.输入输出流运算符：
 *  使用：
 *  cin类型：istream类的对象，cout类型：ostream类的对象，流运算符：<< >>
 *  必须使用友元函数形式重载，这样就可以不用创建对象而直接调用函数，输入输出流重载不是类的成员，应该声明为类的友元函数
 *  也需要operator关键字
 *
 *  输出流类内声明: { friend ostream& operator << (ostream os, const A& an) }
 *  输入流类内声明: { friend istream& operator >> (istream is, A& an) }    //输入流需要改变类的参数，所以传入引用不能加const
 *
 *
 *  << 解释：
 *  << 本质是也一个双目运算符，在标准库中作用是左移运算符，在#include <iostream>之后，当其左边为输出流对象比如cout时，就会触发运算符重载，
 *  输出右边的内容。而对其再次重载之后，识别左边是输出流对象cout，且右边是在运算符重载时定义需要输入的类对象时，就会触发重载的内容
 *  friend ostream& operator << (ostream os, const A& an);
 *  ostream & operator << (ostream &os, const A& an)
 *  {
 *      os << "an.x = " << an.x << "an.y = " << an.y
 *      return os;
 *  }
 *  在实现该函数，friend是为了将该函数作为全局友元函数使用，ostream& 则规定了返回类型为输出流类，return的os会返回到 << 的左边
 *
*/
class A
{
protected:
    int x, y;

public:
    A(int x, int y) : x(x), y(y)
    {
    }

    A& operator +=(const A& a) //运算符重载的返回值是自定义的，可以是返回这个类，也可以返回其中的一种变量
    {
        x += a.x;
        y += a.y;
        return *this;
    }

    int operator ++() //这视为前置++，前置++是+1之后拿着加了之后的值干活，后置++是拿着x干活，之后再+1
    {
        ++x;
        return x;
    }

    A operator++(int) //后置++， 使用哑元int参数触发重载
    {
        A temp = *this;
        x++;
        return temp; //拿着加之前的值干活，之后再加
    }

    friend istream& operator >>(istream& is, A& a);
    friend ostream& operator <<(ostream& os, const A& a);
};

istream& operator >>(istream& is, A& a)
{
    cout << "cin >> A: 请输入x, y的值" << endl;
    is >> a.x >> a.y;
    return is;
}

ostream& operator <<(ostream& os, const A& a)
{
    os << "a.x = " << a.x << ", a.y = " << a.y;
    return os;
}

int main()
{
    A a1(3, 4);
    A a2(0, 0);

    cout << a1 << endl;
    cin >> a2;
    cout << a2 << endl;

    a1 += a2;
    cout << "++a1 : a1.x + 1 = " << ++a1 << endl;
    a2++;
    cout << "a2++ : a2.x = " << endl << a2 << endl;

    system("pause");
    return 0;
}
