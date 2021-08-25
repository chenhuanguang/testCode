#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ans(vector<int> array, int k)
{
    long long res;
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size() - 1; ++i)
    {
        for (int j = i + 1; j < array.size(); ++j)
        {
            if (array[i] + array[j] <= k)
                ++res;
        }
    }
    return res;
}

int main()
{
    ans({ 3,1,2 }, 5);
	return 0;
}