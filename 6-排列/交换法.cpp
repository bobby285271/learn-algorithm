#include <stdio.h>

const int n = 4;                    //n是选择用于排列的数的个数
const int number[n] = {1, 2, 3, 4}; //存放用于排列的数
int digit[n];                       //全排列的数位数量和用于排列的数的个数相等

int cnt = 0;

void swap(int *, int *);
void arrange(int, int);

int main()
{
    for (int i = 0; i < n; i++)
        digit[i] = number[i];
    arrange(n, 0);
    printf("共有%d种排列", cnt);
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void arrange(int n, int pos)
{
    if (pos == n - 1) //到最后一位时
    {
        cnt++;
        for (int i = 0; i < n; i++)
            printf("%d", digit[i]);
        printf("\n");
    }
    else
    {
        for (int i = pos; i < n; i++) //i是当前位pos后面的位
        {
            swap(digit + i, digit + pos); //digit[i]和digit[pos]交换
            arrange(n, pos + 1);          //进入到下一位的排列
            swap(digit + i, digit + pos); //还原交换的两数
        }
    }
}
