#pragma once //保证头文件被多个 #include的时候只被编译一次

/*
pragma 的意思是指令、编译注释，其意义为告诉编译器后面是编译器需要执行的指令，比如 once就是只编译一次

效果同传统文件守卫
#ifndef CLASS_1_APP_H
#define CLASS_1_APP_H
//
需定义内容
//
#endif

#ifndef 的意思是 if not define 如果没有定义，就会执行 #ifndef -> #endif 之间的东西

#define CLASS_1_APP_H 的意思是将 CLASS_1_APP_H定义成一个宏，以后就认住这个名字作为 ifndef的判断
名字是随便取的，可写成小写也可以与文件名字母不同，但是一般约定宏都用全大写以避免跟变量冲突，且守卫宏与文件同名

#endif 作为 #ifndef的结束，标志条件编译区域到此截止
*/

//在头文件中类需要留着成员属性、变量、函数声明，但不需要函数的实现

#include <iostream>
#include <cmath>
using namespace std;

//点类
class Point
{
protected:
    int Point_X;
    int Point_Y;

public:
    //设置点 x坐标
    void Set_Point_X(int x);
    //设置点 y坐标
    void Set_Point_Y(int y);

    //获取点 x坐标
    int Get_Point_X();
    //获取点 y坐标
    int Get_Point_Y();
    //获取点的 x、y坐标
    void Get_Point(int &x, int &y);
    //比较两个点是否相同
    bool Point_Is_Same(Point &c);
    //计算两个点之间距离的平方
    int Point_D(Point &c);
};

//圆类
class Circle
{
protected:
    Point Cir_Center;
    int Cir_R;

public:
    //设置圆的半径
    void Set_Cir_R(int r);
    //获取圆的参数
    void Get_Cir(int &x, int &y, int &r);
    //设置圆的参数
    void Set_Cir(Circle &cir, int x, int y, int r);
    //比较点与圆的位置关系
    void P2C_Rel(Point c);
    //比较圆与圆的位置关系
    void C2C_Rel(Circle cir);
};
