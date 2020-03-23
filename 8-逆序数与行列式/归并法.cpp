#include <iostream>
using namespace std;

void mergesort(int temp_digit[], int L, int R);

int cnt = 0; //用于给逆序数计数

int main()
{
    int n;
    cout << "排序的数的个数：";
    cin >> n;
    int temp_digit[n];
    cout << "准备排序的数：";
    for (int i = 0; i < n; i++)
        cin >> temp_digit[i];
    mergesort(temp_digit, 0, n - 1);
    cout << "经排序过的数：";
    for (int i = 0; i < n; i++)
        cout << temp_digit[i] << " ";
    cout << endl
         << "逆序数：" << cnt;
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
            //子数组1中剩余的数的个数加入逆序数计数中
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
