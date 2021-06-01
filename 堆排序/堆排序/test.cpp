#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void adjust(vector<int>& arr, int sz, int idx)
{
	int child = 2 * idx + 1;
	while (child < sz)
	{
		if ((child + 1 < sz) && (arr[child] < arr[child + 1]))
			++child;
		if (arr[idx] < arr[child])
		{
			swap(arr[idx], arr[child]);
			idx = child;
			child = 2 * idx + 1;
		}
		else
			break;
	}
}

void adjustSmall(vector<int>& arr, int sz, int idx)
{
	int child = 2 * idx + 1;
	while (child < sz)
	{
		if ((child + 1 < sz) && (arr[child] > arr[child + 1]))
			++child;
		if (arr[idx] > arr[child])
		{
			swap(arr[idx], arr[child]);
			idx = child;
			child = 2 * idx + 1;
		}
		else
			break;
	}
}

void makeHeap(vector<int>& arr)
{
	for (int i = (arr.size()-2)/2; i >= 0; --i)
	{
		adjust(arr, arr.size() ,i);
	}
}

void heapSort(vector<int>& arr)
{
	makeHeap(arr);
	int end = arr.size()-1;
	for (int i = 0; i < arr.size(); ++i)
	{
		swap(arr[0], arr[end]);
		adjust(arr, end, 0);
		--end;
	}
}

void topK(vector<int>& arr, int k)
{
	vector<int> res(arr.begin(), arr.begin() + k);
	make_heap(res.begin(), res.end(), greater<int>());
	for (size_t i = k; i < arr.size(); ++i)
	{
		if (arr[i] > res[0])
		{
			swap(arr[i], res[0]);
			adjustSmall(res, k, 0);
		}
	}
	for (const auto& e : res)
		cout << e << " ";
}

int main()
{
	vector<int> arr = { 500,5,6,1,2,3,9,4,7,8, 99, 230 };
	topK(arr, 4);
	//heapSort(arr);
	/*for (const auto& e : arr)
		cout << e << " ";*/
	return 0;
}