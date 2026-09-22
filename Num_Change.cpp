#include <iostream>
#include <iomanip>
using namespace std;

/*
 *类型自动转换规则：
 *1.自动向精度更高、范围更大的类型转换
 *  整型提升：char， short参与运算，先全部提升为int， 然后向更精准大范围的的类型转换
 *  bool - char - short - int - long - long long - float - double - long double
 *2.运算时，两边操作数会统一转换成两者中等级更高的类型，结果也是该类型
 *  如 int + double会触发 int转 double， 结果也是 double
 *3.int / int整数除法，不会自动变成浮点数, 若想要实现整型除出小数，则可以把其中一个数强转为fl，或者在除之前乘1.0
 *  如 int a, b;  float c = static_cast(a) / b or float c = 1.0 * a / b
 *  不能让a / b先算完，a / b * 1.0就没用了, static_cast<double> (a / b)也没用
 *4.有符号和无符号混合运算，有符号会转成无符号，容易出现负数变成超大正数
 *5.赋值转换：把右边表达式的值强制转为左边变量的类型，会发生截断 / 舍入
 *  -浮点赋给整型：比如int i; double d = 3.99; i = d;就会 double转 int，直接截断小数部分，i = 3
 *  -大范围类型赋值给小范围：会丢失高位，可能溢出
 *  -函数参数匹配：实参自动转换为形参类型
 *
 *显式强制类型转换：static_cast<类型>(表达式)
 *1.强转指挥改变值的解释方式, 不会改变原始内存, 依然有数据溢出和精度丢失的可能
 *2.小类型转化为大类型不会丢失数据, 但是大类型转换为小类型会丢失数据
 *
 *浮点数保留小数位
 *特点: 只是输出的显示效果, 不会改变变量本身出存的值
 *方法:
 *  1.C语言printf格式化输出
 *      头文件: #include<cstdio>
 *      格式符:  %.nf 保留n位小数, 有四舍五入, 在输出时%f可以输出float或double, %lf用于double输入
 *  2.C++cout输出控制
 *      头文件: #include<iomanip>
 *      格式符: cout << fixed << setprecision(2) << x << endl; 保留小数点后两位
 *             cout << setprecision(2) << x << endl; 保留两位有效数字
 *
 */


int main()
{
    short shoort = 12;
    int innt1 = 114514191;
    cout << "innt1 + shoort= " << innt1 + shoort << endl; //自动向大类型转换，结果也会是大类型
    shoort = innt1;
    cout << "shoort = innt1 then shoort =" << shoort << endl; //大赋值给小丢失数据

    int a = 5, b = 3;
    cout << "a / b = " << a / b << endl;
    cout << "static_cast<double>(a) / b = " << static_cast<double>(a) / b << endl;
    cout << "1.0 * a / b = " << 1.0 * a / b << endl;
    cout << "fixed 2 : " << fixed << setprecision(4) << 1.0 * a / b << endl;
    cout << "2 : " << setprecision(4) << 1.0 * a / b << endl;


    system("pause");
    return 0;
}
