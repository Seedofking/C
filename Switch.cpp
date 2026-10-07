#include <stdio.h>

int main(void)
{
    int score_level;
    printf("请输入等级(1~4): ");
    scanf("%d", &score_level);

    switch (score_level)
    {
    case 1:
        printf("优秀\n");
        break; // break 跳出switch，不继续往下执行
    case 2:
        printf("良好\n");
        break;
    case 3:
        printf("及格\n");
        break;
    case 4:
        printf("不及格\n");
        break;
    default: // 所有case都不匹配时执行
        printf("输入的等级无效\n");
        break;
    }

    for (int i = 1; i <= 4; i++)
    {
        static int n = 1; //带有初始化的static变量只有在进循环的第一次重置为1
        //n = 1;  如果加上这句，因为这是普通赋值语句，那这个static变量也会每次进循环都重置为1
        int m = 1; //普通变量每次进循环都会重置为1

        printf("n = %d\n", n);
        printf("m = %d\n", m);

        n++;
        m++;
    }


    return 0;
}
