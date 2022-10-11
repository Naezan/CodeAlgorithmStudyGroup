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
	//50��
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int c;
		scanf("%d", &c);
		deq.push_back(c);
		sum += c;
	}

	sort(deq.begin(), deq.end());

	//���� ����ü�κ��� �ϳ��� ����ϸ鼭 ���� ��������
	while (deq[0] != sum)
	{
		//�ּ�ü���� ����
		--deq[0];
		int a = deq.back();//����ūü��
		deq.pop_back();
		int b = deq.back();//�ι�°��ūü��
		deq.pop_back();
		//�� ü���� ���ļ� �־���
		deq.push_back(a + b + 1);

		//�ּ�ü���� ��� �����
		if (deq[0] == 0)
		{
			deq.pop_front();
		}

		++ans;
	}

	printf("%d", ans);

	return 0;
}