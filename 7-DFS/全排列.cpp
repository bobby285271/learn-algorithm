#include <stdio.h>
#include <iostream>
using namespace std;
int a[101], b[101], n;
void print()
{
    int i;
    for (i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
inline void dfs(int i)
{
    int j;
    if (i == n + 1)
    {
        print();
        return;
    }
    for (j = 1; j <= n; j++)
    {
        if (b[j] == 0)
        {
            a[i] = j;
            b[j] = 1;
            dfs(i + 1);
            b[j] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
