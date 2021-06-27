#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

void test()
{
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a)); //16
	//printf("%d\n", sizeof(a + 0));//4
	//printf("%d\n", sizeof(*a)); //4
	//printf("%d\n", sizeof(a + 1));//4
	//printf("%d\n", sizeof(a[1]));//4
	//printf("%d\n", sizeof(&a)); //4
	//printf("%d\n", sizeof(*&a)); //16
	//printf("%d\n", sizeof(&a + 1));//4
	//printf("%d\n", sizeof(&a[0]));//4
	//printf("%d\n", sizeof(&a[0] + 1));//4

	//字符数组 
	//char arr[] = {'a','b','c','d','e','f'}; 
	//printf("%d\n", sizeof(arr)); //6
	//printf("%d\n", sizeof(arr+0));//4
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4
	//printf("%d\n", sizeof(&arr + 1));//4
	//printf("%d\n", sizeof(&arr[0] + 1));//4
	//printf("%d\n", strlen(arr));//随机值
	//printf("%d\n", strlen(arr + 0));//随机值
	//printf("%d\n", strlen(*arr));//error
	//printf("%d\n", strlen(arr[1])); //error
	//printf("%d\n", strlen(&arr));//随机值
	//printf("%d\n", strlen(&arr + 1));//随机值
	//printf("%d\n", strlen(&arr[0] + 1));//随机值

	//char* p = "abcdef";
	////printf("%d\n", sizeof(p));//4
	////printf("%d\n", sizeof(p + 1));//4 
	////printf("%d\n", sizeof(*p));//1
	////printf("%d\n", sizeof(p[0]));//1
	////printf("%d\n", sizeof(&p));//4
	////printf("%d\n", sizeof(&p + 1));//4
	////printf("%d\n", sizeof(&p[0] + 1));//4

	//printf("%d\n", strlen(p)); //6
	//printf("%d\n", strlen(p + 1));//5
	////printf("%d\n", strlen(*p)); //error
	////printf("%d\n", strlen(p[0]));//error
	//printf("%d\n", strlen(&p));//随机值
	//printf("%d\n", strlen(&p + 1));//随机值
	//printf("%d\n", strlen(&p[0] + 1));//5

	//二维数组 
	//int a[3][4] = {0};
	//printf("%d\n",sizeof(a));//48
	//printf("%d\n",sizeof(a[0][0])); //4
	//printf("%d\n",sizeof(a[0])); //16
	//printf("%d\n",sizeof(a[0]+1));//4
	//printf("%d\n",sizeof(*(a[0]+1))); //4
	//printf("%d\n",sizeof(a+1));//4
	//printf("%d\n",sizeof(*(a+1)));//16
	//printf("%d\n",sizeof(&a[0]+1)); //4
	//printf("%d\n",sizeof(*(&a[0]+1)));//16
	//printf("%d\n",sizeof(*a));//16
}

//strlen
int Strlen(char* str)
{
	assert(str);
	char* tmp = str;
	while (*tmp)
	{
		++tmp;
	}
	return tmp - str;
}

char* Strcpy(char* dest, char* src)
{
	assert(dest);
	assert(src);
	while (*src)
	{
		*dest++ = *src++;
	}
	return dest;
}

char* Strcat(char* dest, char* src)
{
	assert(dest);
	assert(src);
	char* res = dest;
	while (*dest)
		++dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	return res;
}

void* Memcpy(void* dest, const void* src, int cnt)
{
	assert(dest);
	assert(src);

	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	while (cnt--)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}

void* Memmove(void* dest, const void* src, int cnt)
{
	assert(dest);
	assert(src);

	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	
	if (pdest > psrc && pdest < (psrc + cnt))
	{
		pdest += cnt - 1;
		psrc += cnt - 1;
		while (cnt--)
		{
			*pdest-- = *psrc--;
		}
	}
	else
	{
		while (cnt--)
		{
			*pdest++ = *psrc++;
		}
	}

	return dest;
}

int my_atoi(const char* str)
{
	assert(str);
	int flag = 1;
	int res = 0;
	while (isspace(*str))
		++str;

	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		++str;

	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res < 0)//越界处理
			res = INT_MAX;
		++str;
	}
	return flag * res;
}

void fun()
{
	union 
	{
		int i;
		char c;
	}un;

	un.i = 1;
	if (un.c)
		printf("%d", 1);
}
int main()
{
	/*char* str = "whiteshirti";
	Strlen(str);
	test();*/
	//char dest[20] = { 0 };
	//char src[] = "whiteshirti";
	//Strcpy(dest, src);
	/*char* res = Strcat(dest, src);*/
	//Memcpy(src+1, src, 5);
	//Memmove(src+1, src, 5);
	//char* str = "-123456789987654";
	//int res = my_atoi(str);
	//long long res1 = atoi(str);
	fun();
	return 0;
}