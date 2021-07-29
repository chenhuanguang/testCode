#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& arr, int begin, int mid, int end, vector<int>& tmp)
{
	//区间1[begin, mid]
	int begin1 = begin;
	int end1 = mid;
	//区间2[mid+1, end]
	int begin2 = mid + 1;
	int end2 = end;

	//辅助空间的起始位置
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		//谁小谁先进
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[idx++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[idx++] = arr[begin2++];
	}

	for (int i = 0; i <= end-begin; ++i)
	{
		arr[begin + i] = tmp[begin + i];
	}
}

void mergeSort(vector<int>& arr, int n)
{
	vector<int> tmp(n);
	int step = 1;
	while (step < n)
	{
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			//找到两个待合并的子序列区间
			//[begin, mid] [mid+1, end]
			int begin = idx;
			int mid = idx + step - 1;
			//判断是否存在第二个序列
			if (mid >= n - 1)
				continue;
			int end = idx + 2 * step - 1;
			//判断第二个子序列是否越界
			if (end >= n)
				end = n - 1;

			Merge(arr, begin, mid, end, tmp);
		}
		step *= 2;
	}
}

int main()
{
	vector<int> arr = { 10000,-100,5,4,9,2,3,1,0,7,8 };
	mergeSort(arr, arr.size());
	for (auto e : arr)
		cout << e << " ";
	return 0;
}