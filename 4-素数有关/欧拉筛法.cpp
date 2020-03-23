#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, kwe = 0, n;
    int bad_boy[1009];  //要判断是否为素数的数组
    int good_boy[1009]; //确定是素数的数组
    scanf("%d", &n);
    memset(bad_boy, 0, sizeof(bad_boy)); // 把数组清零，头文件是 <string.h>
    for (i = 2; i <= n; i++)
    {
        if (bad_boy[i] == 0)
        {
            good_boy[kwe++] = i; //数组元素为零，即此时数组的下标就是素数，把下标存起来
        }
        for (j = 0; j < kwe && i * good_boy[j] <= n; j++)
        {
            bad_boy[i * good_boy[j]] = 1; //是素数倍数的数，绝对不是素数，把它给筛掉
            if (i % good_boy[j] == 0)
                break;            //此操作保证了只用最小素数来筛选，从而保证筛选不会重复。例如，当i=4时， （换行）
        }                         //i%good_boy[0](也就是2）=0,如果此时不退出循环，下面就会出现 （换行）
    }                             //i* good_boy[1](也就是3）= 12，然而，当后来i自增到6时，同样可以出现 （换行）
    for (int i = 0; i < kwe; i++) //i* good_boy[0](也就是2）= 12，也就是说，把12筛选了两次。所以要在 i%good_boy[j]=0时退出循环
    {
        printf("%d ", good_boy[i]);
    }
    return 0;
}
