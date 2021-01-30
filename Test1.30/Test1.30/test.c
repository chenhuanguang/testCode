#include<stdio.h>

//int main()
//{
//	char* p = "abcdefgh", * r;
//	long* q;
//	q = (long*)p;
//	q++;
//	r = (char*)q;
//	printf("%s\n", r);
//
//	return 0;
//}

int main()
{
	char str[] = "ABCD", * p = str;
	printf("%d\n", *(p + 4));

	return 0;
}