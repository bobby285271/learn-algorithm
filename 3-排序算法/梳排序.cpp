#include <stdio.h>
#define N 1000
int main()
{
    int n;          //要处理数据的大小
    int i;          //计数器
    int j;          //距离
    int a[N];       //存储数据的数组
    double k = 1.3; //距离递减值，可以是其他，但1.3测试的效果较好
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    j = n - 1;
    i = 0;
    int flag = 1; //判断是否有交换，如有交换循环还要继续，否则（部分）排序结束
    //两个条件同时满足时，才能认为数据中每一个数都被比较过并处理过
    while (j > 1 || flag == 1)
    {
        j = (j / k > 1) ? (j / k) : 1; //每循环一次让 距离/递减值，减少距离，直到为1，则退化成冒泡
        flag = 0;
        i = 0;
        //下面进行冒泡
        while (i + j < n)
        {
            if (a[i] < a[i + j])
            {
                int temp = a[i];
                a[i] = a[i + j];
                a[i + j] = temp;
                flag = 1;
            } //大到小排序，交换
            i++;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } //输出
    return 0;
}
