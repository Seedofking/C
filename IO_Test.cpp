#include <iostream>
//表示使用 input / ouput 输入/输出数据流
#include <cstdint>
using namespace std;

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

    system("pause");
    return 0;
}
