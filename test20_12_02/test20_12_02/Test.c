#include<stdio.h>
#include<string.h>
#include<assert.h>

/*一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。编写一个函数找出这两个只出现一次的数字。
void finddog(int *arr, int size)
{
	int res = 0;
	int pos= 0;
	int x = 0;
	int y = 0;

	for (int i = 0; i < size; i++)
	{
		res ^= arr[i]; //0110^1000=1110
	}

	for (int i = 0; i < 32; i++)
	{
		if (((res >> i) & 1) == 1)
		{
			pos = i;//3
		}
	}
	for (int i = 0; i < size; i++)
	{
		//这可以将两个不同的数分开 
		if (((arr[i] >> pos) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}

	printf("%d %d\n", x, y);

}

int main()
{
	int arr[] = { 1,3,3,5,5,1,6,4 };
	
	int size = sizeof(arr) / sizeof(int);
	finddog(arr, size);

}
*/
/*模拟实现strncmp
int my_strncmp(char *dest, char *src, int count)
{
	assert(dest);
	assert(src);

	while (count-- && *dest==*src)
	{
		if ((*dest-*src)!=0)
			break;
		dest++;
		src++;

	}
	return *dest - *src;
}

int main()
{
	char dest[] = "worldd";
	char src[] = "world";
	int size = 5;
	int res = my_strncmp(dest, src, size);

	printf("%d\n", res);

	return 0;
}
*/
/*模拟实现strncmp
char *my_strncpy(char *dest, char *src, size_t count)
{
	assert(dest);
	assert(src);

	char *pdest = dest;
	char *psrc = src;

	while (count--)
	{
		*pdest++ = *psrc++;
	}
	*pdest = '\0';
	return dest;
}

int main()
{
	char dest[20] = { 0 };
	char src[] = "world";
	int size = 4;
	char *str = my_strncpy(dest, src, size);

	printf("%s\n", str);

	return 0;
}
*/
/*模拟实现strncat
char *my_strncat(char *dest, char *src, size_t size)
{
	assert(dest != NULL);
	assert(src != NULL);

	char *pdest = dest;
	char *psrc = src;
	
	while (*pdest)
	{
		pdest++;
	}
	while (size--)
	{
		*pdest++ = *psrc++;
	}

	return dest;
}

int main()
{
	char dest[20] = "hello ";
	char src[] = "world";
	int size = strlen(src);

	char *str = my_strncat(dest, src, size);

	printf("%s\n", str);

	return 0;
}
*/