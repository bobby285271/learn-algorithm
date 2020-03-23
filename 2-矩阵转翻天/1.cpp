#include <stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	int a[N][N], b[N][N]; //N*N的矩阵

	for (int i = 0; i < N; i++) //输入数组
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("\n顺时针旋转90°：\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[N - 1 - j][i]; //数组每行或每列最大下标是N-1
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n逆时针旋转90°：\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[j][N - 1 - i]; //数组每行或每列最大下标是N-1
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n左上、右下对角线为轴翻转：\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[j][i]; //数组每行或每列最大下标是N-1
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n右上、左下对角线为轴翻转：\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[N - 1 - j][N - 1 - i]; //数组每行或每列最大下标是N-1
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n左右翻转：\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[i][N - 1 - j]; //数组每行或每列最大下标是N-1
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n上下翻转：\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[N - 1 - i][j]; //数组每行或每列最大下标是N-1
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n中心翻转：\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[N - 1 - i][N - 1 - j]; //数组每行或每列最大下标是N-1
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
