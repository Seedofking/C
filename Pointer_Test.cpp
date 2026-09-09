#include <iostream>
using namespace std;

int main()
{
    int *p, a = 10, b = 20; //定义一个整型变量的指针 p，p指向一个整型变量的地址，但在被定义之前，它就是一个野指针
    int *x, *y;             //*属于 x和 y, *y的整体表示一个int
    int *z = NULL;          //z是空指针，空指针指向的内存是不可以访问的
    int *xh = &b;           //初始化即赋值的写法, 不再有 *xh整体为整型而 &b为地址的解释意义
    //int *xh = (int *) 0x1100 这种写法可以直接指定指针初始化的地址，不过 0x1100 并非是一个合法地址

    cout << "a现在的大小是: " << a << ", a的地址为: " << &a << endl;

    p = &a; //&是取地址，&a就是一个地址
    cout << "p指向a的地址, 为: " << p << endl;

    *p = 60; //由于 p已经指向 a，可以通过指针 p修改 a的值
    cout << "a现在的大小为: " << a << endl;

    x = &b;
    *x = 100; //*是解引用，*x整体可以表示一个整型变量
    cout << "x的地址为: " << x << ", x所指向内存的值为 :" << *x << endl;

    cout << "在32位操作系统下, 各种指针都占4个字节空间" << ", 在64位系统下占8个字节空间" << endl;
    cout << "sizeof (int *) =" << sizeof(int *) << endl;

    const int *yh = &a;
    //常量指针，int *yh 的整体不可修改，即 yh指向的值不可修改，不能通过 yh改变其指向的值 a，但可用 yh = &b改变指向对象
    int *const zh = &a;
    //指针常量，p不可修改，即 p指向的对象不可修改，但可用 *zh = 40改变 zh指向的值
    const int *const zyh = &a;
    //指向对象和指向的值都不可改变

    int arr[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int *pp = arr; //使用指针访问数组
    cout << "int arr[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};" << endl;
    cout << "*pp = " << *pp << endl;
    cout << "*(pp + 1) = " << *(pp + 1) << endl;
    cout << "*(pp + 5) = " << *(pp + 5) << endl;

    y = NULL; //一定不要留下缺乏定义的指针，定义时就应写 NULL

    cout << "使用没被使用的指针：" << y << ";" << z << ";" << xh << ";" << yh << ";" << zh << ";" << zyh << endl;

    system("pause");
    return 0;
}