#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int H, W, X, Y;
int A[300][300];

int main()
{
	scanf("%d %d %d %d", &H, &W, &X, &Y);

	for (int i = 0; i < H + X; ++i)
	{
		for (int j = 0; j < W + Y; ++j)
		{
			int n;
			scanf("%d", &n);
			//�̵����� ���� A
			int c = 0;
			if (i < H && j < W)
			{
				++c;
				A[i][j] = n;
			}
			//�̵��� A
			if (i >= X && j >= Y)
			{
				++c;
			}

			//A���� �̵���A��� �������°��� ��
			if (c == 2)
			{
				A[i][j] = n - A[i - X][j - Y];
			}
		}
	}

	//���
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}