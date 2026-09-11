#include <iostream>
using namespace std;

/*
 *友元
 *使用友元可以让外部的类或者函数访问类内的私有变量
 *类似于发一个可访问证明，被认定为友元的函数或类获得访问类内私有变量的权限, 但给别人发友元权限的类并不会改变接收函数或类的任何行为
 *A{friend void （B::）func}func仍然是全局函数，或者另一个类的成员函数，加了这句话对于A和B其他行为无影响，只是func可以使用A的私有变量
 *仅此而已
 *
 *写法
 *1.friend void Line::func  Line::是作用于修饰符，必须跟函数名绑定在一起
 *
 *用法
 *1.friend void Func(); 友元全局函数
 *2.friend void Cir:: Func();   友元成员函数
 *3.friend class Cir;   友元类
 *
 *特性
 *1.友元全局函数可以通过a.x访问私有变量
 *2.友元成员函数如果要使用友元特性访问另一个类的私有成员，函数只可在类里面声明，定义需要在外部，
 *  因为虽然A是B的友元，但是这条需要在A定义完成后才生效，所以A里面的函数是用不了B的私有成员的
 *3.友元类的所有成员函数都有友元成员函数的特点，但是依然要在类的外面写函数的实现，而且也不可以在类里面直接访问a.x
 *4.friend不受public, protected, private的影响，一般写在public下
 *
*/
class Point;
class Line;

class Cir
{
private:
    Point* Center_Point = nullptr;
    //因为顺序问题，类的前面只有另一个类的声明，因为类的类型在被定义前不完整，大小未知，是不可以用另一个类的声明创建一个类的
    //可以用这一个声明类的指针，指针在类型不完整时依旧可以用来代表这个类，之后用指针可以访问该类的函数，这个指针也可以享受友元特性
    int R = 0;

public:
    Cir();
    ~Cir();
    void Print_Center_Point(); //需要使用友元类特性，实现写在外面
    // {
    //     cout << "Center_Point_X" << Point.x << endl;
    //     cout << "Center_Point_Y" << Point.y <<endl;
    // }

    void Set_Center_Point(const Point& p); //需要使用友元类特性，实现写在外面
    // {
    //     Get_Point(x,y);
    // }
    void Print_Cir();
};

class Line
{
private:
    Point* Orign_Point = nullptr;
    //如果想让Line用上Point的友元函数，Line就要在Point的前面，但是这样Line就只能用Point的指针来访问Point
    int Length = 0, Angle = 0;

public:
    Line();
    ~Line();
    void Line_Get_Point(const Point& po, int& x1, int& y1);
    void Line_Set_Point(const Point& po);
    void Print_Line(const Line& l);
};


class Point
{
private:
    int x, y;

protected:
    friend class Cir;

public:
    void Set_Point(int x, int y);
    friend void Line::Line_Get_Point(const Point& po, int& x1, int& y1); //作用是点给线发友元特性，这个函数仍然是属于线的
    friend void Line::Line_Set_Point(const Point& po);
};


//函数实现
//构造函数析构函数
void Point::Set_Point(int x1, int y1)
{
    this->x = x1;
    this->y = y1;
}

Line::Line()
{
    Orign_Point = new Point; //指针申请了堆内存之后就不要再指向别处，会造成内存泄漏
    Length = 10;
    Angle = 30;
}

Line::~Line()
{
    delete Orign_Point; //清理指针内存
}

void Line::Line_Get_Point(const Point& po, int& x1, int& y1)
{
    x1 = po.x;
    y1 = po.y;
}

void Line::Line_Set_Point(const Point& po)
{
    Orign_Point->x = po.x;
    Orign_Point->y = po.y;
}

void Line::Print_Line(const Line& l)
{
    int xx, yy;
    Line_Get_Point(*l.Orign_Point, xx, yy);
    cout << "Line_Orign_Point: (" << xx << ", " << yy << ")" << endl;
    cout << "Length: " << l.Length << endl;
    cout << "Angle: " << l.Angle << endl;
}

Cir::Cir()
{
    Center_Point = new Point;
    // Center_Point = &po;  不可以这样用，申请在堆的指针指向别处就会造成内存泄漏，直接访问其数据即可
    R = 5;
}

Cir::~Cir()
{
    delete Center_Point;
}

//友元类
//由于Cir是Point的友元，所以Cir作用域下的成员函数可以使用传入的点类p的私有变量p.x和p.y
void Cir::Set_Center_Point(const Point& p)
{
    Center_Point->x = p.x;
    Center_Point->y = p.y;
}

//
void Cir::Print_Center_Point()
{
    cout << "Center_Point_X: " << Center_Point->x << endl;
    cout << "Center_Point_Y: " << Center_Point->y << endl;
}

void Cir::Print_Cir()
{
    Print_Center_Point();
    cout << "R = " << R << endl;
}

int main()
{
    int cx = 0, cy = 0, lx = 0, ly = 0, px = 0, py = 0;
    Point P1, P2, P3;

    cout << "Input Cir_Center_Point: " << endl;
    cin >> cx >> cy;
    P1.Set_Point(cx, cy);
    Cir C1;
    C1.Set_Center_Point(P1);

    cout << "Input Line_Center_Point: " << endl;
    cin >> lx >> ly;
    P2.Set_Point(lx, ly);
    Line L1;
    L1.Line_Set_Point(P2);

    cout << "Input a Point" << endl;
    cin >> px >> py;
    P3.Set_Point(px, py);

    C1.Print_Cir();
    L1.Print_Line(L1);

    system("pause");
    return 0;
}
