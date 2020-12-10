#include<iostream>
using namespace std;

//int main()
//{
//	//权限缩小和放大规则：适用于引用和指针之间
//	//权限放大 不能把const给非const
//	const int a = 10;
//	//int& b = a;
//
//	//权限缩小 非const可以给const，也可以给const
//	int c = 20;
//	int& d = c;
//	const int& e = c;
//
//	const int*cp = &a;
//	//int* p = cp; 权限放大 错误
//
//	int* p2 = &c;
//	const int* cp2 = p2;//可以，权限缩小
//
//	const int x = 10;
//	int y = x;
//	
//}

//1、引用做参数
//void swap_cpp(int& n1, int& n2)
//{
//	int temp = n1;
//	n1 = n2;
//	n2 = temp;
//}
//
//int main()
//{
//
//	int a = 0, b = 1;
//	swap_cpp(a, b);
//
//}

//2、引用做返回值


//int Count1()
//{
//	static int n = 0;
//		n++;
//	// ...
//	return n;
//}
//
//int& Count2()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	//const int& num1 = Count1();
//	int& num2 = Count2();
//
//	int num = Count1();
//
//	return 0;
//}

//不安全
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	//函数Add直接成为ret的别名 
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//int& Add(int a, int b)
//{
//	static int c = a + b; //此初始化只执行一次
//	return c;
//}
//int main()
//{
//	//函数Add直接成为ret的别名 
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}
//总结:一个函数要使用引用返回，返回变量出了这个函数的作用域还存在
//就可以使用引用返回，否则不安全。
//函数使用引用返回好处：少创建拷贝一个临时对象，提高效率

//提高效率--传值
/*
#include <time.h>

struct A {
	int a[10000];
};
void TestFunc1(A a) 
{
}
void TestFunc2(A& a) 
{
}
void main()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;//慢
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//快
}
*/

//提高效率--返回值
//#include <time.h>
//struct A {
//	int a[10000]; 
//};
//A a;
//// 值返回
//A TestFunc1()
//{
//	return a;
//}
//// 引用返回
//A& TestFunc2() 
//{ 
//	return a; 
//}
//void main()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;//b的类型是根据a的类型推导出int
//	int& c = b;
//	const char& d = c;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name()<< endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	//数据的值乘2再打印一遍
//	//C++11
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//
//
//	return 0;
//}

//int main()
//{
//	//C
//	int* p1 = NULL;
//
//	//C++中，推荐这样用
//	int* p2 = nullptr;
//}


//类
//class Person
//{
//	void Print()
//	{
//
//	}
//
//	char _name[10];
//	int _age;
//
//};

class Student
{
public:
	void ShowInfo()
	{
		cout << _name << endl;
		cout << _age << endl;
		cout << _stuid << endl;

	}

private:	//一般情况下成员变量都是比较隐私的，被定义成私有的或者被保护
	char _name[20];
	int _age;
	int _stuid;
};

int main()
{
	Student s1;
	Student s2;

	s1.ShowInfo();

	return 0;
}