#include <stdio.h>

int main()
{
    int i, j, a[100][100], n, k = 1;
    scanf("%d", &n);        //输出上三角
    for (i = 0; i < n; i++) //先按照一般的数组顺序对数组进行赋值
        for (j = 0; j <= i; j++)
        {
            if (i % 2 == 0)
                a[i - j][j] = k++; //偶数行，往上加一 (注意数组下标的设计）
            else
                a[j][i - j] = k++; //奇数行，往下加一 (注意数组下标的设计）
        }
    for (i = n; i < 2 * n; i++) //输出下三角  (注意数组下标的设计）
        for (j = 1; j < 2 * n - i; j++)
        {
            if (i % 2 == 0)
                a[n - j][i - n + j] = k++; //同理
            else
                a[i - n + j][n - j] = k++; //同理
        }
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j >= 0; j--)
            printf("%4d%c", a[i][j], j == 0 ? '\n' : ' '); //此时按照正确的顺序进行蛇形矩阵的输出
    }
    return 0;
}
