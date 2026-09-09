#include <iostream>
using namespace std;

int &Times(int &a, int &b);

int main()
{
    int a = 9;
    int num1 = 3, num2 = 4;
    int &red = a;

    /*
    引用的初始化必须当场定义 = 谁，其本质是 int * const red = a;编译器会做所有关于解引用的操作，使用时当成 a即可
    引用 &red = a, 以后 red就是 a的别名，由 red代表 a，red也指向 a的内存，a变即 red变，red 变即 a变
    由于是 int *const red 所以一定不能改变 red所指对象，只要 red = a，就不能再 = Times（）
    */

    red = 6;
    cout << "此时a = " << a << endl;

    int &ref = Times(num1, num2);
    //函数传回 T即 Times的别名，这样以后修改 ref，Times也会被修改，是现在函数外修改函数内的静态变量
    //传回的别名必须是静态变量，不然存在栈的形参会随着函数的结束消失

    cout << "num1 = " << num1 << " ; num2 = " << num2 << endl;
    cout << "现在ref的值为: " << ref << endl;

    Times(num1, num2) = 19;
    //如果函数返回的是别名，那么这个别名也可以代表这个函数，将函数放在左边赋值实际上会把 T连同 ref一起改变
    cout << "现在ref的值为: " << ref << endl;

    system("pause");
    return 0;
}

int &Times(int &a, int &b)
{
    //&a和 &b传入的是 a和 b的引用，所以函数内对 &a和 &b的操作会直接改变传入参数本身
    //需要的参数是 num1 num2这样的变量
    static int Times;
    static int &T = Times;

    cout << "请输入倍数：" << endl;
    cin >> Times;

    a *= Times;
    b = b * Times * Times;

    return T;
}
