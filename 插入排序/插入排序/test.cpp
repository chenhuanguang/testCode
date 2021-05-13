#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int data = arr[i];
		int end = i - 1;
		while (end >= 0 && arr[end] > data)
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

int main()
{
	vector<int> arr = { 8,6,4,2,3,9,1,5,7 , -1, 100};
	insertSort(arr);
	for (const auto& e : arr)
	{
		cout << e << " ";
	}
	return 0;
}