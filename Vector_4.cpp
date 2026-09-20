#include "iostream"
#include "vector"
using namespace std;

/*
 *vector插入和删除
 *  1.push_back(elem);  尾部插入元素
 *  2.pop_back();   尾部删除最后一个元素
 *  3.insert(const_iterator pos, ele);  //迭代器指向位置 pos的元素前面, 插入元素 elem
 *  4.insert(const_iterator pos, int count, elem);  //迭代器指向位置 pos, 插入 count个元素 elem
 *  5.erase(const_iterator pos); //迭代器指向位置 pos删除元素
 *  6.erase(const_iterator start, const_iterator end);  //删除迭代器从 start到 end之间的元素
 *  7.clear();  //删除容器中所有的元素
 *
 *vector数据存取
 *  1.at(int idx);  //返回索引idx所指的数据
 *  2.v[];   //返回索引idx所指的数据
 *  3.front();  //返回容器中第一个数据元素
 *  4.back();   //返回容器中最后一个数据元素
 *
 *vector互换容器
 *  v1.swap(v2);
 *  特性: 如果创建一个匿名临时对象vector, 使其与一个容量很大但是只存有少量数据的vector1互换, 原存有少量数据的vector1就会与临时对象互换指针,
 *  v1按照存有少量数据大小的容量换到匿名对象的vector中去, 变成新的vector1, 而匿名对象带着巨大的空容量在语句结束后被消去, 实现收缩内存效果
 *  vector<int>(v).swap(v); 解释:
 *  正常创建: v1 = vector<int>(v2) 是一个拷贝构造, v1会根据 v2数据量大小自动分配内存, 如果这时v2容量不再存在, 就可以释放无需内存
 *  而如果v1不去接 vector<int>(v2), 只有vector<int>(vx)存在的话, vector<int>(vx)会按照vx数据相配的容量拷贝到temp
 *  temp与v2互换, temp会持有v2的数据和大容量, v2会持有原来vx的数据和temp的对应容量(是拷贝后与vx数据相配的容量, 不是vx的容量),
 *  之后temp会带着v2数据和v2的大容量被释放, v2仍持有原来vx的数据和temp的对应容量
 *  而在vector<int>(v2).swap(v2)的情况中,v2就持有原来v2的数据和v2数据对应容量, 实现收缩内存
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
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.insert(v.begin() + 6, 66); //v.begin() + 6 : insert 会在指向元素前插入元素, v.begin() + 6之后会指向第7个元素
    //v.begin()一开始在第一个元素的位置, 因为pop_back删掉了3, 所以有012456->7<-, 插在7前面, 就变成 012456 66 7
    v.push_back(7);
    v.push_back(8);
    v.insert(v.begin() + 8, 3, 3); //多插了个6, 又少了个3, +8指向第9个元素8, 在8之前插入3个3
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
    v.push_back(17);

    v.erase(v.begin() + 10 + 3); //erase()会抹去指向的当个元素, 多了3, +3 后抹掉了 10
    v.erase(v.begin() + 14 + 2, v.begin() + 16 + 2); //erase抹掉了[14, 16)的数, 包含了begin但不包含end指向元素

    Print_Vector(v);

    cout << "v.at(1) = " << v.at(1) << ", v.at(2) = " << v.at(2) << endl;
    cout << "v[0] = " << v[0] << ", v[2] = " << v[2] << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;

    vector<int> v1(13000); //

    for (int i = 0; i < 10000; ++i)
    {
        v1[i] = i; //如果v1是空vector, 在被扩展之前直接通过下标访问的话会越界, 光reserve也是不能访问的
    }
    cout << "v1.capacity = " << v1.capacity() << endl;
    v1.erase(v1.begin() + 5, v1.end());
    cout << "After erase: " << endl;
    cout << "v1.capacity = " << v1.capacity() << endl;
    cout << "After swap: " << endl;
    vector<int>(v1).swap(v1);
    cout << "v1.capacity = " << v1.capacity() << endl;
    Print_Vector(v1);


    system("pause");
    return 0;
}
