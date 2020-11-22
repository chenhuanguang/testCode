#include<stdio.h>

//二进制奇偶打印
int main()
{

	int num = 6;

	//偶数
	for (int i = 31; i >=1; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");

	//奇数
	for (int i = 30; i >=0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}

	return 0;
}

/*
int main()
{

	char *str = "hello world";
	char str1[] = "hello world";

	printf("%d %d %d %d \n", sizeof(str), strlen(str), sizeof(str1), strlen(str1)); //随机值 11 12 11

	return 0;
}
*/