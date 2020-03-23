#include <stdio.h>
void arrange(int, int, int[], struct FLAG); //应用于某个数位的排列函数
struct FLAG copy(struct FLAG);

const int n = 4;                    //n是选择用于排列的数的个数
const int number[n] = {1, 2, 3, 4}; //存放用于排列的数
//在number中升序放置数字即可达到最后输出升序出排列方式的效果
int cnt = 0; //cnt用于计数共有多少种的排列方式

/*array用于记录某位的数字是否有被用过 
第i位的值代表用于排列的数字number[i]的使用情况，0为未使用过，1为使用过*/
/*将数组放在结构体是为了每次能在当前数位的排列函数中
将数组的副本传递到下一个数位的排列函数,而不是传递指针 */
struct FLAG
{
    int array[n];
};
int main()
{
    int m, pos = 0;
    struct FLAG flag;

    for (int i = 0; i < n; i++)
        flag.array[i] = 0; //相当于给flag的数组全部初始化为0

    printf("位数：");
    scanf("%d", &m); //m是数位的个数，相当于从n个数挑m个进行排列

    int digit[m]; //digit用于存每个数位的数

    arrange(m, pos, digit, flag); //给定m个数位，有n个数进行的排列
    //相当于从n个数中选出m个进行的排列

    printf("共有%d种排列方式", cnt);
    return 0;
}

//应用于某个数位的排列函数
//pos为当前正在排列的数位位置
void arrange(int m, int pos, int digit[], struct FLAG flag)
{
    int i;
    if (pos == m) //到最后一位结束后，输出
    {
        cnt++;
        for (int i = 0; i < m; i++)
            printf("%d", digit[i]);
        printf("\n");
        return;
    }
    if (pos == 0 && number[0] == 0)
        i = 1; //首位不能为0
    else
        i = 0;
    for (; i < n; i++)
    {
        if (flag.array[i])
            continue; //若某个数字被使用过，则直接跳过该数字
        digit[pos] = number[i];
        flag.array[i] = 1; //记录某数字被使用过
        arrange(m, pos + 1, digit, copy(flag));
        flag.array[i] = 0; //还原某数字使用情况
    }
}

//将当前记录数字使用情况的数组复制，并传入下一个数位的排列函数
struct FLAG copy(struct FLAG flag)
{
    struct FLAG new_flag;
    new_flag = flag;
    return new_flag;
}
