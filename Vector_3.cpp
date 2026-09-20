#include <iostream>
#include <vector>
using namespace std;

/*
 *vector的容量和大小
 *1.empty(); 判断容器是否为空
 *2.capacity(); 查看容器的容量
 *3.size(); 查看容器中元素的个数,即大小
 *4.resize(int num); 重新指定容器的长度为 num, 若容器变长, 则用默认值 0填充新位置; 若容器变短,则超出长度的元素会被删除, 之后仍可自动扩展
 *5.resize(int num, elem); 重新指定容器长度为 num, 若容器变长, 则用num填补新位置, 否则超出的元素会被删除
 *6.reserve(int len); 容器预留 len个元素长度, 预留位置不会初始化, 在增加元素之前不可访问, 如果不预留长度,
 *  则会在构造或者增添元素时多次扩展, 预留可避免多次扩展, 数据较大时可一开始就利用 reserve预留空间
 *
 */
void Print_Vector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    vector<int> v1;
    for (int i = 0; i < 100; i++)
    {
        v1.push_back(i);
    }
    if (!v1.empty())
    {
        cout << "v1.capacity(): " << v1.capacity() << endl;
        cout << "v1.size(): " << v1.size() << endl;
    }

    v1.resize(130); //此时从100到130所有的空位都被补成了0, 大小是130个, 容量达到了200
    cout << "v1.capacity: " << v1.capacity() << endl;

    v1.resize(144, 122); //此时从131到144所有的空位都被补上122, 有14个122, 大小是144个, 容量还是200
    cout << "capacity(): " << v1.capacity() << endl;
    cout << "size(): " << v1.size() << endl;
    Print_Vector(v1);

    vector<int> v2;
    int* p = &v2[0];
    int num = 0;
    for (int i = 0; i < 10000; i++)
    {
        v2.push_back(i);
        if (p != &v2[0])
        {
            p = &v2[0];
            num++;
        }
    }
    cout << "num = " << num << endl;
    //num = 15, 说明在push_back到10000的过程中, vector的地址变了15次, 即扩展了15次内存空间

    vector<int> v3;
    v3.reserve(13000);
    p = &v3[0];
    num = 0;
    for (int i = 0; i < 20000; i++)
    {
        v3.push_back(i);
        if (p != &v3[0])
        {
            p = &v3[0];
            num++;
        }
    }
    cout << "After_Reserve_num: " << num << endl;
    //预留内存之后,push_back到20000也只重新分配了一次内存, 说明预留可以减少扩展次数

    system("pause");
    return 0;
}
