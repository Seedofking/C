#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
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
 *  write(); 输出字符串          getline( , , ); 输入字符串  *1:字符流cin或ss, *2:要存进的字符串, (*3):读到什么停下, 默认'\n'
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
 *      stringstream ss1("test");
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
 *  ss.str(""); 将流内部的字符重置为空
 *
 *  No.6 流字符转换, 字符拼接, 字符截取
 */

//已知分隔符号分割数据
class Cut
{
public:
    template <typename T>
    static void StrCut(const string& s, char c, vector<T>& v) //(需分割的字符串, 分隔符, 需传出的数组类型)
    {
        string temp;
        stringstream ss(s);

        while (getline(ss, temp, c))
        {
            if (temp.empty())
            {
                continue; //如果有两个分隔符c连在一起, 读出来的temp是空的, 应跳过
            }
            stringstream sstemp(temp); //使用字符流可以进行类型识别的特性, 靠传入的vector模板识别要放入的类型
            T val;
            sstemp >> val;
            v.push_back(val);
        }
    }
};


int main()
{
    //字符流的初始化
    cout << "字符流的初始化" << endl;
    stringstream ss;
    string s1 = "stringstream yes! ";
    string s4 = "OK";
    int a = 114;
    //字符流的输入
    ss << s1 << a << s4;
    cout << ss.str() << endl;

    //字符流输出, 默认使用" "自动分割
    cout << "字符流输出, 默认使用空格自动分割" << endl;
    string s2, s3;
    ss >> s2;
    cout << s2 << '\n';
    ss >> s3;
    cout << s3 << endl;

    //流状态查看
    cout << "流状态查看" << endl;
    int ac;
    cout << "cin.good() = " << cin.good() << '\n';
    cout << "cin.fail() = " << cin.fail() << '\n';
    cout << "cin.eof = " << cin.eof() << '\n';

    cout << "cin >> int ac: " << '\n';
    cin >> ac;

    cout << "cin.good() = " << cin.good() << '\n';
    cout << "cin.fail() = " << cin.fail() << '\n';

    //流状态重置
    cout << "流状态重置" << endl;
    cin.clear();
    cin.ignore();
    cout << "After clear: " << '\n';
    cout << "cin.good() = " << cin.good() << '\n';
    cout << "cin.fail() = " << cin.fail() << endl;

    //小数点与科学计数法表示
    cout << "小数点与科学计数法表示" << endl;
    double heng = 114514.1919810;
    long long num = 12345678900000;

    cout << "heng = " << heng << endl;
    cout << fixed << setprecision(3) << "heng(f3) = " << heng << endl;
    cout << fixed << setprecision(7) << "heng(f7) = " << heng << endl;

    //需要手动清除fixed标记
    cout << resetiosflags(ios::fixed) << setprecision(7) << "heng(7) = " << heng << endl;
    cout << setiosflags(ios::scientific) << heng << endl;

    cout << setiosflags(ios::scientific) << num << endl; //整数不会用科学计数

    //格式输出右对齐矩阵
    cout << "格式输出右对齐矩阵" << endl;
    int n;
    cout << "Enter the size of the Matric: " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        stringstream ss;
        string s;

        for (int j = 1; j <= i; j++)
        {
            static int nnum = 1;
            if (nnum < 10)
            {
                ss << "0";
            }
            ss << nnum;
            nnum++;
        }
        s = ss.str(); //setw不能一次一次用，不然就相当于制表符，所以用字符流拼成一个字符串之后再输出
        cout << right << setw(2 * n) << setfill('*') << s << endl; //setfill()要是字符'', 不setfill默认填空格
        //right / left 来控制左右对齐，不设置默认右对齐
    }

    //字符和整行输入
    cout << "字符和整行输入" << endl;
    char c;
    cout << "Enter a char: " << endl;

    cin.ignore();
    cin.get(c);

    cout.put(c);
    cout << endl;

    string sas;

    //重新利用ss前需要先清除eof标志位，再把里面的内容覆盖为空
    ss.clear();
    ss.str("");

    cout << "Enter a line: " << endl;
    cin.ignore();

    getline(cin, sas);
    ss << sas;

    cout << "Enter a line: " << endl;
    //前一个getline()会直接吃掉换行，不用cin.ignore

    getline(cin, sas); //两个getline会直接覆盖sas的原有内容
    ss << sas;

    cout << "getline(cin, s) then getline(cin, s) would cover the s with the second getline" << endl;
    cout << sas << endl;
    cout << ss.str() << endl; //使用字符流可以把多次getline拼在一起

    //字符流实现字符串拼接和类型转换
    cout << "字符流实现字符串拼接和类型转换" << endl;
    stringstream da;
    int a1, a2;
    string st1;

    cout << "Enter number1: " << endl;
    cin >> a1;
    cout << "Enter string: " << endl;
    cin >> st1;
    cout << "Enter number2: " << endl;
    cin >> a2;

    //使用字符流将整型的a1, a2和字符串st1拼在一起，并且把整形转为字符串
    da << a1 << st1 << a2;
    cout << da.str() << endl;

    //使用字符流实现字符分割
    //1.已知字符流形式用空格自动分割为指定对象
    cout << "1.已知字符流形式用空格自动分割为指定对象" << endl;
    string stdd = "strv 122 b+";
    stringstream sd(stdd); //拷贝构造字符流，将stdd拷进sd
    string tk, md;
    int n3; //输出流会根据接受变量的类型自动调整输出的变量类型，如果类型不能转换会报错


    sd >> tk >> n3 >> md;
    cout << "tk = " << tk << endl;
    cout << "n3 = " << n3 << endl;
    cout << "md = " << md << endl;

    //2.未知字符流长度用空格自动分割为某类型对象
    cout << "2.未知字符流长度用空格自动分割为某类型对象" << endl;
    string td;

    cin.ignore();
    cout << "Enter the number separated by space, end with Enter" << endl;
    getline(cin, td);
    vector<int> v;

    stringstream tds(td);
    while (!tds.eof()) //意思是当tds还没有到结束的时候，就会一直执行循环，把tds用空格分开的一次次放进Onenum
    {
        string Onenum;
        tds >> Onenum;
        v.push_back(stoi(Onenum)); //stoi会适用于把字符串数字转为整型数字
    }

    for (int x : v)
    {
        cout << x << ", ";
    }
    cout << " Vector end" << endl;

    //3.未知字符流形式，用单个未知分隔符分割数据
    cout << "3.未知字符流形式，用单个未知分隔符分割数据" << endl;
    string ll;
    // cin.ignore(); 前一个是getlline就不要ignore
    cout << "Please enter number separated by a punctuation, end with Enter: " << endl;
    getline(cin, ll);
    stringstream lls(ll);

    int n5; //用n5来接收整型数据
    char dot; //用char dot来每次固定接收一个字符, 消除分隔符
    vector<int> nv;

    while (lls >> n5) //lls成功读到第一个整数给n5, 进循环
    {
        nv.push_back(n5);
        lls >> dot; //进循环之后, 马上又消除一个字符dot, lls的流指针移到下一个字符, 接下来又是数字, 所以循环继续读数字
    }
    //读到最后的时候, 循环会结束, 结束时会让lls.eof() = 1;
    cout << "lls.eof() = " << lls.eof() << endl;


    for (int x : nv)
    {
        cout << x << ", ";
    }
    cout << " Vector end" << endl;

    //使用while (cin >> x)实现多次数字输入
    cout << "使用while (cin >> x)实现多次数字输入" << endl;
    int m1;
    vector<int> mv;

    cout << "Please enter number with Enter, end with not number: " << endl;
    while (cin >> m1)
    {
        mv.push_back(m1);
        cout << "go on: " << endl;
    }
    cin.clear(); //读到最后cin会读不到数置fail = 1
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); //后面输入的int读不了的字符会残留在缓冲区, 要整行丢弃

    for (int x : mv)
    {
        cout << x << ", ";
    }
    cout << " Vector end" << endl;

    //使用while (cin >> s)实现多次字符串输入
    cout << "使用while (cin >> s)实现多次字符串输入" << endl;
    string ssss;
    vector<string> sv;

    cout << "Please enter string, end with Ctrl+Z, and keep input to go on: " << endl;
    while (cin >> ssss)
    {
        sv.push_back(ssss);
        cout << "go on: " << endl;
    }
    cin.clear(); //windows按下 Ctrl+Z 会置eof = 1, 要清除标志位
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //EOF也会直接清除\n, 所以当eof会清除\n的时候, ignore读不到\n就回原地等, 直到输入下一个\n
    //当上一次缓冲区置了eof的时候,下一次cin读到了\n, 尝试跳过空白时又会立马置eof, 所以需要cin.ignore()清掉\n
    //Ctrl+Z之后要多按一次enter或者输入什么东西才能让

    for (string s : sv)
    {
        cout << s << ", ";
    }
    cout << " Vector end" << endl;


    //4.指定分隔符分割字符串, 并将数据放入指定类型的vector
    cout << "4.指定分隔符分割字符串, 并将数据放入指定类型的vector" << endl;
    cout << "Please enter the number separated by ',' end with Enter: " << endl;
    string s21;
    getline(cin, s21);
    vector<int> v3;

    Cut::StrCut(s21, ',', v3);

    for (int x : v3)
    {
        cout << x << ", ";
    }
    cout << " Vector end" << endl;

    cout << "Please enter the string separated by ',' end with Enter: " << endl;
    string s31;
    getline(cin, s31);
    vector<string> v4;

    Cut::StrCut(s31, ',', v4);

    for (string x : v4)
    {
        cout << x << ", ";
    }
    cout << " Vector end" << endl;


    system("pause");
    return 0;
}

