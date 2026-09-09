#include <iostream>
using namespace std;

int Value_ElseWhere = 13; //Value_ElseWhere是一个全局变量
int Val_Ew2 = 14;
const int C_Val = 11;
const int CV2 = 12;
static int Val_Inner = 1;
static int VI2 = 2;

void Show_Static(void);
int *Creat_Arr(const int size);
void Assign_Arr(int *arr, int size);
void Print_Arr(int *arr, int size);

int main()
{
    int num1, num2;

    cout << "程序运行前: 代码转为二进制后放在代码区, 由操作系统管理; 全局变量、静态变量、常量放在全局区" << endl;
    cout << "程序运行后: 函数的参数、局部变量放在栈区, 由编译器分配; 程序员分配的内存放堆区, "
            "若程序员不释放则程序结束时由操作系统回收"
         << endl;

    cout << "局部变量a, b的地址为: " << &num1 << " ; " << &num2 << endl;
    Show_Static();

    int *p = NULL;
    p = new int(10);
    //用 new在堆区申请了大小为 int的内存，其值定义为 10，但其返回的值并非 10而是其地址，由指针接收
    cout << "new申请的地址为: " << p << endl;
    cout << "new存放的值为: *p = " << *p << endl;
    //delete p;
    //释放指针内存, 但是如果在这里释放，这里就会标记为空闲，后面的 arr依然会使用 p之前的地址
    int size;
    int *arr;
    cout << "请定义数组的大小: " << endl;
    cin >> size;

    arr = Creat_Arr(size);
    Assign_Arr(arr, size);
    cout << "堆区数组首地址为: " << arr << endl;
    Print_Arr(arr, size);

    delete p;
    delete[] arr; //释放数组内存要加[]

    system("pause");
    return 0;
}

void Show_Static(void)
{
    static int a, b;
    const int c = 2, d = 3;

    cout << "局部常量a, b的地址为: " << &c << " ; " << &d << endl;
    cout << "静态局部变量a, b的地址为: " << &a << " ; " << &b << endl;
    cout << "静态全局变量a, b的地址为: " << &Val_Inner << " ; " << &VI2 << endl;
    cout << "全局常量a, b的地址为: " << &C_Val << " ; " << &CV2 << endl;
}

int *Creat_Arr(const int size)
{
    int *p = new int[size]; //C++允许使用变量定义数组
    //此处的 new int[10] 与 new int(10) 含义不同，前者的 10表示申请内存所指的值为 10，后者指的是申请了大小为 10 int的数组
    return p;
}

void Assign_Arr(int *arr, int size)
{
    //数组在传入函数时退化为指针，其长度信息缺失，需要在传参时传入大小
    // int size = sizeof(arr) / sizeof(arr[0]); 这样无法计算出数组大小，因为 sizeof(arr)中 arr本质指针，必为 8字节
    int i;

    for (i = 0; i < size; i++)
    {
        arr[i] = i + 10;
    }
}

void Print_Arr(int *arr, int size)
{
    // int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    for (i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}