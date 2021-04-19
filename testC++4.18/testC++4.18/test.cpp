#include <iostream>
#include "fun.h"
using namespace std;

int main()
{
	fun(1);
	return 0;
}

//#include <iostream>
//#include <array>
//#include <string>
//using namespace std;

//void test()
//{
//	//定义10个int类型的静态数组
//	//这是在栈上申请的，第二个值不宜太大
//	//array<class T, size_t N>
//	array<int, 2> arr;
//	int sz = arr.size();
//	cout << sz << endl;
//}

//template<class T>
//bool isEqual(T a, T b)
//{
//	return a == b;
//}
//
////特化模板
//template<>
//bool isEqual<char*>(char* a, char* b)
//{
//	return strcmp(a, b) == 0;
//}
//
//void test()
//{
//
//	char ptr1[] = "123";
//	char ptr2[] = "123";
//	int ret = isEqual(ptr1, ptr2);
//	cout << ret << endl;
//}

//通用类模板
//template<class T1, class T2>
//class D
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1, T2)" << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
//
////类模板特化
//template<>
//class D<int, char>
//{
//public:
//	D(const int& d1, const char& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(int, char)" << endl;
//	}
//	int _d1;
//	char _d2;
//};
//
////类模板偏特化
//template<class T1>
//class D<T1, double>
//{
//public:
//	D(const T1& d1, const double& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1, double)" << endl;
//	}
//	T1 _d1;
//	double _d2;
//};
//
////限制作用
//template<class T1, class T2>
//class D<T1*, T2*>
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1*, T2*)" << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
//
//void test()
//{
//	//调用通用模板
//	D<int, int> d1(1, 2);
//	//调用特化模板
//	D<int, char> d2(1, 'a');
//	//调用偏特化模板
//	D<int, double> d3(1, 2.2);
//	//调用偏特化模板
//	D<int*, int*> d4(1, 2);
//}

//int main()
//{
//	test();
//	return 0;
//}