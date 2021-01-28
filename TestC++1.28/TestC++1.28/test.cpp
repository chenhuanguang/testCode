#include <iostream>
using namespace std;

////namespace 命名空间 {变量 + 函数}
//namespace N1
//{
//	int a = 1;
//	void fun1()
//	{
//		printf("N1: fun1()\n");
//	}
//
//	//嵌套的命名空间
//	namespace N2
//	{
//		int a;
//		void fun1()
//		{
//			printf("N1: fun1()\n");
//		}
//	}
//
//}
//
////分段定义
//namespace N1
//{
//	int b;
//	void fun2()
//	{
//		printf("N1: fun2()\n");
//	}
//}
//
////int a = 10;
//int main()
//{
//	printf("N1 : a = %d\n", N1::a);
//	N1::fun1();
//	/*using N1::a;
//	using N1::fun1;
//	printf("N1 : a = %d\n", a);
//	fun1();*/
//	using namespace N1;
//	printf("N1 : a = %d\n", a);
//	fun1();
//
//	return 0;
//}
#include <iostream>
using namespace std;
//void fun1(int a)
//{
//	cout << "fun1() : a = " << a << endl;
//}
//
//void fun2(int a = 10)
//{
//	cout << "fun2() : a = " << a << endl;
//}

//void fun1(int a = 1, int b = 2, int c = 3)
//{
//	cout << "fun1() : a = " << a << " b = " << b << " c = " << c << endl;
//}

//void fun1(int a, int b, int c = 3)
//{
//	cout << "fun1() : a = " << a << " b = " << b << " c = " << c << endl;
//}


//void fun(int a = 1);
//void fun(int a = 10){}

//void fun1(int a, int b = 2, int c){}
//void fun2(int a = 1, int b, int c){}
//void fun3(int a = 1, int b = 2, int c){}
//int num = 20;
//
//void fun(int a = num){}
//int main()
//{
//	fun();
//
//	return 0;
//}

int AddInt(int a, int b)
{
	return a + b;
}

char AddChar(char a, char b)
{
	return a + b;
}

double AddDouble(double a, double b)
{
	return a + b;
}

int Add(int a, int b)
{
	return a + b;
}

char Add(char a, char b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

//void fun(int a, char c)
//{
//	cout << "fun(int, char)" << endl;
//}
//
//void fun(char c, int a)
//{
//	cout << "fun(char, int)" << endl;
//}

void fun(int a)
{
	cout << "fun(int)" << endl;
}

void fun(int a, int b)
{
	cout << "fun(int ,int)" << endl;
}
int main()
{
	fun(1);
	fun(1, 2);

	return 0;
}