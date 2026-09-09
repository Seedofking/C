#include "Function_Test_App.h"

int Value_ElseWhere = 13; //Value_ElseWhere是一个全局变量
static int Val_Inner = 1;
//Val_Inner是一个全局变量，但仅限本文件内使用，其他文件不论有无 extern都不可以直接使用，但是可以放在本文件的函数内，由本文件函数在外可调用。生命周期：随程序全程存在，全局内存区
const int Val_C = 15; // Val_C是一个常量，其值不能再改变

//值传递
int Max(int a = 66, int b = 77)
{
    /*
    函数的默认参数：赋默认值，如果没有传入参数，就会用默认值
    只要左边有默认值，右边都必须有默认值
    函数的声明和实现只有其中一个可以有默认值
    */

    // temp是函数的内部变量，其作用域和生命周期都限制在该函数内
    //函数传入的 a和 b都是形参，其生命周期仅限在该函数以内，函数运行完毕以后就会销毁
    int temp;
    if (a >= b)
    {
        temp = a;
    }
    else
    {
        temp = b;
    }
    return temp;
}

//地址传递
void Times(int *a, int *b)
{
    static int Times;
    //Times是静态局部变量，作用域仅限函数内，但是生命周期变为整个程序，函数运行结束时，其值会保留，下次函数运行时会继承上次的值
    //函数传入了 a和 b的地址，函数内对 a和 b的改变就是对 ab本身的直接改变
    //函数需要的参数类型是指针，所以传入的参数需要也是指针，或者给 num1和 num2取地址传入
    cout << "请输入倍数：" << endl;
    cin >> Times;

    //由于传入的参数是指针，对其使用数值操作时都要解引用
    *a *= Times * Val_Inner;
    *b = *b * Times * Times;
}

//引用传递
void Times(int &a, int &b)
{
    //&a和 &b传入的是 a和 b的引用，所以函数内对 &a和 &b的操作会直接改变传入参数本身
    //需要的参数是 num1 num2这样的变量即可，不需要 num1 和 num2是引用类型的变量
    static int Times;

    cout << "请输入倍数：" << endl;
    cin >> Times;

    a *= Times;
    b = b * Times * Times;
}

/*
函数重载：
条件：
1、同一作用域下
2、函数名称相同
3、函数参数类型不同，或者个数不同，或者顺序不同

注意事项：
1、返回值不同不可作为区分
2、在参数都为引用时，const可作为区分，f (const int &a) 和 f (int &a) 传参 int a到 f(a)进后者，传 f(10)进前者
3、函数重载遇上默认参数时，如 f(int a, int b = 10)和 f(int a)，调用时写 f(11)会出现歧义，只能写 f(11, 12), 应避免
*/