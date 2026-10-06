#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

/*流：
 *  本质是字符序列的缓冲区，所有读写都是对字符序列操作; 截取, 转换是通过流的提取运算符 >> , 格式化, 缓冲区处理来完成的
 *  stringstream: 字符串流, 把字符串当成流, 是内存中的字符缓冲区, 常用于字符串截取盒类型转换
 *  cin / cout: 文件 / 控制台流, 底层也是字符缓冲区
 *
 *  输入字符流: 可以把字符串转为其他类型
 *      特性:
 *      1.cin跳过空白符, (换行, 空格, tab)直到遇到非空白
 *      2.读取连续有效字符, 从缓冲区逐个拿字符, 直到遇到分隔符(空白, 与输入数据所需类型不同的非法字符), 默认以空白作为分隔符
 *      3.字符解析转换: 把读到的一串字符转成对应类型值存入val
 *      4.设置流状态: 成功: goodbit, 失败(读到非法字符): failbit, 读到流末尾: eofbit, 严重错误(流损坏): badbit
 *
 *  输出字符流: 可以把其他类型转为字符串, 写入缓冲区
 *      流程:
 *      1.会把变量val初始化, 转成一串字符
 *      2.将字符写入缓冲区
 *      3.把字符输出到目标(控制台 / 字符串)
 *
 *  字符串流: stringstream 头文件 <sstream>
 *  istringstream 从字符串读, ostringstream 写入字符串, stringstream 读写两用
 *  作用: 把字符串当作流, 方便类型转换, 分割文本
 *
 *
 *  输入输出流操作:
 *  No.1 输入流和输出流的对象:
 *  cin: 标准输入  cout: 标准输出  cerr: 标准错误, 不可重定向  clog: 标准错误
 *
 *  No.2 流对象常用的函数, 字符和字符串上面的操作      (字符流操作也常用)
 *  put(); 输出字符              get(); 输入字符
 *  write(); 输出字符串          getline(); 输入字符串
 *
 *  No.3 C++格式控制: 包含 <iomanip>
 *  用法: cout << 操作 << ;
 *  setbase(n): 设置为n进制
 *  dec 十进制, hex 十六进制小写, oct 八进制, uppercase 十六进制A-F大写   (设置后一直生效直到修改)
 *  setiosflags(ios::scientific): 将小数用科学计数法表示
 *  setprecision(n): 设置精度
 *  fixed: 将保留有效数字改为保留小数位数
 *  setw(n): 设置宽度
 *  setfill(n): 设置填充字符
 *  setiosflags(ios::left);ios::right 设置左/右对其
 *
 *  No.4 流状态查询 / 处理   (字符流操作也通用)
 *  cin.good();     返回true表示流正常         cin.bad();                是否严重损坏
 *  cin.eof();      是否到达文件尾             cin.clear();              重置状态标志为goodbit
 *  cin.fail();     是否失败(bad/fail)        cin.ignore(n, delim);     丢弃缓冲区字符, 直到n个或者遇到delim
 *
 *  No.5 换行和刷新缓冲区: 大量换行推荐'\n'减少刷新卡顿
 *  endl 换行并刷新缓冲区       '\n' 只换行        cout.flush(); 手动刷新缓冲区, 输出缓冲区内容
 *
 *  字符流操作: 包含 <sstream>
 *  No.1 初始化流对象:
 *  1.创建空流再灌入字符串:
 *      stringstream oss;
 *      oss << "Hello";
 *  2.创建同时直接传入字符串:
 *      string str = "Hello";
 *      stringstream ss(str);
 *  3.拷贝构造:
 *      stringstream ss1("test);
 *      stringstream ss2(ss1.str());
 *
 *  No.2 获取流的字符串:
 *      ss.str(): 可以获取流里面全部的字符串
 *      ss.str("New"); 给流重新设置字符串, 覆盖原有内容
 *
 *  No.3 流输出数据
 *  "100 200 Hello"
 *  使用 >> 像cin一样就可以把ss里面的数据输出给变量: ss >> a >> b >> word;
 *  对应的数据需要使用对应的数据类型接收, int a和int b会对应100和200, 而string word对应Hello
 *  特性: ss存了"100 200 Hello"之后, 每次 >> 都会让其指针向后移动, 但是使用.str()获取的数据不会发生变化
 *  用途: 使用流输出数据可以实现分割文本和类型转换
 *
 *  No.4 流写入数据
 *  int num = 666; string str = "number = ";
 *  使用 << 像cout一样就可以把变量里的数据输入给ss: ss << str << num;
 *  再用.str()就可以把流中的数据一次性取出乘整体字符串string res = ss.str(); 取出操作是复制ss其中的内容并输出
 *  特性: 每次 << 都会向其中追加新的数据, 只有使用.str("内容")才会将原数据覆盖
 *  用途: 使用流输入可以实现字符串拼接和类型转换
 *
 *  No.5 流状态重置
 *  流读到末尾后, 流会设置eof标志, 后续再>>读取会失效
 *  ss.clear(); 清除流的错误状态标志
 *  ss.str(""); 将流内部的
 *
 *  No.6
 *
 *
 *
 *
 *
 *
 */

int main()
{
    //字符流的初始化
    stringstream ss;
    string s1 = "stringstream yes! ";
    string s4 = "OK";
    int a = 114;
    //字符流的输入
    ss << s1 << a << s4;
    cout << ss.str() << endl;

    //字符流输出, 默认使用" "自动分割
    string s2, s3;
    ss >> s2;
    cout << s2 << '\n';
    ss >> s3;
    cout << s3 << endl;

    //流状态查看
    int ac;
    cout << "cin.good() = " << cin.good() << '\n';
    cout << "cin.fail() = " << cin.fail() << '\n';
    cout << "cin.eof = " << cin.eof() << '\n';

    cout << "cin >> int ac: " << '\n';
    cin >> ac;

    cout << "cin.good() = " << cin.good() << '\n';
    cout << "cin.fail() = " << cin.fail() << '\n';

    //流状态重置
    cin.clear();
    cin.ignore();
    cout << "After clear: " << '\n';
    cout << "cin.good() = " << cin.good() << '\n';
    cout << "cin.fail() = " << cin.fail() << endl;

    //


    system("pause");
    return 0;
}
