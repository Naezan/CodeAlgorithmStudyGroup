#include <bits/stdc++.h>
using namespace std;

int main()
{

    
    int sum = 0;
    int min;
    int num;
    const int ARRAY_SIZE = 8;
    vector<pair<int, int>> v1;
    
    
    
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cin >> num;
        v1.push_back(pair<int, int>(i, num));
    }

    for (int i = 0; i < v1.size(); ++i)
    {
        min = i;
        for (int j = i + 1; j < v1.size(); ++j)
        {
            if (v1[min].second < v1[j].second)
            {
                pair<int, int> tempPair = v1[min];
                v1[min] = v1[j];
                v1[j] = tempPair;
            }
        }
    }
    
    for (int i = 0; i < 5; ++i)
    {
        sum += v1[i].second;
    }
    cout << sum << endl;
    sort(v1.begin(), v1.begin() + 5);
    for (int i = 0; i < 5; ++i)
    {
        cout << v1[i].first + 1 << " ";
    }
    
}

