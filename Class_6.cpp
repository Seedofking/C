#include <iostream>
using namespace std;

/*
 *多态：
 *可以实现同一个接口，不同对象，有不同实现
 *
 *静态多态：
 *1.特点：编译阶段就确定函数地址，没有运行开销，速度快
 *2.类型：
 *  函数重载：同一个作用域，函数名相同，参数列表不同
 *  模板（泛型）
 *
 *动态多态：
 *1.特点：运行期绑定，需要使用虚表查找，有微小开销，父类先于子类构建，后于子类销毁，父类通过虚函数virtual才可以实现调用子类函数
 *2.条件：
 *  继承：子类需要公有继承父类   class Son : public Pare;
 *  父类指针/引用：指向子类    Pare *p = new Son; 指针使用->调用/ Son s; Pare* p = &s  or  Pare& ref = s; 引用使用.调用
 *  虚函数virtual：父类同名函数需要加virtual，子类需要重写该函数
 *      Pare{ virtual void Fun(){A} }   Son{ void Fun(){B} }
 *3.调用：p-> Fun(); //如果父类函数前写了virtual, 就会调用子类内重写的函数, 如果父类没写virtual，则会调用父类的
 *4.指针的意义：Ani* p = new Dog ; Ani* 内有 Virtual Speak()函数"Sound"，Dog重写了Speak()为"Bark"
 *  父类Ani类型指针的作用：知道Ani部分的内存，可以访问Ani里面定义的成员，比如可以访问Speak函数
 *  指向子类Dog后：通过父类指针访问Speak()时，因为其带有virtual，所以在开始运行时会在vptr虚函数表里面查看Dog中Speak的()定义，实现多态
 *  如果没有virtual，普通指针访问成员就会在编译器直接确定, p->Speak()会直接调用父类函数，而不会调用子类重写的Speak()
 *5.多态的作用：父类相当于通用地址手柄，指向谁就可以调用特殊化的子类函数
 *  比如创建了Ani父类，有Speak()，子类Dog, Cat, Duck有其特殊的 Speak()，以后写一个函数
 *  void Ani_Speak(Ani* ani)
 *  {
 *      ani->Speak();
 *  }
 *  就只用传入指向了子类的父类指针，把Dog, Cat, Duck传进去而不用改Ani_Speak()函数的任何代码，原代码不动就能支持新动物
 *6.协变：父子关系的类，如果其函数返回值为父子关系的指针或引用，可以触发多态
 *
 *
*/

class Ani
{
public:
    static void Let_Speak(Ani* ani)
    {
        ani->Speak();
    }

    void Move()
    {
        cout << "Ani_Move" << endl;
    }

protected:
    virtual void Speak()
    {
        cout << "Speak" << endl;
    }
};

class Dog : public Ani
{
public:
    void Speak()
    {
        cout << "Bark" << endl;
    }

    void Move()
    {
        cout << "Dog_Move" << endl;
    }
};

class Cat : public Ani
{
public:
    void Speak()
    {
        cout << "Meow" << endl;
    }

    void Move()
    {
        cout << "Cat_Move" << endl;
    }
};

int main()
{
    Ani* a1 = new Dog;
    Ani* a2 = new Cat;


    Ani::Let_Speak(a1);
    Ani::Let_Speak(a2);

    a1->Move();

    delete a1;
    delete a2;

    system("pause");
    return 0;
}
