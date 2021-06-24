#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr)
{
	int gap = arr.size() / 2;
	while (gap > 0)
	{
		for (int i = gap; i < arr.size(); ++i)
		{
			int data = arr[i];
			int end = i - gap;
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
		gap /= 2;
	}
}

int main()
{
	vector<int> arr = { 8,6,4,2,3,9,1,5,7 , -1, 100 ,999,-99};
	shellSort(arr);
	for (const auto& e : arr)
	{
		cout << e << " ";
	}
	return 0;
}