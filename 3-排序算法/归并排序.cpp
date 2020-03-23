#include <stdio.h>
#define N 1000
void Mergesort(int a[], int L, int R);
int main()
{
    int n, i;
    int a[N];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Mergesort(a, 0, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
void Mergesort(int a[], int L, int R)
{
    if (L > R - 2)
    {
        return;
    }                         //当数据只剩下1个的时候，结束，回到上一层递归
    int middle = (L + R) / 2; //中间值，负责分半
    Mergesort(a, L, middle);
    Mergesort(a, middle, R);    //把数据分开两半
    int x = L;                  //子数据1的下标
    int y = middle;             //子数据1旁边的子数据2的下标
    int t = L;                  //空白数组的下标
    int turn[N] = {0};          //空白数组
    while (x < middle || y < R) //对a[L]……a[middle-1],和对a[middle]…….a[R-1]数据进行合并
    {
        if (y >= R || (x < middle && (a[x] >= a[y])))
        {
            turn[t++] = a[x++];
        } //把大的先放进去turn[ ],达到从大到小排序的目的。忘了x<middle时循环可能会越过middle边界。如果子数据2已经越了界，则把子数据1全部放入turn[ ]中
        else
        {
            turn[t++] = a[y++];
        }
    }
    for (int i = L; i < R; i++)
    {
        a[i] = turn[i];
    } //把turn[ ]中排好的数据放回原来的数组
}
