#include <stdio.h>
#define N 1000
int main()
{
    int n, i;
    int a[N];
    scanf("%d", &n);
    int all = -1;
    for (i = 0; i < n; i++)
    {
        int s = 0;
        scanf("%d", &a[i]);
        int x = a[i];
        while (x)
        {
            s++;
            x /= 10;
        }
        if (s > all)
        {
            all = s;
        } //找到最大位数
    }
    int lo = 1; //排序从1（个位）开始
    while (lo <= all)
    {
        int k = 1;
        int Lo = lo;
        while (--Lo)
        {
            k = k * 10; //用来处理元素的工具
        }
        int A[n + 3] = {0};
        int j, c = 0;
        for (i = 9; i >= 0; i--)
        {
            for (j = 0; j < n; j++)
            {
                if ((a[j] / k) % 10 == i) //对每一个元素，先/k使其最后一位变成我们现在进行排序的位数，如我们现在要排2（十位），使123/10=12，12%10=2，2即为123的十位数。
                {
                    A[c++] = a[j]; //基数大元素的先放进空白数组。
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            a[i] = A[i];
        } //空白数组中的数据回到原数组
        lo++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
