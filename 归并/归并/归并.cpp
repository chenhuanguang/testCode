#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& arr, int begin, int mid, int end, vector<int>& tmp)
{
	//����1[begin, mid]
	int begin1 = begin;
	int end1 = mid;
	//����2[mid+1, end]
	int begin2 = mid + 1;
	int end2 = end;

	//�����ռ����ʼλ��
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		//˭С˭�Ƚ�
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
			//�ҵ��������ϲ�������������
			//[begin, mid] [mid+1, end]
			int begin = idx;
			int mid = idx + step - 1;
			//�ж��Ƿ���ڵڶ�������
			if (mid >= n - 1)
				continue;
			int end = idx + 2 * step - 1;
			//�жϵڶ����������Ƿ�Խ��
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