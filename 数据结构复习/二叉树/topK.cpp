#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void adjust(vector<int>& arr, int parent)
{
	int child = 2 * parent + 1;
	while (child < arr.size())
	{
		if ((child + 1 < arr.size()) && arr[child] > arr[child+1])
			++child;

		if (arr[parent] > arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void topK(vector<int>& arr, int k)
{
	vector<int> res(arr.begin(), arr.begin() + k);
	make_heap(res.begin(), res.end(), greater<int>());
	for (int i = k; i < arr.size(); ++i)
	{
		if (arr[i] > res[0])
		{
			res[0] = arr[i];
			adjust(res, 0);
		}
	}
	for (const auto& e : res)
		cout << e << " ";
}

int main()
{
	vector<int> arr = { 200,1,9,7,5,3,8,2,4,6, 100 };
	int k = 5;
	topK(arr, k);
	return 0;
}