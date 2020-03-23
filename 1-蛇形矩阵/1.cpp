#include <stdio.h>
int main()
{
    int n, i = 0, j = 0, cnt = 0, a[100][100], k = 2;
    scanf("%d", &n);
    a[0][n - 1] = 1, a[0][n - 2] = 2;
    j = n - 2; //从2开始，可以避免后面在判断循环终止时的一系列麻烦
    while (i != n - 1 || j != 0)
    { //只要不是最后一个数，就开始循环
        if (cnt == 0)
        {
            do
            {
                a[++i][++j] = ++k;
            } while (i != n - 1 && j != n - 1); //没有到达边框都可以斜向下加一
            cnt = !cnt;
        }
        else
        {
            do
            {
                a[--i][--j] = ++k;
            } while (i != 0 && j != 0); //没有到达边框都可以斜向上加一
            cnt = !cnt;
        }
        if ((i == 0 || i == n - 1) && j > 0)
            a[i][--j] = ++k; //进行边框的赋值
        else if ((j == 0 || j == n - 1) && i < n - 1)
            a[++i][j] = ++k; //进行边框的赋值
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d%c", a[i][j], j == n - 1 ? '\n' : ' '); //右对齐输出
    }
    return 0;
}
