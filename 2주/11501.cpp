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

//���簪���� ������ ���ֽ��� �ִٸ� �Ȱ� ������ ������
//���簪���� ũ�� ���

//�ݷ�
//�ڿ� �� ���� ���� �ֽ��� �ִٸ� �� ���� ������ ���� �� ����

//�迭�� ���� ���� ���� ���� �༮���ͳ��� + �ε��� ����

//���ϳ����������� �ε������� ���������� ��� ���Ϳ� ������ �� �ε����� ����
//�� �ε������� ũ�ٸ� �� �ε��� + 1���� ���� �ε������� �������� ������ ���Ϳ� ������

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

		//�ֽ��� ū��~������ ����
		sort(v.begin(), v.end(), compare);

		//ó�� �ƽ� �ε����� ����
		int maxindex = 0;
		while (!v.empty())
		{
			//ó�� ���� �ִ��� �� //�������� ���� �ִ�
			pair<int, int> p = v.front();
			v.pop_front();

			//�ε����� �߽� �ε������� �۴ٸ� �̹� �� �ֽ�
			if (p.first < maxindex)
			{
				continue;
			}

			//ó���� �ƴҰ�� ���� �ε��� + 1���� �����ؾ���
			if (maxindex != 0)
			{
				++maxindex;
			}

			//���� ���� ū���� �ֽ� ������ ��簪�� �ֽ��� ������ ������
			for (int j = maxindex; j < p.first; ++j)
			{
				ans += (p.second - base[j]);
			}

			//�ƽ� �ε����� ���� �ƽ� �ε����� ���� ���� �񱳸� ���ؼ� ���
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