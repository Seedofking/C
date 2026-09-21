#include <iostream>
using namespace std;

/*
 *类型自动转换规则：
 *1.自动向精度更高、范围更大的类型转换
 *  整型提升：char， short参与运算，先全部提升为int， 然后向更精准大范围的的类型转换
 *  bool - char - short - int - long - long long - float - double - long double
 *2.运算时，两边操作数会统一转换成两者中等级更高的类型，结果也是该类型
 *  如 int + double会触发 int转 double， 结果也是 double
 *3.int / int整数除法，不会自动变成浮点数
 *4.有符号和无符号混合运算，有符号会转成无符号，容易出现负数变成超大正数
 *5.赋值转换：把右边表达式的值强制转为左边变量的类型，会发生截断 / 舍入
 *  -浮点赋给整型：比如int i; double d = 3.99; i = d;就会 double转 int，直接截断小数部分，i = 3
 *  -大范围类型赋值给小范围：会丢失高位，可能溢出
 *  -函数参数匹配：实参自动转换为形参类型
 *
 *显式强制类型转换：
 *
 *
 */


int main()
{
    system("pause");
    return 0;
}
