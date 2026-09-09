#include "Class_1_App.h"

//在 C++主文件中，类只需要写函数实现，不需要写变量，变量直接从类里使用即可
//Point:: 表示在 Point作用域下的成员函数，这样才能使用头文件中类里面的成员

//点的实现
//设置点 x坐标
void Point::Set_Point_X(int x) { Point_X = x; }
//设置点 y坐标
void Point::Set_Point_Y(int y) { Point_Y = y; }
//获取点 x坐标
int Point::Get_Point_X() { return Point_X; }
//获取点 y坐标
int Point::Get_Point_Y() { return Point_Y; }
//获取点的 x、y坐标
void Point::Get_Point(int& x, int& y)
{
    x = Point_X;
    y = Point_Y;

    cout << "点的x坐标为: " << x << endl;
    cout << "点的y坐标为: " << y << endl;
}

//比较两个点是否相同
bool Point::Point_Is_Same(Point& c) //类和结构体一样，传入一个指针或者引用可以避免产生拷贝占用内存
{
    if (Point_X == c.Point_X && Point_Y == c.Point_Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//也可写全局函数
bool Point_IS_Same(Point& c1, Point& c2)
{
    int c1x = c1.Get_Point_X();
    int c2x = c2.Get_Point_X();
    int c1y = c1.Get_Point_Y();
    int c2y = c2.Get_Point_Y();

    if (c1x == c2x && c1y == c2y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//计算两点间距离的平方
int Point::Point_D(Point& c)
{
    int d;
    d = (Point_X - c.Point_X) * (Point_X - c.Point_X) + (Point_Y - c.Point_Y) * (Point_Y - c.Point_Y);
    return d;
}

//获取圆的参数
void Circle::Get_Cir(int& x, int& y, int& r)
{
    x = Cir_Center.Get_Point_X();
    y = Cir_Center.Get_Point_Y();
    r = Cir_R;

    cout << "圆的参数为：" << "(" << x << ", " << y << ") r = " << r << endl;
}

//设置圆的参数
void Circle::Set_Cir(Circle& cir, int x, int y, int r)
{
    cir.Cir_Center.Set_Point_X(x);
    cir.Cir_Center.Set_Point_Y(y);
    cir.Cir_R = r; //在类的作用域里，传入本类参数的成员函数可以直接使用 protected的成员
}

//比较点与圆的位置关系
void Circle::P2C_Rel(Point c)
{
    int d = c.Point_D(Cir_Center);
    if (d < Cir_R * Cir_R)
    {
        cout << "点在圆内" << endl;
    }
    else if (d == Cir_R * Cir_R)
    {
        cout << "点在圆上" << endl;
    }
    else
    {
        cout << "点在圆外" << endl;
    }
}

//比较圆与圆的位置关系
void Circle::C2C_Rel(Circle cir)
{
    int d;
    int flag;
    //开平方根
    d = sqrt(Cir_Center.Point_D(cir.Cir_Center));

    //内含
    if (d < Cir_R || d < cir.Cir_R)
    {
        flag = 1;
    }
    //内切
    if (d + Cir_R == cir.Cir_R || d + cir.Cir_R == Cir_R)
    {
        flag = 2;
    }
    //相交
    if (d < cir.Cir_R + Cir_R)
    {
        flag = 3;
    }
    //外切
    if (d == cir.Cir_R + Cir_R)
    {
        flag = 4;
    }
    //相离
    if (d > cir.Cir_R + Cir_R)
    {
        flag = 5;
    }
    //输出
    switch (flag)
    {
    case 1:
        cout << "内含" << endl;
        break;
    case 2:
        cout << "内切" << endl;
        break;
    case 3:
        cout << "相切" << endl;
        break;
    case 4:
        cout << "外切" << endl;
        break;
    case 5:
        cout << "相离" << endl;
        break;
    }
}
