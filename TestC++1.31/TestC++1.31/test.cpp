#include <iostream>
#include "test.h"
using namespace std;

//inline int fun(int a, int b)
//{
//	return a * b;
//}
//
//int main()
//{
//	fun(10, 20);
//
//	return 0;
//}

//int main()
//{
//	auto a = 1;
//	auto b = 2.0;
//	auto c = 'a';
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	return 0;
//}

//void fun(auto a) {}

//void fun(int arr[], int n)
//{
//	for (const auto& num : arr)
//	{
//		cout << " " << num;
//	}
//}

//int main()
//{
//	//auto a = 1;
//	////通过对变量取地址推导出指针
//	//auto pa = &a;
//	////明确pa2为指针类型，与上面用法结果一样
//	//auto* pa2 = &a;
//
//	////不能推导出是引用，只能推导出与a同类型的类型
//	//auto ra = a;
//	//ra = 2;
//	//cout << a << endl;
//	////明确ra2是一个引用，与a类型相同的引用
//	//auto& ra2 = a;
//	//ra2 = 3;
//	//cout << a << endl;
//	//cout << typeid(a).name() << endl;
//	//cout << typeid(pa).name() << endl;
//	//cout << typeid(pa2).name() << endl;
//
//
//	//auto a = 1, b = 2, c = 3.0;
//
//	//auto arr[] = { 0, 1, 2, 3};
//
//	/*int arr[] = { 0, 1, 2, 3 , 4, 5, 6, 7, 8, 9, 10 };
//
//	int n = sizeof(arr) / sizeof(int);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << " " << arr[i];
//	}
//	cout << endl;
//	for (int num : arr)
//	{
//		cout << " " << num;
//	}
//	cout << endl;
//	for (const auto& num : arr)
//	{
//		cout << " " << num;
//	}*/
//
//	int* pa = 0;
//	int* pb = NULL;
//	int* pc = nullptr;
//	return 0;
//}

void fun(int a)
{
	cout << "fun(int)"<< endl;
}

void fun(int* a)
{
	cout << "fun(int*)" << endl;
}

int main()
{

	fun(0);
	fun(NULL);
	fun(nullptr);

	return 0;
}