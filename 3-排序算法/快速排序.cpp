#include <stdio.h>
#define N 1000
void quicksort(int a[], int L, int R);
void Swap(int *a, int *b);
int main()
{
    int n, i;
    int a[N];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
void quicksort(int a[], int L, int R)
{
    if (L == R - 1)
    {
        return;
    }
    int x = L + 1, y = R - 1;
    while (x != y)
    {
        while (a[y] < a[L] && y > x)
        {
            y--;
        }
        while (a[x] > a[L] && x < y)
        {
            x++;
        }
        if (x < y)
        {
            Swap(&a[x], &a[y]);
        }
    }
    if (a[L] < a[y])
        Swap(&a[L], &a[y]);
    quicksort(a, L, x);
    quicksort(a, x, R);
}
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
