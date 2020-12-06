#include<stdio.h>
#include<malloc.h>

int f_max(int a, int b)
{
	return a > b ? a : b;
}

int maximumWealth(int(*accounts)[2], int accountsSize, int* accountsColSize) 
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < accountsSize; i++)
	{
		for (int j = 0; j < *accountsColSize; j++)
		{
			sum += accounts[i][j];
		}
		max = f_max(max, sum);
		sum = 0;
	}
	return max;
}

int main()
{

	int arr[][2] = { 1,5,7,4,2,6 };
	int size = sizeof(arr) / sizeof(int);
	int bank = 2;
	int max = maximumWealth(arr, 3, &bank);

	printf("%d\n", max);

	return 0;
}
