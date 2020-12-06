#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

int* singleNumbers(int* nums, int numsSize, int* returnSize) 
{
	*returnSize = 2;
	int x = 0;
	int y = 0;
	int ret = 0;
	int pos = 0;
	int *pnum = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	for (int i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
			pos = i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (((nums[i] >> pos) & 1) == 1)
			x ^= nums[i];
		else
			y ^= nums[i];
	}
	pnum[0] = x;
	pnum[1] = y;
	return pnum;
}

int main()
{
	int nums[] = { 4,1,4,6 };
	int numsSize = sizeof(nums) / sizeof(int);
	int returnSize = 2;
	int *pnums = singleNumbers(nums, numsSize, &returnSize);
	printf("%d\n",pnums[0]);
	return 0;
}

/*
int missingNumber(int* nums, int numsSize) 
{
	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i <= numsSize; i++)
	{
		sum += i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		sum1 += nums[i];
	}
	return sum-sum1;
}

int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int size = sizeof(nums) / sizeof(int);
	int num = missingNumber(nums, size);
	printf("%d\n", num);
	return 0;
}
*/
/*∂˛∑÷∑®
int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	int a = BinarySearch(arr, 10, 3);
	printf("%d\n", a);
	return 0;
}
*/
/*√∞≈›≈≈–Ú
void BubbleSort(int *a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,10 };

	BubbleSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/