#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

vector<pair<int, int>> score;
int sum;
int indexs[5];

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	for (int i = 0; i < 8; ++i)
	{
		int n;
		scanf("%d", &n);
		score.push_back(make_pair(i, n));//(i번째, 점수)
	}

	//NlogN
	sort(score.begin(), score.end(), compare);

	//NlogN
	sort(score.begin(), score.begin() + 5, compare2);

	for (int i = 0; i < 5; ++i)
	{
		sum += score[i].second;
		indexs[i] = score[i].first;
	}

	printf("%d\n", sum);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", indexs[i] + 1);
	}

	return 0;
}