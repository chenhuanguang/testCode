#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A
{
public:
	void fun(int a)
	{
		[this]() {return this->_a; };
	}
private:
	int _a;
};

void test()
{
	int a = 10;
	int b = 20;
	auto fun = [=](int c) ->int{return a + b + c; };
	auto fun1 = [&](int c) ->int {return a + b + c; };
	auto fun2 = [&a](int c) ->int {return a + c; };
	auto fun3 = [=, &a](int c) ->int {return a + b + c;};
	auto fun4 = [&, a](int c) ->int {return a + b + c; };
}

//void test()
//{
//	int a = 10;
//	int b = 20;
//	[a, b] {return a + b; };
//	[a, b](int c) {return a + b + c; };
//	[a, b](int c) ->int{return a + b + c; };
//	[a, b]()mutable{a = 100; b = 200; };
//	[] {};
//}

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; } 
//void Fun(const int& x) { cout << "const类型的左值引用" << endl; } 
//void Fun(const int&& x) { cout << "const类型的右值引用" << endl; }
//template<typename T> 
//void PerfectForward(T&& t) 
//{ 
//	Fun(std::forward<T>(t)); //完美转发std::forward<T>(name)
//}
//void test() {
//	PerfectForward(10); // 右值引用
//	int a = 4;
//	PerfectForward(a); // 左值引用
//	PerfectForward(std::move(a)); // 右值引用
//	const int b = 8;
//	PerfectForward(b); // const类型的左值引用
//	PerfectForward(std::move(b)); // const类型的右值引用
//}

//void test()
//{
//	int a = 10;
//	int&& rra = move(a);//ok
//}

//class String {
//public:
//	String(const char* str = "") {
//		if (nullptr == str) 
//			str = "";
//		_str = new char[strlen(str) + 1]; strcpy(_str, str);
//	}
//	String(const String& s) 
//		: _str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//		cout << "String(const String&)" << endl;
//	}
//
//	String(String&& s) 
//		:_str(s._str)
//	{
//		s._str = nullptr;
//		cout << "String(String&&)" << endl;
//	}
//
//	String& operator=(const String& s) {
//		if (this != &s) {
//			char* pTemp = new char[strlen(s._str) + 1]; 
//			strcpy(pTemp, s._str); 
//			delete[] _str; _str = pTemp;
//			cout << "String& operator=(const String&)" << endl;
//		} return *this;
//	}
//
//	String& operator=(String&& s) {
//		if (this != &s) {
//			delete[] _str;
//			_str = s._str;
//			s._str = nullptr;
//			cout << "String& operator=(String&&)" << endl;
//		} return *this;
//	}
//
//	String operator+(const String& s) {
//		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1]; 
//		strcpy(pTemp, _str); 
//		strcpy(pTemp + strlen(_str), s._str); 
//		String strRet(pTemp); 
//		return strRet;
//	}
//	~String() 
//	{ 
//		if (_str) delete[] _str; 
//	}
//private: char* _str;
//};
//void test() {
//	String s1("hello"); 
//	String s2("world"); 
//	String s3(s1 + s2);
//	String s4(s2);
//	s4 = s1 + s2; //右值引用赋值
//}

//void test()
//{
//	int a = 10;
//	int&& rri = 10;//ok
//	int&& rra = a;//error;
//}

//void test()
//{
//	int a = 10;
//	int b = a;//ok a为左值
//	10 = a; //error 10为右值
//
//	int* pa = &a;//ok
//	int* pi = &10;//error
//}

int main()
{
	test();
	return 0; 
}