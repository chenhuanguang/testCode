#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

bool isStraight(int* nums, int numsSize){
	for (int i = 0; i < numsSize - 1; ++i)
	{
		for (int j = 0; j < numsSize - 1 - i; ++j)
		{

			if (nums[j] == nums[j + 1] && nums[j] != 0)
			{
				return false;
			}
			if (nums[j]>nums[j + 1])
			{
				int tmp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = tmp;
			}
		}
	}

	int joker = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
		{
			joker++;
		}
	}
	return nums[4] - nums[joker]<5;

}

int main()
{
	int num[] = { 0,0,2,2,5};
	int size = sizeof(num) / sizeof(int);

	bool flag = isStraight(num, size);


	if (flag)
	{
		printf("顺子\n");
	}
	else
	{
		printf("不是顺子\n");
	}
	return 0;
}

/*
typedef struct Test3
{
	short a;
	struct
	{
		int b; 
		double c;
		long d;
	};
	int e; 
}Test3;

int main()
{
	printf("size = %d\n", sizeof(Test3));

	return 0;
}
*/
/*
int main()
{

	char str[][2] = { '1', '2', 'c', 'd','s' };

	int n = sizeof(str);

	return 0;
}
*/

/* 8转化为10进制
int my_ocetoi(const char *str)
{
	int sum = 0;
	while (isdigit(*str) && *str <='7')
	{
		sum = sum * 8 + *str - '0';
		++str;
	}
	return sum;
}

10转化为10进制
int my_dectoi(const char *str)
{
	int sum = 0;
	while (isdigit(*str))
	{
		sum = sum * 10 + *str - '0';
		++str;
	}
	return sum;
}

16转化为10进制
int my_hextoi(const char *str)
{
	int sum = 0;
	while (isxdigit(*str))
	{
		if (isdigit(*str))
		{
			sum = sum * 16 + *str - '0';
			
		}
		else
		{
			char ch = tolower(*str);
			sum = sum * 16 + ch - 'a'+10;
		}
		++str;
	}
	return sum;
}

int main()
{
	char str[] = { "12F34" };

	printf("%d\n", my_hextoi(str));

	return 0;
}
*/

/*
int main()
{
	int ar[5][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int(*p)[2] = &ar[1];
	int *s = (int*)&ar[0];

	printf("%d %d\n", p[1][3], s[4]);

	
	return 0;
}
*/