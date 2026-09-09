#include <iostream>
#include "Class_1_App.h"
using namespace std;

int main()
{
    Point p1;
    int px, py, chpx, chpy;

    Circle c1, c2;
    int c1x, c1y, c1r, chc1x, chc1y, chc1r;
    int c2x, c2y, c2r, chc2x, chc2y, chc2r;

    cout << "设置一个点: (x, y)" << endl;
    cin >> px >> py;
    p1.Set_Point_X(px);
    p1.Set_Point_Y(py);

    cout << "设置第一个圆: (x, y ,r)" << endl;
    cin >> c1x >> c1y >> c1r;
    cout << "设置第二个圆: (x, y, r)" << endl;
    cin >> c2x >> c2y >> c2r;

    c1.Set_Cir(c1, c1x, c1y, c1r);
    c2.Set_Cir(c2, c2x, c2y, c2r);

    cout << "查看第一个点的坐标: " << endl;
    p1.Get_Point(chpx, chpy);
    cout << endl;

    cout << "查看第一个圆的参数: " << endl;
    c1.Get_Cir(chc1x, chc1y, chc1r);
    cout << "查看第二个圆的参数: " << endl;
    c2.Get_Cir(chc2x, chc2y, chc2r);
    cout << endl;

    cout << "点与第一个圆的关系: " << endl;
    c1.P2C_Rel(p1);
    cout << endl;

    cout << "两个圆之间的关系: " << endl;
    c1.C2C_Rel(c2);
    cout << endl;

    system("pause");
    return 0;
}