#include <stdio.h>
#include <string.h>
#define LENGTH 10000 //这个10000是自己想要的在一定的范围内的素数，要根据题意
int main()
{
    int n, p = 0, i;
    int bad_boy[LENGTH];                      //要判断的数组
    int good_boy[LENGTH];                     //确定是素数的数组
    memset(bad_boy, 0, sizeof(int) * LENGTH); //把数组清零，头文件是 <string.h>
    for (i = 2; i <= 100; i++)                //100就是10000开的根号的值
    {
        if (bad_boy[i] == 0)
        {
            good_boy[p++] = i;                      //再来一个数组把素数给装起来
            for (int j = 2 * i; j <= 10000; j += i) //排除1000000的范围内所有上面已经确定的素数的倍数
                bad_boy[j] = 1;                     //直接让他们等于1，就可以避免在上面的为0的判断中乱入
        }
    }
    for (; i <= 10000; i++) //这边是完成它未尽的判断事务，要把根号外的数给判断完
        if (bad_boy[i] == 0)
            good_boy[p++] = i;
    for (int i = 0; i < p; i++) //输出10000范围内的所有素数
    {
        printf("%d ", good_boy[i]);
    }
    printf("\n");
    return 0;
}
