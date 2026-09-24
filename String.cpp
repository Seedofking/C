#include <iostream>
#include <string>
using namespace std;

/*
 *字符串型
 *  C语言风格：char str[] = "hello world"     数组版本放在栈内存，可以用str[]修改
 *           char* str = "hello world"      指针版本存放在只读常量区，不可修改，指针只是保留其地址
 *  C++风格： string str = "hello world" string是一个类，不仅包含了其中的字符数组，还封装了其处理方法
 *
 *string容器
 *  访问：所有关于[]下标、pos位置的都是从0开始的
 *  构造函数：
 *  1.string();                                         string str;                 默认构造函数
 *  2.string(const char* s);                            string str(s);              拷贝构造
 *    string(const string& str);
 *  3.string(int n, char c);                            string str(10, 'a');        创建n个a字符
 *
 *  赋值操作：
 *  1.string& operator = (const char* s);               str1 = str2 / "Hello";     =将字符串str2赋值给str1
 *    string& operator = (const string &s);
 *  2.string& operator = (char c);                      str1 = 'a';                 =将后面的字符赋值给str1
 *  3.string& assign(const char* s);                    str1.assign(str2);          assign将str2赋值给str1
 *  4.string& assign(const char* s, int n);             str1.assign(str2, 5);       assign把字符串str2的前n个字符赋值给str1
 *  5.string& assign(const string& s);                  str1.assign(str2);          assign把字符串str2赋值给str1
 *  6.string& assign(int n, char c);                    str1.assign(5, 'x');        assign把n个字符x赋值给str1
 *
 *  尾部拼接：
 *  1.string& operator+=(const char* str)               str1 += str2 / "Hello";     +=将字符串拼接到str1后面
 *    string& operator+=(const string& str)
 *  2.string& operator+=(const char c)                  str1 += 'a';                +=将字符拼接到str1后面
 *  3.string& append(const char* s)                     str1.append(str2);          append将str2拼接到str1后面
 *    string& append(const string& s)
 *  4.string& append(const char* s, int n);             str1.append(str2, 5);       append将str2前n个字符拼接在str1后面
 *  5.string& append(const string&s, int pos, int n)    str1.append(str2, 2, 5);    append将str2从pos开始的n个字符接在str1后
 *
 *  查找和替换：
 *  pos若不填，正find则默认为0, rfind则默认为末尾, rfind()返回的位置也是正序位置，只是从后开始找到第一个符合条件的字符串
 *  1.int find(const string& str, int pos);             p = str1.find("Hello", 5);  从pos=5开始查找"Hello"第一次出现的位置
 *    int fing(const char* s, int pos);
 *  2.int find(const char* s, int pos, int n);          p = str1.find(str2, 3, 5);  从pos开始查找，str2前5个字符第一次出现位置
 *  3.int find(const char c, int pos);                  p = str1.find('c');         从0开始查找，字符c第一次出现位置
 *  4.int rfind(const string& str, int pos);            p = str1.rfind("He");       从后开始查找，"He"第一次出现的位置
 *    int rfind(const char* s,int pos);
 *  5.int rfind(const char* s, int pos, int n);         p = str1.rfind(str2, 1, 3); 从前第2个字倒着找，str2前3字符首次出现位置
 *  6.int rfind(const char c, int pos);                 p = str1.rfind('a', 1);     从后找字符a首次出现位置
 *  7.string& replace(int pos, int n, const char* s);   str1.replace(1, 3,"11111"); str1从第2个字后的3个字符被替换为"11111"
 *  8.string& replace(int pos, int n, const string& str);
 *
 *  字符串比较
 *  int compare(const string& s);                       flag = str1.compare(s2)     ASCII码的大小比较，比最前出现的字符的大小
 *      1=2: 返回 0
 *      1>2: 返回 1
 *      1<2: 返回-1
 *  作用：主要用于判断字符是否相同，判断谁大谁小可以用于排序
 *
 *  字符串存取
 *  1.char& operator[](int n)                           c = str[1];                 通过[]下标访问取 / 改字符
 *  2.char& at(int n)                                   c = str.at(1);              通过at访问取 / 改字符
 *
 *  插入和删除
 *  1.string& insert(int pos, const char* s);           str1.insert(1, str2);       把str2插进str1
 *    string& insert(int pos, const string& str);
 *  2.string& insert(int pos, int n, char c);           str1.insert(2, 3, ‘c');     在str1的第3个字前插入3个c
 *  3.strint& erase(int pos, int n)                     str1.erase(1, 3);           删除从pos开始的n个字符
 *
 *  string子串
 *  string substr(int pos, int n);                      str1.substr(2, 4);          返回从pos开始的n个字符组成的字符串
 *  作用：可以搭配查找使用，在指定位置截取需要的内容
 *
 *  整型转字符串
 *  string to_string(int num);                          str1 = to_string(num)       将num从整型转化为字符串型
 *
 */


