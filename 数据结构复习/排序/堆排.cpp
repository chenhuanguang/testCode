#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void adjust(vector<int>& arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if ((child + 1) < n && arr[child] < arr[child + 1])
			++child;
		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void makeHeap(vector<int>& arr)
{
	for (int i = (arr.size() - 2) / 2; i >= 0; --i)
	{
		adjust(arr, arr.size(), i);
	}
}

void heapSort(vector<int>& arr)
{
	makeHeap(arr);

	int end = arr.size() - 1;
	while (end >= 0)
	{
		swap(arr[0], arr[end]);
		adjust(arr, end, 0);
		--end;
	}
}

//int main()
//{
//	vector<int> arr = { 200,1,9,7,5,3,8,2,4,6, 100 };
//	heapSort(arr);
//	return 0;
//}