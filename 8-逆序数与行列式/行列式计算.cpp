#include <stdio.h>

void swap(int *, int *);
void arrange(int[], int[], int[], int, int);
void mergesort(int[], int, int);

int cnt = 0;      //cnt用于逆序数计数
int term_cnt = 0; //term_cnt用于项数计数
int ans = 0;      //ans为行列式计算结果

int main()
{
    int n;
    printf("行列式阶数：");
    scanf("%d", &n);
    int digit[n];
    int temp_digit[n]; //temp_digit是digit的临时副本，用于给归并法排序来算逆序数
    int det[n * n];
    //为方便将数组传入函数，用一维数组det存储行列式元素
    //行列式中i行j列元素为数组det中第i*n+j个元素
    printf("\n行列式：\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &det[i * n + j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        digit[i - 1] = i;
    }

    printf("\n行列式计算式的项：\n");
    arrange(det, digit, temp_digit, n, 0);
    printf("\n行列式计算式项数：%d\n\n", term_cnt);
    printf("行列式计算结果为：%d", ans);
    return 0;
}

void swap(int *x, int *y) //交换
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void arrange(int det[], int digit[], int temp_digit[], int n, int pos)
{
    //arrange是用交换法对a1p1 a2p2...anpn（n和pn都是下标）中的p1p2...pn进行全排列
    if (pos == n - 1) //到最后一位时，开始套公式计算行列式
    {
        int term = 1;               //term重置为1
        for (int i = 0; i < n; i++) //此处循环中的i+1是aij的i，digit[i]是j(在数组中下标都减一)
        {
            term *= det[i * n + digit[i] - 1]; //term是当前的项
        }

        //为了不改变原排列的顺序，需要用一个临时数组作为原排列的副本
        for (int i = 0; i < n; i++)
            temp_digit[i] = digit[i];

        cnt = 0; //cnt重置为0
        //将临时数组传入归并法，用于临时排序的同时计算逆序数
        mergesort(temp_digit, 0, n - 1);

        term_cnt++;       //项数+1
        if (cnt % 2 == 1) //若逆序数为奇数，则当前项前有负号
        {
            printf(" -");
            ans = ans - term;
        }
        else if (cnt % 2 == 0) //若逆序数为偶数，则当前项前有正号
        {
            printf(" +");
            ans = ans + term;
        }
        for (int i = 0; i < n; i++)
        {
            //用a(i,j)表示行列式中第i行第j列的元素
            //将每一项（包括前面的正负符号）输出，展现计算过程
            printf(" a(%d,%d) ", i + 1, digit[i]);
            if (i != n - 1)
                printf("*");
        }
        printf("\n");
    }
    else
    {
        for (int i = pos; i < n; i++) //i是当前位pos后面的位
        {
            swap(digit + i, digit + pos);                //digit[i]和digit[pos]交换
            arrange(det, digit, temp_digit, n, pos + 1); //进入到下一位的排列
            swap(digit + i, digit + pos);                //还原交换的两数
        }
    }
}

void mergesort(int temp_digit[], int L, int R) //L,R分别为当前数组的首尾位置
{
    if (L == R)
        return;                       //当数组只剩一个数（无法再分割时），返回
    int middle = (L + R) / 2;         //将当前数组一分为二
    mergesort(temp_digit, L, middle); //对子数组同样一分为二，直到数组无法再分割
    mergesort(temp_digit, middle + 1, R);
    int temp[R - L + 1];
    //临时数组，用于暂时存放排好序的数
    //达到排序并合并两子数组的效果
    int pos1 = L, pos2 = middle + 1, pos3 = 0;
    //pos1是在子数组1中的当前位置
    //pos2是在子数组2中的当前位置
    //pos3是在临时数组中的当前位置
    while (pos1 <= middle && pos2 <= R)
    {
        //两子数组中的数进行比较，较小的数放在临时数组前面
        if (temp_digit[pos1] <= temp_digit[pos2])
        {
            temp[pos3++] = temp_digit[pos1++];
        }
        else
        {
            temp[pos3++] = temp_digit[pos2++];
            cnt += middle - pos1 + 1;
            //当子数组2当前位置的数比子数组1当前位置的数小时（不能有等于）
            //逆序数计数加上子数组1中剩余的数的个数
        }
    }
    while (pos1 <= middle) //将比较后子数组1剩余的数放进临时数组
    {
        temp[pos3++] = temp_digit[pos1++];
    }
    while (pos2 <= R) //将比较后子数组2剩余的数放进临时数组
    {
        temp[pos3++] = temp_digit[pos2++];
    }

    for (int i = 0; i < pos3; i++) //将临时数组排好序的数放回原数组
    {
        temp_digit[L + i] = temp[i];
    }
}
