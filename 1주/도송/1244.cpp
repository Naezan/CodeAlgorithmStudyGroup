#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int N, M;
int light[101];
vector<pair<int, int>> students;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int n;
		scanf("%d", &n);
		light[i] = n;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		students.push_back(make_pair(a, b));
	}

	//M * N
	for (int i = 0; i < students.size(); ++i)
	{
		int gender = students[i].first;
		int number = students[i].second;
		if (gender == 1)
		{
			for (int j = 0; j < N; ++j)
			{
				if ((j + 1) % number == 0)
				{
					light[j] ^= 1;//0이면1 1이면0
				}
			}
		}
		else
		{
			//자기가받은 번호중심으로 대칭인구간의 모든 수를 바꿈
			int index = 0;
			while (true)
			{
				if (number - index < 1 || number + index > N)
				{
					break;
				}

				//대칭이라면
				if (light[number - index - 1] == light[number + index - 1])
				{
					light[number - index - 1] ^= 1;

					//나 자신이 아니라면 반대편 대칭 스위치
					if (number - index - 1 != number + index - 1)
					{
						light[number + index - 1] ^= 1;
					}
				}
				//대칭이 아니라면
				else
				{
					break;
				}

				++index;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", light[i]);
		if ((i + 1) % 20 == 0)
			printf("\n");
	}

	return 0;
}