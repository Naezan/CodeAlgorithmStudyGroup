#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int N;//1~26
int input[27];
string s;//100
stack<double> nums;

int main()
{
	cin >> N;
	cin >> s;

	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;
		input[i] = n;
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] <= 'Z' && s[i] >= 'A')
		{
			nums.push(input[s[i] - 'A']);
		}
		else
		{
			double second = nums.top();
			nums.pop();
			double first = nums.top();
			nums.pop();
			switch (s[i])
			{
			case '+':
				nums.push(first + second);
				break;
			case '-':
				nums.push(first - second);
				break;
			case '*':
				nums.push(first * second);
				break;
			case '/':
				nums.push(first / second);
				break;
			}
		}
	}

	printf("%.2f", nums.top());

	return 0;
}