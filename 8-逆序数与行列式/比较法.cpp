#include <stdio.h>
void compare(int digit[], int n);

int cnt = 0; //用于给逆序数计数

int main()
{
	int n;
	printf("数的个数：");
	scanf("%d", &n);
	int digit[n];

	printf("数：");
	for (int i = 0; i < n; i++)
		scanf("%d", &digit[i]);

	compare(digit, n);
	printf("逆序数：%d", cnt);
}

void compare(int digit[], int n)
{
	for (int i = 0; i < n; i++) //i是当前的数的位置
	{
		for (int j = 0; j < i; j++) //j是当前的数前面的数的位置
		{
			if (digit[j] > digit[i])
				cnt++;
		}
	}
}
