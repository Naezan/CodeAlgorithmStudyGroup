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
long long ans;

vector<int> base;
deque<pair<int, int>> v;

//현재값보다 작으면 산주식이 있다면 팔고 없으면 가만히
//현재값보다 크면 사기

//반례
//뒤에 더 높은 값의 주식이 있다면 더 좋은 이익이 나올 수 있음

//배열을 제일 높은 값을 가진 녀석부터나열 + 인덱스 포함

//제일높은값을가진 인덱스까지 이전값들을 모두 이익에 더해줌 이 인덱스를 저장
//이 인덱스보다 크다면 이 인덱스 + 1부터 현재 인덱스까지 높은값의 차익을 이익에 더해줌

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.second > b.second;
}

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &N);
		int max = 0;
		for (int j = 0; j < N; ++j)
		{
			int n;
			scanf("%d", &n);

			base.push_back(n);
			v.push_back(make_pair(j, n));//index, stock
		}

		//주식이 큰값~작은값 정렬
		sort(v.begin(), v.end(), compare);

		//처음 맥스 인덱스를 지정
		int maxindex = 0;
		while (!v.empty())
		{
			//처음 값은 최댓값이 들어감 //다음부턴 다음 최댓값
			pair<int, int> p = v.front();
			v.pop_front();

			//인덱스가 멕스 인덱스보다 작다면 이미 판 주식
			if (p.first < maxindex)
			{
				continue;
			}

			//처음이 아닐경우 나의 인덱스 + 1부터 연산해야함
			if (maxindex != 0)
			{
				++maxindex;
			}

			//현재 가장 큰값의 주식 이전의 모든값의 주식의 차익을 더해줌
			for (int j = maxindex; j < p.first; ++j)
			{
				ans += (p.second - base[j]);
			}

			//맥스 인덱스는 현재 맥스 인덱스로 지정 다음 비교를 위해서 사용
			maxindex = p.first;
		}

		ans = ans < 0 ? 0 : ans;
		printf("%lld\n", ans);

		ans = 0;
		base.clear();
		v.clear();
	}

	return 0;
}