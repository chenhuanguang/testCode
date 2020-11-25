#include<stdio.h>

union un
{
	int i;
	char ch;
};

int main()
{

	union un un;
	un.i = 1;
	un.ch = 2;
	return 0;
}

/*
struct Test
{
	int a;  //4
	short b[5];  //5+7
	double c[6];//48
	long d; //4+4
}Test;

int main()
{
	printf("size = %d\n", sizeof(Test)); //72

	return 0;
}
*/
/*
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };
	s.a = 10; //1010
	s.b = 12; //1100
	s.c = 3;  //0011
	s.d = 4;  //0100
	return 0;

}
*/

/*
#pragma pack(2)

typedef struct Test
{
	short a;
	struct t //14
	{
		int b;
		double c;
		char d;
	};
	int e;
}Test;

int main()
{

	printf("size = %d\n", sizeof(Test));
	return 0;
	
}
*/
/*
typedef struct Test
{
	short a;
	struct   //4+4+80+1+7=96
	{
		int b; //数组只要跟类型的大小对齐
		double c[10];//80
		char d;
	};
	int e;
}Test;

int main()
{

	printf("size = %d\n", sizeof(Test));
	return 0;
}
*/