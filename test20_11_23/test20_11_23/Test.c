#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

struct MyStruct
{
	int i; // (0) + 4 = 4，后面一个为2，已经对齐
	char c;  // (4) + 1 = 5,后面一个为结构体，直接拆开看第一个，int=4，所以对齐为(4) + 4 = 8
	struct InnerStruct
	{
		int i;  // (8) + 4 = 12，下一个为4，已经对齐（学java注意了，32位下C语言的long为4，和java不一样）
		long l;  //  (12) + 4 = 16，下一个为8，已经对齐
		double d;  //  (16) + 8 = 24，下一个为1，已经对齐
		char c;  //  (24) + 1 = 25，这是最后一个，将其对齐为最大值8的倍数，所以补齐为 (24) + 8 = 32，最后结果=32
	} innerStruct;
}MyStruct;


struct Test
{
	short a; //4
	
	struct
	{
		int b;  //8
		double c; //16
		long d;//20
	};
	int e;//4
}Test;


struct Test2
{
	int b;
	double c;
	long d;
}Test2;

int main()
{
	printf("size = %d\n", sizeof(Test2));

	return 0;
}


/*
struct S3
{
	double d; //8
	char c; //1
	int i;//4+3
}S3;
int main()
{
	printf("size = %d\n", sizeof(S3));

	return 0;
}
*/

/*
struct S2
{
	char c1; //1
	char c2; //1+2
	int i;
}S2;
int main()
{
	printf("size = %d\n", sizeof(S2));

	return 0;
}
*/
/*
struct S1
{
	char c1;
	int i;
	char c2;
}S1;

int main()
{
	printf("size = %d\n", sizeof(S1));

	return 0;
}
*/

/*
//#pragma pack(2)
struct Test
{
	double c;  //8
	char a;   //1+3
	int b;	  //4
	
}Test;

int main()
{
	printf("size = %d\n", sizeof(Test));

	return 0;
}
*/


/*
int main()
{
	char *str = "123";

	int num = atoi(str);
	printf("%d \n", num); //123

	return 0;
}
*/


/*
int main(int argc,char *argv[])
{
	printf("argc=%d\n", argc);
	for (int i = 0; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}

	return 0;
}
*/

/*
int main()
{
	char string[] = "A string\tof ,,tokens\nand some  more tokens";
	char seps[] = " ,\t\n";
	char *token;
	printf("Tokens:\n");

	token = strtok(string, seps); 
	while (token != NULL)
	{
		printf(" %s\n", token);

		token = strtok(NULL, seps);
	}
}
*/


/*
char *my_strstr(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);

	const char *pstr1 = str1;
	const char *p = pstr1;
	const char *pstr2 = str2;

	while (*p != '\0')
	{
		pstr1 = p;
		pstr2 = str2;

		while (*pstr1 != '\0' && *pstr2 != '\0' && *pstr1 == *pstr2)
		{
			pstr1++;
			pstr2++;
			if (*pstr2=='\0')
			{
				return p;
			}
		}
		p++;
	}
	return NULL;
}

int main()
{
	char *str1 = "abcdefghijkl";
	char *str2 = "def";

	char *str3 = my_strstr(str1, str2);

	printf("%s\n", str3);

	return 0;
}
*/

/*
int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };//指针数组

	char**cp[] = { c + 3, c + 2, c + 1, c };

	char***cpp = cp;

	printf("%s\n", **++cpp); //POINT

	printf("%s\n", *--*++cpp + 3); //ER

	printf("%s\n", *cpp[-2] + 3); //ST

	printf("%s\n", cpp[-1][-1] + 1);//EW

	return 0;
}
*/