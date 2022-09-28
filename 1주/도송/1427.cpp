#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

string N;
bool compare(char& a, char& b)
{
	return a > b;
}

int main()
{
	cin >> N;

	sort(N.begin(), N.end(), compare);

	for (int i = 0; i < N.size(); ++i)
	{
		cout << N[i];
	}

	return 0;
}