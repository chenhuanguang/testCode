#include <iostream>
#include <vector>
using namespace std;

void selectSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		int minIdx = i;
		for (int j =  i + 1; j < arr.size(); ++j)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		swap(arr[i], arr[minIdx]);
	}
}

int main()
{
	vector<int> arr = { 5,2,3,1,7,8,9,4,10,6,5 };
	selectSort(arr);
	for (auto& e : arr)
		cout << e << " ";
	return 0;
}