int main()
{
    const char* str1 = "Hello"; //指针型
    char str2[] = "World"; //数组型
    string str3_1; //string默认构造
    string str3_2;
    string str3_3;
    string str3_4;
    string str3_5;
    string str4 = str1; //等号构造
    string str5(str2); //拷贝构造
    string str6(5, '7'); //5个7构造
    string str7;
    string str8;
    string str9;
    string str10;
    string str11;
    string str12;
    string str13;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str4: " << str4 << endl;
    cout << "str6: " << str6 << endl;


    str3_1 = str4; //等号字符串赋值
    str3_2 = 'a'; //等号字符赋值
    str3_3.assign(str1); //assign拷贝复制
    str3_4.assign(str2, 3); //assign拷贝赋值str2的前3个字符
    str3_5.assign(4, 'a'); //assign赋值4个a

    cout << "str3_1: " << str3_1 << endl;
    cout << "str3_2: " << str3_2 << endl;
    cout << "str3_3: " << str3_3 << endl;
    cout << "str3_4: " << str3_4 << endl;
    cout << "str3_5: " << str3_5 << endl;

    str6 += str1;
    cout << "str6: " << str6 << endl;
    str6.append(str2);
    cout << "str6: " << str6 << endl;
    str6.append(str2, 1, 3);
    cout << "str6: " << str6 << endl;


    int ps1, ps2, ps3, ps4, ps5;

    ps1 = str4.find("ll", 1);
    ps2 = str6.find(str2, 2);
    ps3 = str6.rfind(str2, 2);
    ps4 = str6.find("o", 2);
    ps5 = str6.rfind(str2, 15);
    cout << "ps1: " << ps1 << endl;
    cout << "ps2: " << ps2 << endl;
    cout << "str6.size() = " << str6.size() << endl;
    cout << "ps3, 2: " << ps3 << ", return -1 means nothing found" << endl;
    cout << "ps3, 15: " << ps5 << endl;
    cout << "ps4: " << ps4 << endl;

    str8 = "Awfullife";
    str9 = " But happy ";
    str8.replace(0, 5, str9);
    cout << "str8: " << str8 << endl;

    str10.assign("lie");
    str11.assign("lie");
    str12.assign("Believe");

    if (str10.compare(str11) == 0)
    {
        cout << "lie = lie" << endl;
    }
    else
    {
        cout << "str10 != str11" << endl;
    }

    cout << "lie.compare(Believe) = " << str10.compare(str12) << endl;

    cout << "str12[3] = " << str12[3] << endl;
    str12[3] = 'I';
    cout << "[3] = I: " << str12 << endl;
    str12.at(3) = 'i';
    cout << "at(3) = i: " << str12 << endl;

    str12.insert(2, str10);
    cout << "str12 insert lie: " << str12 << endl;

    str12.insert(2, 3, 'h');
    cout << "str12 insert 3h: " << str12 << endl;

    str12.erase(2, 3);
    cout << "str12 erase 3h: " << str12 << endl;
    int liePos;
    liePos = str12.find("lie");
    str13 = str12.substr(liePos, 3);
    cout << "str13 = substr(str12.find('lie') = " << str13 << endl;

    cout << "lie.compare(lie in Belielieve) = " << str13.compare(str10) << endl;

    int INTNUM = 114514;
    cout << "INTNUM = " << INTNUM << endl;

    string INTSTR = to_string(INTNUM);
    cout << "INTSTR = to_string(INTNUM) = " << INTSTR << endl;
    int Pos514 = INTSTR.find("514");
    string STR514 = INTSTR.substr(Pos514, 3);

    cout << "substr: STR514 = " << STR514 << endl;


    system("pause");
    return 0;
}
