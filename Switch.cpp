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

    return 0;
}
