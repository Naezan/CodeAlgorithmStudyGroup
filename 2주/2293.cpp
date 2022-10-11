#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int N, K;

//��;��� �ð��ʰ�
int dp[10001];//2�����迭���� �޸��ʰ� ���� 2������ �ʿ����
int coins[101];

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; ++i)
	{
		int n;
		scanf("%d", &n);
		coins[i] = n;
	}

	//n���� ������ k������ ��
	//ù��°�õ� 1 1 1 1 1 1 1 1 1 1
	//�ι�°�õ� 1 2 2 3 3 4 4 5 5 6
	//����°�õ� 1 2 2 3 4 5 6 7 8 10
	dp[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = coins[i]; j <= K; ++j)
		{
			dp[j] += dp[j - coins[i]];
		}
	}

	printf("%d", dp[K]);

	return 0;
}