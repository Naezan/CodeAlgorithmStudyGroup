#include <bits/stdc++.h>
using namespace std;

bool switchState[105]; 

int main()
{
	
	int switchCount;	
	int studentNumber;	


	cin >> switchCount;
	for (int i = 1; i <= switchCount; ++i)
	{
		cin >> switchState[i];
	}
	
	cin >> studentNumber;
	
	for (int i = 0; i < studentNumber; ++i)
	{
		int gender;
		int selectedNumber;
		cin >> gender;
		cin >> selectedNumber;
		if (gender == 1)
		{
			// TODO
			// 배수 인덱스 뒤집기
			for (int i = 1; i <= switchCount; ++i)
			{
				if ((i % selectedNumber) == 0)
				{
					switchState[i] = !switchState[i];
				}
			}
		}
		else if (gender == 2)
		{
			switchState[selectedNumber] = !switchState[selectedNumber];
			int prevIndex = selectedNumber - 1;
			int nextIndex = selectedNumber + 1;
			while (switchState[prevIndex] == switchState[nextIndex])
			{
				if (prevIndex <= 0 || nextIndex > switchCount)
					break;
				switchState[prevIndex] = !switchState[prevIndex];
				switchState[nextIndex] = !switchState[nextIndex];
				prevIndex--;
				nextIndex++;
			}
		
		}		
	}
	for (int i = 1; i <= switchCount; ++i)
	{
		
		cout << switchState[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}
}