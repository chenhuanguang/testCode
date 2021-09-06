#include <iostream>
#include <vector>
using namespace std;

//使用二分查找法，查找出第一个大于或等于某个数的下标
//nums = 1, 2, 3, 4, 4, 5, 5, 6, 8, 9 target = 4

int find(vector<int> arr, int target)
{
	int sz = arr.size();
	if (sz <= 0)
		return -1;
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] >= target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (arr[left] < target)
		return -1;
	return left;
}

int main()
{
	vector<int> arr = { 1,2,3,4,4,5,5,6,8,9 };
	cout << find(arr, 7) << endl;
	return 0;
}