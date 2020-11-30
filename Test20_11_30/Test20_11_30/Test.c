#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include<ctype.h>

int my_atoi(char *str)
{

	int num = 0;
	int flag = 1;
	size_t i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	if (str[i] == '+')
	{
		i++;
	}
	while (isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return num*flag;

}

int main()
{
	char str[] = "-a1234";

	int num=my_atoi(str);
	printf("%d \n", num);
	return 0;
}

/*
typedef struct Test
{
	int a;
	double b;
	int c;
	int d;
	char *ch;
}Test;

int main()
{
	char str[] = "hello world";
	Test *pt = (Test*)malloc(sizeof(Test));
	if (NULL == pt)
	{
		printf("Insufficient memory available\n");//没有足够的空间
		return;
	}

	pt->ch = (char*)malloc(strlen(str) + 1);
	if (NULL == pt->ch)
	{
		printf("Insufficient memory available\n");//没有足够的空间
		return;
	}
	strcpy(pt->ch, str);
	printf("str = %s\n", pt->ch);

	free(pt->ch);
	pt->ch = NULL;

	free(pt);
	pt = NULL;

	return 0;
}
*/
/*
typedef struct Test
{
	int a;
	double b;
	int c;
	int d;
	char ch[0];
}Test;

int main()
{
	char str[] = "hello world";
	Test *pt = (Test*)malloc(sizeof(Test) + strlen(str) + 1);
	if (NULL == pt)
	{
		printf("Insufficient memory available\n");//没有足够的空间
		return;
	}
	
	strcpy(pt->ch, str);
	printf("str = %s\n", pt->ch);

	free(pt);
	pt = NULL;

	return 0;
}
*/
/*
int main()
{
	int num = 10;
	int *p = (int*)malloc(sizeof(int)*num);
	if (NULL == p)
	{
		printf("Insufficient memory available\n");//没有足够的空间
		return;
	}
	for (int i = 0; i < num; i++)
	{
		*(p + i) = i + 1;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");

	num = 15;
	p = (int*)realloc(p,sizeof(int)*num);//开辟 15*4 字节空间
	if (NULL == p)
	{
		printf("Insufficient memory available\n");//没有足够的空间
		return;
	}
	for (int i = 9; i < num; i++)
	{
		*(p + i) = i + 1;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	free(p);
	p = NULL;

	return 0;
}
*/
/*
int main()
{
	int num = 10;
	int *p = (int*)calloc(10,sizeof(int));
	if (NULL == p)
	{
		printf("Insufficient memory available\n");//没有足够的空间
		return;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	free(p);
	p = NULL;

	return 0;
}
*/
/*
int main()
{
	int num = 10;
	int *p = (int*)malloc(sizeof(int)*num);
	if (NULL == p)
	{
		printf("Insufficient memory available\n");//没有足够的空间
		return;
	}
	for (int i = 0; i < num; i++)
	{
		*(p + i) = i + 1;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	free(p);
	p = NULL;

	return 0;
}
*/
/*
int main()
{
	char str[] = "This a sam,ple string.";
	char *sep = " ,";
	printf("%s\n", str);
	char *pch = strtok(str, sep);
	while (*pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, sep);
	}


	return 0;
}
*/