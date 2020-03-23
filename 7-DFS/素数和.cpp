#include <bits/stdc++.h>
using namespace std;

int num[10];    //存储输入的数字
int record[10]; //记录使用情况，这里初始值为 0
int sum = 0;    //几个数的和
int n, k;
int p[10]; //用来防止有重复的情况出现

int print()
{
    for (int i = 1; i <= n; i++)
    {
        if (record[i] == 1)
        {
            cout << num[i] << " ";
        }
    }
    cout << endl;
}

void dfs(int i) //轮到第几位数
{
    if (i == k + 1) //满足个数就输出
    {
        if (sum % 2 != 0)
        { //满足和是素数才输出
            print();
        }
        return;
    }
    else
    {
        for (int j = 1; j <= n; j++) //为第几位数选择数
        {
            if (record[j] == 0 && num[j] > p[i - 1]) //没有被选的数才加上去，并且这个数要比上一位 （换行）
            {                                        // 选择的数大，不然会出现重复的现象
                p[i] = num[j];                       //表示当前选择的数
                sum += num[j];                       //加上这个数
                record[j] = 1;                       //记录，选过了
                dfs(i + 1);                          //进行选择下一位数
                record[j] = 0;                       //回头，清除记录
                sum -= num[j];                       //和也要回头，不然就多了
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    dfs(1); //从第一位开始
    return 0;
}
