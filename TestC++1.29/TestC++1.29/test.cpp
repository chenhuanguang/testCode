#include <iostream>
using namespace std;

//int funtion1(int a, int b)
//{
//	return a + b;
//}
//
//int funtion2(double a, double b)
//{
//	return a + b;
//}
////int funtion(int a, int b)
////{
////	return a + b;
////}
////
////int funtion(double a, double b)
////{
////	return a + b;
////}
////
////int funtion(int a, double b)
////{
////	return a + b;
////}
//
//extern "C" int funtion(int a, int b)
//{
//	return a + b;
//}
//
//double funtion(double a, double b)
//{
//	return a + b;
//}
//
//int main()
//{
//	funtion1(1.01, 2.02);
//	funtion2(10, 1.02);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//
//	int b = 20;
//	//将b的值赋给ra
//	ra = b; //ra = 20
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	//编译报错
//	int& ra = a;
//	//编译通过
//	const int& ra2 = a;
//
//	return 0;
//}

//int main()
//{
//	double b = 12.34;
//	const int& c = b;
//
//	return 0;
//}


//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << "a = " << a << " b = " << b << endl;
//
//	return 0;
//}

//int& funtion(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& res = funtion(a, b);
//	cout << "res = " << res << endl;
//
//	return 0;
//}

//int& funtion(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& res = funtion(a, b);
//	cout << "res = " << res << endl;
//	cout << "res = " << res << endl;
//
//
//	return 0;
//}

#include <time.h> 
//struct A
//{
//	int a[10000];
//};
//void fun1(A a) {}
//void fun2(A& a) {}

//struct A
//{
//	int a[10000]; 
//};
//A a;
//// 值返回 
//A* fun1() 
//{ 
//	return &a;
//} 
//// 引用返回 
//A& fun2()
//{
//	return a;
//}
//
//int main() 
//{
//
//	int n = 0;
//	cout << "循环次数 ：";
//	cin >> n;
//	// 以值作为函数返回值
//	int begin = clock();
//	for (int i = 0; i < n; ++i)
//		fun1();
//	int end = clock();
//	cout << "以值作为函数参数：fun1() time :" << end - begin << endl;
//
//	// 以引用作为函数返回值
//	 begin = clock();
//	for (int i = 0; i < n; ++i)
//		fun2();
//	 end = clock();
//	cout << "以引用作为函数参数 ：fun2() time :" << end - begin << endl;
//
//	return 0;
//}

int main()
{
	int a = 10;
	int& ra = a;

	int b = 10;
	int* pb = &b;

	return 0;
}