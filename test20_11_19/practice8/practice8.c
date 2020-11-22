#include<stdio.h>
#include<malloc.h>

//调整数组顺序使奇数位于偶数前面
/*
int* exchange(int* nums, int numsSize, int* returnSize){

	*returnSize = numsSize;

	int l = 0;

	for (int i = 0; i < numsSize;i++)
	{
		if ((nums[i] & 1) != 0)
		{
			int temp = nums[i];
			nums[i] = nums[l];
			nums[l++] = temp;
		}
	}

	return nums;

}
*/

int* exchange(int* nums, int numsSize, int* returnSize){

	*returnSize = numsSize;

	int l = 0;
	int r = numsSize - 1;

	while (l < r)
	{
		if ((nums[l] & 1) == 1)
		{
			l++;
			continue;
		}
		if ((nums[r] & 1) == 0)
		{
			r--;
			continue;
		}
		int temp = nums[l];
		nums[l++] = nums[r];
		nums[r--] = temp;
	}
	
	return nums;

}

/*
int* exchange(int* nums, int numsSize, int* returnSize){

	*returnSize = numsSize;
	int *arr = (int*)malloc(sizeof(int)*numsSize);
	int x = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i]%2!= 0)
		{
			arr[x++] = nums[i];
		}
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i]%2==0)
		{
			arr[x++] = nums[i];
		}
	}
	
	return arr;

}
*/
int main()
{
	int nums[] = { 1, 2, 3, 5, 7, 9 };
	int size = sizeof(nums) / sizeof(int);
	int returnSize;

	int *arr=exchange(nums, size, &returnSize);

	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

//连续子数组的最大和
/*
int maxSubArray(int* nums, int numsSize){

	int res=nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i - 1]>0)
		{
			nums[i] = nums[i]+nums[i - 1];
		}
		if (nums[i] > res)
		{
			res = nums[i];
		}
	}
	return res;
}

//输入: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//			   [-2, 1, -2, 4,  3, 5, 6,  1, 5]
//输出 : 6
//解释 : 连续子数组[4, -1, 2, 1] 的和最大，为 6。

int main()
{

	int nums[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int sumsSize = sizeof(nums) / sizeof(int);

	printf("%d \n", maxSubArray(nums,sumsSize));
	return 0;
}
*/
