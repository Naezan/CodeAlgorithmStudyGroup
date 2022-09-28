#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int N;
queue<int> cards;

int main()
{
	scanf("%d", &N);

	//N
	for (int i = 0; i < N; ++i)
	{
		cards.push(i + 1);
	}

	//N/2
	while (cards.size() != 1)
	{
		cards.pop();

		int top = cards.front();
		cards.pop();
		cards.push(top);
	}

	printf("%d", cards.front());

	return 0;
}