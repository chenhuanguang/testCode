#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int massage(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int *dp = (int*)malloc(sizeof(int)*numsSize);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	int i;
	for ( i= 2; i < numsSize; i++)
	{
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[i - 1];
}

int main()
{
	int nums[] = { 2,1,4,5,3,1,1,3};
	int size = sizeof(nums) / sizeof(int);

	printf("%d\n", massage(nums, size));

	return 0;
}

/*
int minCount(int* coins, int coinsSize) 
{
	int sum = 0;
	for (int i = 0; i < coinsSize; i++) 
	{
		sum += (coins[i] + 1) / 2;
	}
	return sum;
}

int main()
{
	int coins[] = {4,2,1 };
	int size = sizeof(coins) / sizeof(int);

	printf("%d\n", minCount(coins, size));

	return 0;
}
*/
/*单词规律
#define MAXSIZE 1000
int wordPattern(char *pattern, char *s)
{
	int plen = strlen(pattern); 
	char *sub[MAXSIZE]; //用于存放s的指针数组
	int rear = 0;
	sub[rear] = strtok(s, " ");
	while (sub[rear] != NULL)
	{
		rear++;
		sub[rear] = strtok(NULL, " ");
	}
	if (plen != rear)
	{
		return 0;
	}
	for (int i = 0; i < rear; i++)//要和其他比较的
	{
		for (int j = i + 1; j < rear; j++)//被比较的
		{
			if ((strcmp(sub[i], sub[j]) == 0 && pattern[i] != pattern[j]) || (strcmp(sub[i], sub[j]) != 0 && pattern[i] == pattern[j]))
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	char pattern[] = "abba";
	char s[] = "cat dog dog cat";

	int a = wordPattern(pattern, s);
	printf("%d\n", a);

	return 0;
}
*/