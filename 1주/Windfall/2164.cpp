#include <bits/stdc++.h>
using namespace std;

// Logic
//  1  2  3  4  5  6  7
// [1][2][3][4]
//    [2][3][4]
// 
//       [3][4][2]
//          [4][2]
// 
//             [2][4]
//                [4]

// Logic queue? deque?


// 1  2  3  4  5  6
//[1][2][3][4]
//[2][3][4]
//[3][4][2]
//
//

int main()
{

	deque<int> d1;
	int number;
	cin >> number;
	for (int i = 1; i <= number; ++i)
	{
		d1.push_back(i);
	}
	while (d1.size() != 1)
	{
		d1.pop_front();
		d1.push_back(d1.front());
		d1.pop_front();
	}

	cout << d1.front();



}