#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

/*
int main()
{

	for (int A = 1; A <= 5; A++)
	{
		for (int B = 1; B<= 5; B++)
		{
			for (int C = 1; C <= 5; C++)
			{
				for (int D = 1; D <= 5; D++)
				{
					for (int E = 1; E <= 5; E++)
					{
						if (A*B*C*D*E==120)
						{
							if (((A == 3) + (B == 2) == 1) &&
								((E == 4) + (B == 2) == 1) &&
								((D == 2) + (C == 1) == 1) &&
								((C == 5) + (D == 3) == 1) &&
								((E == 4) + (A == 1) == 1))
							{
								printf("名次为A:%d B:%d C:%d D:%d E:%d\n", A, B, C, D, E);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
*/

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词 :
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

/*
int main()
{
	for (char k='A' ; k <= 'D'; k++)
	{
		int A = (k!= 'A') ? 1 : 0;
		int B = (k== 'C') ? 1 : 0;
		int C = (k== 'D') ? 1 : 0;
		int D = (k!= 'D') ? 1 : 0;

		if ((A + B + C + D) == 3)
		{
			printf("杀手是： %C\n", k);
		}
	}
}
*/

/*杨辉三角
#define ROW 10
#define COL 10
int main()
{
	int arr[ROW][COL] = { 0 };
	int size = sizeof(arr) / sizeof(int);
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/


/*255
int main()
{
	char a[1000] = { 0 };
	int i = 0;
	for (i = 0; i<1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}
*/


/*模拟实现memmove
void *my_memmove(const void* dest, const void *src, size_t count)
{
	assert(dest != NULL&&src != NULL);
	char *pdest = (char *)dest;
	const char *psrc = (const char*)src;

	if (pdest>psrc&&pdest<(psrc+count))
	{
		psrc = psrc + count - 1;
		pdest = pdest + count - 1;
		while (count-- > 0)
		{
			*pdest-- = *psrc--;
		}
	}
	else
	{
		while (count-- > 0)
		{
			*pdest++ = *psrc++;
		}
	}
	return dest;
}

int main()
{
	char str[20] = "helloworld";
	int count = 4;
	my_memmove(str + 2, str, count);
	printf("%s\n", str);

	return 0;
}
*/


/*模拟实现memcpy
void *my_memcpy(const void *dest, const void *src,size_t count)
{
	assert(dest != NULL&&src != NULL);
	char*pdest = (char*)dest;
	const char*psrc = (const char*)src;

	while (count-- > 0)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}

int main()
{
	char dest[20] = {0};
	char *src = "hello world";
	int count = 3;
	my_memcpy(dest, src,count);
	printf("%s\n", dest);

	return 0;
}
*/


/*
void main()
{
	union
	{
		short k;
		char i[2];
	}*s,a;

	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;

	printf("%x\n", a.k); //3839
}
*/


/*判断计算式存储是大端还是小端
int check_sys()
{
	int i = 1;
	return (*(char *)&i);
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
*/


/*模拟实现strstr
char *my_strstr(const char *str, const char *str2)
{
	assert(str != NULL && str2 != NULL);
	char *pstr = str;
	char *p = pstr;
	char *pstr2 = str2;
	

	while (*p!='\0')
	{
		pstr = p;
		pstr2 = str2;

		while ((*pstr != '\0') && (*pstr2 != '\0') && *pstr == *pstr2)
		{
			pstr++;
			pstr2++;
		}

		if (*pstr2 == '\0')
		{
			return p;
		}
		p++;

	}
	return NULL;

}

int main()
{
	char str[20] = "abcdefgh";

	char *p;
	p= my_strstr(str, "def");

	printf("str3 = %s\n", p);

	return 0;
}
*/


/*模拟实现strcat
char *my_strcat(char *dest, const char *src)
{
	assert(dest != NULL && src != NULL);

	char *pdest = dest;
	char *psrc = src;

	while (*pdest != '\0')
	{
		pdest++;
	}
	while (*psrc != '\0')
	{
		*pdest++ = *psrc++;
	}
	*pdest = '\0';

	return dest;
}

int main()
{
	char dest[20] = "abc";
	char *src = "defg";
	printf("dest = %s\n", dest);
	my_strcat(dest, src);
	printf("dest = %s\n", dest);
	return 0;
}
*/


/* 模拟实现strcmp
int my_strcmp(const char *str, const char *str2)
{
	assert(str != NULL && str2 != NULL);
	char *pstr = str;
	char *pstr2 = str2;

	while (*pstr != '\0' || *pstr2 != '\0')
	{
		if (*pstr - *pstr2 != 0)
			break;
		pstr++;
		pstr2++;
	}

	return (*pstr - *pstr2);

}

int main()
{
	char *str = "abcde";
	char *str2 = "abcdef";
	int ret = my_strcmp(str, str2);
	if (ret > 0)
	{
		printf("str > str2");
	}
	else if (ret < 0)
	{
		printf("str < str2");
	}
	else
	{
		printf("str = str2");
	}

	return 0;
}
*/


/*模拟实现strcpy
char *my_strcpy(char *dest, const char *src)
{
	assert(dest != NULL && src!=NULL);

	char *pdest = dest;
	char *psrc = src;

	while (*psrc != '\0')
	{
		*pdest++ = *psrc++;
	}
	*pdest = '\0';
	return dest;
}

int main()
{
	char dest[20] = "abc";
	char *src = "defg";
	printf("dest = %s\n", dest);
	my_strcpy(dest, src);
	printf("dest = %s\n", dest);
	return 0;
}
*/


/* 模拟实现strlen
int my_strlen(const char *str)
{
	assert(str != NULL);
	int len=0;
	char *pstr = str;

	while (*pstr != '\0')
	{
		pstr++;
		len++;
	}
	return len;
}

int main()
{
	char *str = "abcdefg";

	int size = my_strlen(str);
	printf("%d \n", size);

	return 0;
}
*/