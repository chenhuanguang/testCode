#include <stdio.h>

//int fun(int num)
//{
//	while (num)
//	{
//		if (num < 10)
//		{
//			if (num == 2 || num == 0 || num == 1 || num == 9)
//			{
//				return 1;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		else
//		{
//			int count = num % 10;
//			if (count == 2 || count == 0 || count == 1 || count == 9)
//			{
//				return 1;
//			}
//			num /= 10;
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int sum = 0;
//	int i = 1;
//	for (i = 1; i <= 40; ++i)
//	{
//		if (fun(i))
//			sum += i;
//	}
//	printf("sum = %d\n",sum);
//	return 0;
//}

int main()
{
	long a = 1;
	long b = 1;
	long c = 1;
	int n = 201;
	while (n--)
	{
		int tmp = c;
		c = a + b + c;
		a = b;
		b = tmp;
	}
	printf("%d\n", c);
}