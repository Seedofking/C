#include <iostream>
using namespace std;

class man
{
public: //public下的属性和操作可以被类外和类内使用
    void Set_Name(const char *name) { Name = name; }
    const char *Get_Name(void) { return Name; }
    //实现可读可写操作

    int Get_Age(void) { return Age; }
    //只读

    void Set_Rank(int rank) { Rank = rank; }
    //只写

protected: //protected类外不可访问，类内和子类可以访问
    const char *Name;

private: //private类外和子类不可访问，类内可以访问
    int Age = 19;

public:
    int Rank;
};

int main()
{
    man Me;
    int The_Age;
    const char *The_Name;

    Me.Set_Name("C");
    The_Name = Me.Get_Name();
    The_Age = Me.Get_Age();
    Me.Set_Rank(1);

    cout << "The_Name: " << The_Name << endl;
    cout << "The_Age: " << The_Age << endl;
    cout << "Rank: " << Me.Rank << endl;

    system("pause");
    return 0;
}