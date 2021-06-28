#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr)
{
	int gap = arr.size();
	while (gap > 0)
	{
		gap /= 2;
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
	}
}

//int main()
//{
//	vector<int> arr = { 200,1,9,7,5,3,8,2,4,6, 100 };
//	shellSort(arr);
//	return 0;
//}