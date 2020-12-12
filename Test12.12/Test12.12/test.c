#include<stdio.h>
#include<stdbool.h>
#include<string.h>

//bool checkRecord(char * s)
//{
//	if (s == NULL)
//		return false;
//	int a = 0, l = 0;
//	char *ps = s;
//	char *ps2 = ps;
//	while (*ps!='\0')
//	{
//		if (*ps == 'A')
//		{
//			a++;
//		}
//		if (a == 2)
//			return false;
//		if (*ps == 'L'&& *ps2!='L')
//		{
//			ps2 = ps;
//			l++;
//		}
//		else if (*ps == 'L'&& *ps2 == 'L')
//		{
//			l++;
//			if (l >= 3)
//				return false;
//		}
//		if (*ps != 'L')
//		{
//			ps2 = ps;
//			l = 0;
//		}
//			
//		
//		ps++;
//	}
//	return true;
//}

//bool checkRecord(char * s)
//{
//	int len = strlen(s);
//
//	for (int i = 0; i < len - 2; ++i)
//	{
//		if (s[i] == 'L'&&s[i + 1] == 'L'&&s[i + 2] == 'L')
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	char *s = "LALL";
//	int flag = checkRecord(s);
//	printf("%d \n", flag);
//	return 0;
//}

int reverse(int x)
{
	long sum = 0;
	while (x != 0)
	{
		sum = sum * 10 + x % 10;
		x=x / 10;
	}
	if ((int)sum != sum)
		return 0;
	return (int)sum;
}

int main()
{
	int n =reverse(2147483648);
	printf("%d \n", n);
	return 0;
}


