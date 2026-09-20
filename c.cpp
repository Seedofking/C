#include<stdio.h>

int main()
{
    int a = 0;


    int* p = &a;
    int b = *p;
    b = a;
    printf("%d", b);

    return 0;
}
