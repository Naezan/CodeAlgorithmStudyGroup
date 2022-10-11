#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int N, M, V;

vector<int> path[1001];
bool check[1001];
queue<int> q;

void dfs(int curindex);
void bfs();

int main()
{
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; ++i)
	{
		int start, end;//1~
		scanf("%d %d", &start, &end);
		path[start].push_back(end);
		path[end].push_back(start);
	}

	//���������� Ž���� �Ұ��̱� ������ ���� ����
	for (int i = 1; i <= N; ++i)
	{
		sort(path[i].begin(), path[i].end());
	}

	//�ܼ� bfs, dfs����
	check[V] = true;
	printf("%d ", V);
	dfs(V);
	printf("\n");

	memset(check, false, sizeof(bool) * 1001);

	q.push(V);
	check[V] = true;
	printf("%d ", V);
	bfs();

	return 0;
}

void dfs(int curindex)
{
	for (int i = 0; i < path[curindex].size(); ++i)
	{
		if (check[path[curindex][i]])//������ �˻��ߴٸ� �Ѿ��
			continue;

		check[path[curindex][i]] = true;
		printf("%d ", path[curindex][i]);
		dfs(path[curindex][i]);
	}
}

void bfs()
{
	while (!q.empty())
	{
		int a = q.front();//���� ��ġ
		q.pop();
		for (int i = 0; i < path[a].size(); ++i)
		{
			if (check[path[a][i]])//������ �˻��ߴٸ� �Ѿ��
				continue;

			check[path[a][i]] = true;
			printf("%d ", path[a][i]);
			q.push(path[a][i]);
		}
	}
}
