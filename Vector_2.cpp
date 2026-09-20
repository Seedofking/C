#include "iostream"
#include "vector"
using namespace std;

/*
 *Vector的构造和赋值
 *
 *构造：
 *  1.vector<T> v;                  vector<int> v//采用模板实现类实现，默认构造函数
 *  2.vector(v.begin(), v.end())    vector<int> v1(v2.begin(), v2.end());   //将v2从[begin(), end())区间中的赋值拷给v1
 *  3.vector(n, elem)               vector<int> v1(10, 20)   //构造函数将 n(10)个 elem(20)添加给自己
 *  4.vector(const vector &v)       vector<int> v1(const vector &v2);  //拷贝构造函数
 *
 * 赋值：
 *  1. v1 = v2; 使用vector库自带的重载等号赋值
 *  2. v1.assign(v2.begin(), v2.end())  //将名为 v2的 vector从[begin
 *  3. v1.assign(n, elem);  //将 n个 elem值赋值给v1
 *
 *
 */

void Print_Vector(vector<int>& v)
{
    vector<int>::iterator it = v.begin();
    for (it = v.begin(); it != v.end(); it++)
    {
        if (!v.empty())
        {
            if (it != prev(v.end())) // or (it != v.end() - 1)
            {
                cout << *it << ", ";
            }
            else
            {
                cout << *it << endl;
            }
        }
    }
}

int main()
{
    //默认构造
    vector<int> v0;
    v0.push_back(1);
    v0.push_back(2);
    v0.push_back(3);
    v0.push_back(4);
    Print_Vector(v0);
    //初始赋指定数量值构造
    vector<int> v1(10, 15);
    Print_Vector(v1);
    //迭代器区间构造
    vector<int> v2(v1.begin(), v1.end());
    Print_Vector(v2);
    //拷贝构造函数构造
    vector<int> v3(v0);
    Print_Vector(v3);

    //等号赋值
    v2 = v1;
    cout << "v2 = v1" << endl;
    Print_Vector(v2);

    //用assign的迭代器给v3拷贝成v2
    v3.assign(v2.begin(), v2.end());
    cout << "v3 = v2" << endl;
    Print_Vector(v3);

    //用 assign给 v3赋 5个 122, 数组原来的元素都会不见，只剩下 5个 122
    v3.assign(5, 122);
    cout << "v3 assign 5 x 122" << endl;
    Print_Vector(v3);


    system("pause");
    return 0;
}
