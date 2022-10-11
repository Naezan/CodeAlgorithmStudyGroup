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

//재귀쓰면 시간초과
int dp[10001];//2차원배열쓰면 메모리초과 굳이 2차원이 필요없다
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

	//n개의 동전과 k까지의 합
	//첫번째시도 1 1 1 1 1 1 1 1 1 1
	//두번째시도 1 2 2 3 3 4 4 5 5 6
	//세번째시도 1 2 2 3 4 5 6 7 8 10
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