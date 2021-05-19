#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapSort(vector<int>& arr)
{
	make_heap(arr.begin(), arr.end());
	int end = arr.size() - 1;
	for (int i = 0; i < arr.size(); ++i)
	{
		swap(arr[0], arr[end]);
		make_heap(arr.begin(), arr.begin() + end);
		--end;
	}
}

int main()
{
	vector<int> arr = { 5,6,1,2,3,9,4,7,8 };
	heapSort(arr);
	for (const auto& e : arr)
		cout << e << " ";
	return 0;
}