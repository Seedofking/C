#include <iostream>
using namespace std;
#include "Function_Test_App.h"

//extern int Value_ElseWhere; 如果在头文件 extern，其他文件则不需要 extern

int main()
{
    int num1, num2, Max_Num;
    cout << "请输入需要求最大值的两个数：" << endl;
    cin >> num1 >> num2;

    Max_Num = Max(num1, num2);
    cout << "最大的数是：" << Max_Num << endl;

    int numa, numb;
    cout << "请输入需要乘倍数和乘倍数平方的a和b的值: " << endl;
    cin >> numa >> numb;
    Times(&numa, &numb);
    cout << "a的值为: " << numa << endl;
    cout << "b的值为: " << numb << endl;

    system("pause");
    return 0;
}