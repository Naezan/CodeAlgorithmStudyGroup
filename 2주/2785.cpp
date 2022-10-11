#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int N, sum, ans;

deque<int> deq;

int main()
{
	//50만
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int c;
		scanf("%d", &c);
		deq.push_back(c);
		sum += c;
	}

	sort(deq.begin(), deq.end());

	//제일 작은체인부터 하나씩 사용하면서 고리를 연결해줌
	while (deq[0] != sum)
	{
		//최솟체인을 빼줌
		--deq[0];
		int a = deq.back();//제일큰체인
		deq.pop_back();
		int b = deq.back();//두번째로큰체인
		deq.pop_back();
		//두 체인을 합쳐서 넣어줌
		deq.push_back(a + b + 1);

		//최소체인을 모두 쓴경우
		if (deq[0] == 0)
		{
			deq.pop_front();
		}

		++ans;
	}

	printf("%d", ans);

	return 0;
}