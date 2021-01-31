#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//struct A
//{
//	void SetStudentInfo(const char* name, const char* gender, int age) 
//	{
//		strcpy(_name, name); 
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//	char _name[20]; 
//	char _gender[3]; 
//	int _age;
//};

//struct Student
//{
//public:
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//int main()
//{
//	Student s;
//	s.SetStudentInfo("白衬衫i", "男", 22);
//	s.PrintStudentInfo();
//	return 0;
//}

class A
{
public:
	void print()
	{
		cout << "A::print()" << endl;
	}
private:
	int _a;
};

class B
{
private:
	int _b;
};
class C
{
public:
	void print()
	{
		cout << "C::print()" << endl;
	}
};
class D
{};

int main()
{
	cout << "有函数有属性：" << sizeof(A) << endl;
	cout << "有属性没函数：" << sizeof(B) << endl;
	cout << "有函数没属性：" << sizeof(C) << endl;
	cout << "空类：" << sizeof(D) << endl;
}