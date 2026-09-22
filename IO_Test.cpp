#include <iostream>
//表示使用 input / ouput 输入/输出数据流
#include <cstdint>
using namespace std;
#include<vector>

//一行多输入
#include <string>
#include <sstream>
#include <limits>

void Multi_Input(vector<int>& v)
{
    string line; //line一会用于存储从cin得到的一整行数据
    cout << "请输入若干数字，须使用空格分隔，按回车提交" << endl;
    //cin.ignore();一定要在前面有cin才可以加，读不到\n都会出问题
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');这个东西的问题是，如果前面没有换行可供读取，就永远不会结束程序
    //cin.ignore();   //这个东西的问题是，如果前面没有换行可供丢弃，就会丢弃数据
    //cin.ignore()可以忽略掉前面cin << a;等剩下的一个\n, 但是只能忽略一个，如果回车前还有空格等就会失效
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'); 可以清除回车之前的所有东西
    getline(cin, line); //getline可以实现从cin中拿到一整行的输入数据，放在line里
    stringstream ss(line); //stringstream ss(line) 可以从line中构造输入流数据给ss， 并且可以从中分割数据

    int tmp;
    while (ss >> tmp)
    {
        v.push_back(tmp);
    }
}


void Print_Vector(vector<int>& v)
{
    for (auto x : v)
    {
        cout << x << endl;
    }
}


float GPA_Turn(uint16_t score)
{
    float GPA;
    GPA = static_cast<float>(score - 50) / 10;

    return GPA;
}


int main()
{
    uint16_t score;
    float score_out = 0;

    cout << "请输入成绩: " << endl;
    //表示数据从“ 请输入成绩 ”流向cout
    cin >> score;
    //表示数据从键盘 cin 流向 score

    if (50 < score && score <= 100)
    {
        score_out = GPA_Turn(score);
        cout << "GPA = " << score_out << endl;
    }
    else
    {
        cout << "Get fucking out" << endl;
    }

    vector<int> v;
    Multi_Input(v);
    Print_Vector(v);


    system("pause");
    return 0;
}
