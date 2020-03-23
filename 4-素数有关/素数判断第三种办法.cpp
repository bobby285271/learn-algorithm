
#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if (n <= 3 && n > 1)
        return 1; //确认是素数
    if (n % 6 != 1 && n % 6 != 5)
        return 0; //不在6的倍数两边的都不是素数
    int s = (int)sqrt(n);
    for (int i = 5; i <= s; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) //为了保证速度最大化，选取6的倍数两边的数来进行衡量
            return 0;                       //能被6的倍数两边的数整除的数绝对不是素数
    }
    return 1; //其余的都是素数
}
int main()
{
    int n; //输入数据保证n大于1
    while ((scanf("%d", &n)) != EOF)
    {
        if ((isPrime(n)) == 1)
            printf("是素数\n");
        else
            printf("不是素数\n");
    }
    return 0;
}
