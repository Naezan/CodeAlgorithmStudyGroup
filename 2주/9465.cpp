#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int T, N;

int dp[2][100001];
vector<int> v[2];

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &N);
		for (int j = 0; j < (N + N); ++j)
		{
			int m;
			scanf("%d", &m);
			if (j < N)
				v[0].push_back(m);
			else
				v[1].push_back(m);
		}
		
		//표를 통해서 행은 dp[0][?], dp[1][?] 열은 dp[?][0~5]
		// \ 0 1  2   3   4   5
		// 0 0 50 40  200 140 250
		// 1 0 30 100 120 210 260
		dp[0][0] = 0;
		dp[0][1] = v[0][0];
		dp[1][0] = 0;
		dp[1][1] = v[1][0];
		for (int j = 2; j <= N; ++j)
		{
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + v[0][j - 1];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + v[1][j - 1];
		}

		printf("%d\n", max(dp[0][N], dp[1][N]));
		v[0].clear();
		v[1].clear();
	}

	return 0;
}