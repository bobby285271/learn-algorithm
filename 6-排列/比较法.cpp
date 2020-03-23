#include <stdio.h>
void arrange(int, int, int[]); //应用于除首位之外的数位的排列函数

const int n = 4;                    //n是选择用于排列的数的个数
const int number[n] = {1, 2, 3, 4}; //存放用于排列的数

int cnt = 0; //cnt用于计数共有多少种的排列方式

int main()
{
    int m, pos = 1;
    printf("位数：");
    scanf("%d", &m);
    int digit[m]; //digit用于存每个数位的数

    for (int i = 0; i < n; i++)
    {
        digit[0] = number[i]; //首位排列
        if (m == 1)
        {
            printf("%d\n", digit[0]);
        }
        else
        {
            arrange(m, pos, digit);
        }
    }
    printf("共有%d种的排列方式", cnt);
    return 0;
}

//应用于某个数位（除去首尾位）的排列函数
//pos为当前正在排列的数位位置
void arrange(int m, int pos, int digit[])
{

    for (int i = 0; i < n; i++)
    {
        digit[pos] = number[i];
        for (int j = 0; j < pos; j++) //j是当前位前面的位
        {
            if (digit[j] == digit[pos]) //此处两数位一一比较，检测某数是否用过
            {
                i++;
                digit[pos] = number[i];
                j = -1; //每当发现某数用过后，就重头开始检测
                if (i == n)
                    return;
            }
        }
        if (pos == m - 1)
        {
            cnt++;
            for (int i = 0; i < m; i++) //输出
                printf("%d", digit[i]);
            printf("\n");
        }
        else
            arrange(m, pos + 1, digit);
    }
    return;
}
