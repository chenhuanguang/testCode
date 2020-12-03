#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<stdlib.h>

int int_qsort(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

bool uniqueOccurrences(int* arr, int arrSize)
{
	int j = 0;
	int flag = 0;
	qsort(arr, arrSize, sizeof(int), int_qsort);

	if (arrSize == 2)
	{
		if (arr[0] != arr[1])
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	for (int i = 0; i < arrSize - 1; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			arr[j++] = i - flag + 1;	 ///1 1 1 2 2 3
			flag = i + 1;
		}
	}
	arr[j] = 1;
	qsort(arr, j, sizeof(int), int_qsort);
	for (int i = 0; i < j - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			return false;
		}
	}

	return true;
}

//arr = [-3,0,1,-3,1,1,1,-3,10]
int main()
{
	int ar[] = { 1,2,2,1,1,3 };
	int size = sizeof(ar) / sizeof(int);

	bool flag = uniqueOccurrences(ar, size);

	printf("%d\n", (int)flag);

	return 0;
}