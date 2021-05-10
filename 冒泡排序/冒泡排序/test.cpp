#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr)
{
	int n = arr.size() - 1;
	int pos = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		bool flag = false;
		for (int j = 0; j < n; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j + 1], arr[j]);
				flag = true;
				pos = j;
			}
		}
		if (!flag)
			break;
		n = pos;
	}
}

int main()
{
	vector<int> arr = { 5,2,3,1,7,8,9,4,10,6,5 ,-1,100};
	bubbleSort(arr);
	for (auto& e : arr)
		cout << e << " ";
	return 0;
}