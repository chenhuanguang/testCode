#include<iostream>
using namespace std;
//
////对象调用const
////class Date
////{
////public:
////	Date(int year = 0, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	//void Print()->void Print(Date* this)
////	void Print() const //->void Print(const Date* this)
////	{
////		cout << _year << "-" << _month << "-" << _day << endl;
////		//不能修改成员变量了，因为const修饰保护了*this
////		//this->_year = 10;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////
////void f(const Date& d)
////{
////	d.Print();
////}
////
////int main()
////{
////	Date d1(2020, 12, 15);
////	f(d1);
////	d1.Print();
////	return 0;
////}
//
////class Date
////{
////public:
////	Date(int year = 0, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	
////	void f1() //void f1(Date* this)
////	{
////		f2(); //this->f2(this) //权限缩小 可以
////	}
////
////	void f2() const //void f2(const Date* this)
////	{
////
////	}
////	void f3() //void f3(Date* this)
////	{
////
////	}
////	void f4() const //void f4(const Date* this)
////	{
////		//f3(); //void f3(this) //权限放大，不可以
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////
////int main()
////{
////	
////	return 0;
////}
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	 Date* operator&() 
//	{
//		cout << "Date* operator&()" << endl;
//		return this;
//		//不想让别人取到对象的地址
//		//return nullptr
//	}
//
//	const Date* operator&() const //const Date* this
//	{
//		cout << "const Date* operator&()" << endl;
//		return this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 12, 15);
//	Date d2(2020, 12, 15);
//	const Date d3;
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	cout << &d3 << endl;
//	return 0;
//}
//#include"Date.h"
//
//void Fun(const Date& d3, const Date& d4)
//{
//	cout << d3 - d4 << endl;
//	cout << (d3 > d4) << endl;
//}
//
//int main()
//{
//	Date d1(2020, 12, 15);
//	Date d2(2020, 12, 24);
//	d1.print();
//	Fun(d1, d2);
//
//	cout << d1 - d2 << endl;
//}

//class Date
//{
//public:
//	/*Date(int year = 0, int month = 1, int day = 1)
//	{
//		//函数体内赋值
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{
//		//初始化列表
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	//可以理解成初始化列表是对象的成员变量的定义的地方
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	//像下面三种都必须要在声明的时候初始化的，就放在初始化列表中
//	//成员变量的声明
//	A _aobj; // 没有 默认构造函数(不用传参就可以调的那种构造函数)
//	int& _ref; // 引用
//	const int _n; // const
//
//	int _x; //不需要声明就初始化
//
//};
//

//
//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//
//
//int main()
//{
//	B b(1, 2); //对象定义
//
//	Date d(1);
//
//	return 0;
//}

//class Date
//{
//public:
//
//	//explicit Date(int year = 0) //不允许Date d2 = 2;发生
//	 Date(int year = 0)
//		:_year(year)
//		
//	{
//		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(1); //构造
//	Date d2 = 2; //隐式类型的转化 构造出tmp(2)+在用tmp拷贝构造d2(tmp)+优化成直接构造
//	Date d3 = d2; //拷贝构造
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//
//	{
//		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 12, 15);
//
//	//C+11
//	Date d2 = { 2020, 12, 16 };//隐式类型转化
//
//	return 0;
//}

//static成员变量
// 设计出一个类，可以寄算这个类总计产生了多少对象
//int n = 0;
//class A
//{
//public:
//	A()
//	{
//		++n;
//	}
//	A(const A& a)
//	{
//		++n;
//	}
//};
//
//A f1(A a)
//{
//	return a;
//}
//
//int main()
//{
//	A a1;
//	A a2;
//
//	f1(a1);
//	n = 1; //谁都可以对n进行修改
//	f1(a2);
//
//	cout << n << endl;
//	return 0;
//}

class A
{
public:
	A()
	{
		++n;
	}
	A(const A& a)
	{
		++n;
	}

	static int GetN() //没有this指针，函数中不能访问非静态的成员 只能访问静态的
	{
		//_a = 10  error 因为没有this
		return n;
	}

private:
	static int n; //声明 不是属于某个对象，是属于类的所有对象，属于这个类
	//n不在对象中，n在静态区
};

int A::n = 0;//定义

A f1(A a)
{
	return a;
}

int main()
{
	A a1;
	A a2;

	f1(a1);
	f1(a2);

	cout << a1.GetN() << endl;
	cout << a2.GetN() << endl;
	cout << A::GetN() << endl;

	//public
	/*cout << a1.n << endl;
	cout << a2.n << endl;
	cout << A::n << endl;
	a1.n = 10;*/

	return 0;
}

