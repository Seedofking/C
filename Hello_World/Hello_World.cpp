#include <iostream>
using namespace std;

#define A_Week 7
#define SHORT_BIT "2bit"
#define INT_BIT "4bit"
#define LONG_BIT "4bit_except_Linux(64)_8bit"
#define LONG_LONG_BIT "8bit"
#define FLOAT_BIT "4bit"
#define DOUBLE_BIT "8bit"

int main()
{
    int i;

    int a = 3;
    const int b = 6;
    float fl = 3.1415926;
    double db = 3e2;
    double minus_db = 3e-2;
    /*
    SIZENAME变量类型是**char，是*char指针的指针，也是一个数组，数组有很多元素为*char类型的变量，数组存了很多个数组（字符串）
    数组的元素变量类型是*char，是char的指针，也是数组，数组整体是一个字符串，元素是char，一个个的字符型变量
    char* a = "chuan"是一个字符串
    char* a[]; a[0] = ......; a是一个字符串数组，在C++中可以用string a[]实现
    */

    /*
   基础定义区别
    char*（字符指针，C 语言原生）
    只是一个内存地址，仅保存字符串首字符位置；
    不记录字符串长度，靠末尾 \0 判断结束；
    分两种场景：
    const char* p = "abc";：指向只读常量区字符串，不能修改字符，即字符串
    char buf[100], *p = buf;：指向栈 / 堆字符数组，可修改内容，是字符数组


    std::string（C++ 标准库封装类）
    是一个完整类对象，不是单纯地址；
    内部自动管理三块数据：字符数组、字符串长度、容量；
    内存自动分配释放，不用手动处理 \0、不用strcpy。
   */
    const char *SIZENAME[6];
    SIZENAME[0] = "SHORT_BIT        Max: +-2^15-1   32767   3.2x10^4";
    SIZENAME[1] = "INT_BIT          Max: +-2^31-1           2.1x10^9";
    SIZENAME[2] = "LONG_BIT         Max: +-2^31-1           2.1x10^9";
    SIZENAME[3] = "LONG_LONG_BIT    Max: +-2^63-1           9.2x10^18";
    SIZENAME[4] = "FLOAT_BIT        Actu: +-1.6x10^7        Max: 3.4x10^38";
    SIZENAME[5] = "DOUBLE_BIT       Actu: +-2^53            Max: 1.7x10^308";

    char SIZE[][100] = {SHORT_BIT, INT_BIT, LONG_BIT, LONG_LONG_BIT, FLOAT_BIT, DOUBLE_BIT};

    cout << "HelloWorld & " << a << " & " << b << endl;
    cout << "一个星期有 " << A_Week << " 天" << endl;
    cout << "3.1415926 = " << fl << endl;
    cout << "3e2 = " << "3 * 10 ^ 2 = " << db << endl;
    cout << "3e-2 = " << "3 * 10 ^ - 2 = " << minus_db << endl;

    for (i = 0; i < (int)(sizeof(SIZENAME) / sizeof(char *)); i++)
    {
        cout << SIZENAME[i] << " == " << SIZE[i] << endl;
    }

    system("pause");
    return 0;
}
