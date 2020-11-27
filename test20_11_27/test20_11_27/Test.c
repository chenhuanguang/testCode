#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

/*
int xorOperation(int n, int start) 
{

	int result = start;
	for (int i = 0; i < n-1; i++)
	{
		result ^= start + 2 * (i + 1);
	}
	return result;
}

int main()
{

	int start = 0;
	int result = start;
	for (int i = 0; i < 4; i++)
	{
		result ^= start + 2 * (i + 1);
	}
	printf("%d\n", result);
	return 0;
}
*/
/*
#define N 1000000007

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int breakfastNumber(int* staple, int stapleSize, int* drinks, int drinksSize, int x) {

	qsort(staple, stapleSize, sizeof(int), cmp);
	qsort(drinks, drinksSize, sizeof(int), cmp);

	long count = 0;
	int stapleIndex = 0;
	int drinksIndex = drinksSize - 1;
	while (stapleIndex < stapleSize && drinksIndex >= 0) {
		if (staple[stapleIndex] + drinks[drinksIndex] <= x) {
			count += drinksIndex + 1;
			stapleIndex++;
		}
		else {
			drinksIndex--;
		}
	}
	return count%N;
}

int main()
{
	int staple[] = { 10,20,5 }; //5 10 20
	int drinks[] = { 5,5,2 };
	int v = breakfastNumber(staple,3, drinks, 3,15);
	printf("%d\n", v);
	return 0;
}
*/
/*
int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
	int count = 0;
	for (int i = 0; i < ASize; i++)
	{
		for (int j = 0; j < BSize; j++)
		{
			for (int k = 0; k < CSize; k++)
			{
				for (int l = 0; l < DSize; l++)
				{
					if ((A[i] + B[j] + C[k] + D[l]) == 0)
					{
						count++;
					}
				}
			}
		}
	}
	return count;
}

int main()
{
	int a[] = { 1,2 }; 
	int b[] = { -2,-1 };
	int c[] = { -1,2 };
	int d[] = { 0,2 };

	printf("%d \n", fourSumCount(a, 2, b, 2, c, 2, d, 2));
	return 0;
}
*/

/*
int* printNumbers(int n, int* returnSize) {

	int count = pow(10, n) - 1;
	int *nums = (int*)malloc(sizeof(int)*count);
	*returnSize = count;
	for (int i = 0; i < count; i++)
	{
		nums[i] = i + 1;
	}
	return nums;
}
*/