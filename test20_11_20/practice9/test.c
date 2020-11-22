#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define true 1
#define false 0

#define N 4

int  YangSearch(int a[][N], int M, int key, int *i, int *j)
{
	if (key<a[0][0] || key>a[M - 1][N - 1])
		return false;
	int row = 0;
	int col = N - 1;
	while (row < M&&col >= 0)
	{
		if (key == a[row][col])
		{
			*i = row;
			*j = col;
			return true;
		}
		else if (key > a[row][col])
		{
			row++;
		}
		else if (key < a[row][col])
		{
			col--;
		}
	}
	return false;
}


int main(void)
{
	int a[4][4] = { { 1, 5, 7, 9 }, { 4, 6, 10, 15 }, { 8, 11, 12, 19 }, { 14, 16, 18, 21 } };
	int i = -1;
	int j = -1;
	int key = 12;
	int b = YangSearch(a, 4, key, &i, &j);
	if (b)
	{
		printf("查找到%d，位置为%d,%d\n", key, i, j);
	}
}


//实现一个函数，可以左旋字符串中的k个字符。
//
//例如：
//
//ABCD左旋一个字符得到BCDA
//
//ABCD左旋两个字符得到CDAB

/*
void revolveStr(char *str1, int len, int k)
{
	char s[20];
	strncpy(s, str1, k);
	strcpy(str1, str1 + k);
	strncpy(str1 + len-k, s,k);

}

int main()		
{
	char str1[] = "AABCD";
	int len = strlen(str1);
	revolveStr(str1, len, 3);

	printf("%s", str1);

	return 0;
}
*/
/*
void revolveStr(char *str1, int len,int k)
{

	for (int i = 0; i < k; i++)
	{
		char tmp = str1[0];
		for (int j = 0; j < len; j++)
		{	
			str1[j] = str1[j + 1];
		}
		str1[len - 1] = tmp;
	}
}

int main()
{
	char str1[] = "AABCD";
	int len = strlen(str1);
	revolveStr(str1, len, 3);

	printf("%s", str1);

	return 0;
}*/
//字符串旋转结果
//作业内容
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

/*

int revolveStr(char *str1, char *str2,int len)
{
	
	while (_stricmp(str1, str2)!=0)
	{
		char tmp = *(str1+len - 1);
		*(str1 + len - 1) = *str1;
		int i;
		for ( i= 0; i < len-2; i++)
		{
			*(str1+i) = *(str1+i+1);
		}
		*(str1 + len - 2) = tmp;
		if (_stricmp(str1, str2) == 0)
			return 1;
		if (i == len - 2)
			break;

	}
	return 0;
	
}

int main()
{
	char str1[] = "AABCD";
	char str2[] = "ABCDA";

	int len = strlen(str1);

	printf("%d \n", revolveStr(str1, str2,len));

	return 0;
}

*/
/*
int int_cmp(const void *a, const void *b)
{
	return (*(int*)a) - (*(int*)b);
}

int double_cmp(const void *a, const void *b)
{
	return (int)((*(double*)a) - (*(double*)b));
}

int str_cmp(const void *a, const void *b)
{
	return _stricmp( *(char**)a,*(char**)b );
}

int char_cmp(const void *a, const void *b)
{
	return  (*(char*)a) - (*(char*)b);
}


int main()
{
	int arr[] = { 9, 6, 4, 2, 1, 4, 7, 8, 2 };
	//char arr[] = { 'a', 'b', 'd', 'c', 'a' };
	//double arr[] = { 9.0, 7.0, 5.0, 3.0, 1.0, 2.0, 4.0, 6.0, 20.0, 8.0 };
	//char *arr[] = { "abc","def","ghi","gha" };
	int num = sizeof(arr) / sizeof(arr[0]);
	int size = sizeof(arr[0]);
	qsort(arr, num, size, int_cmp);

	for (int i = 0; i < num; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/