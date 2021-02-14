#include <iostream>
using namespace std;

int BinarySearch(int* nums, int size, int target)
{
	int left = 0;
	int right = size - 1;
	int res = size;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] > target)
		{
			right = mid - 1;
			res = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return res;
}

int main()
{
	int arr[] = { 1, 3, 5, 5, 5, 7, 8, 8, 9 };
	int size = sizeof(arr) / sizeof(int);
	int target = 5;
	int left = BinarySearch(arr, size, 5);
	int right = BinarySearch(arr, size, 5) - 1;
	cout << right << endl;
	return 0;
}