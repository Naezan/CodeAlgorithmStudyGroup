#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int R, C, K;

char board[6][6];
bool check[6][6];
int ax[4]{ -1, 0, 1, 0 };
int ay[4]{ 0, 1, 0, -1 };
int ans;

void calc(int startx, int starty, int count);

int main()
{
	scanf("%d %d %d", &R, &C, &K);
	getchar();

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			char c;
			scanf("%c", &c);
			board[i][j] = c;
		}
		getchar();
	}

	//시작점(0, R - 1) 도착점(C - 1, 0)
	board[R - 1][0] = 'a';
	calc(0, R - 1, 1);

	printf("%d", ans);

	return 0;
}

void calc(int startx, int starty, int count)
{
	//횟수 K
	++count;
	if (count > K)
	{
		--count;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int dx = ax[i] + startx;
		int dy = ay[i] + starty;

		if (dx < 0 || dx > C - 1 || dy < 0 || dy > R - 1)
		{
			continue;
		}

		//만약 확인한 장소거나 장애물이라면
		if (board[dy][dx] == 'T' || board[dy][dx] != '.')
		{
			continue;
		}

		board[dy][dx] = board[starty][startx] + 1;

		if (dy == 0 && dx == C - 1)
		{
			if (count == K)
			{
				++ans;
				board[dy][dx] = '.';
				return;
			}
			board[dy][dx] = '.';
			continue;
		}

		calc(dx, dy, count);

		board[dy][dx] = '.';
	}
}