#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	int _a;
};
class B : virtual public A
{
public:
	int _b;
};
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};

void test()
{
	D d;
	d.B::_a = 1;
	d._b = 2;
	d.C::_a = 3;
	d._c = 4;
	d._d = 5;
}

//class Person
//{
//public:
//	string _name;
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id;
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//
//void test()
//{
//	Assistant a;
//	a._name = "WhiteShirtI";
//	cout << a._name << endl;
//}

//class Person
//{
//public:
//	string _name;
//};
//
//class Student : public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id;
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};

//void test()
//{
//	Assistant a;
//	a._name = "abcd";
//}

//class A
//{
//public:
//	A()
//	{
//		++_a;
//	}
//	static int _a;
//};
//int A::_a = 0;
//
//class B : public A
//{};
//
//void test()
//{
//	A a;
//	B b;
//	cout << a._a << endl;
//	cout << b._a << endl;
//	cout << &a._a << endl;
//	cout << &b._a << endl;
//}
//class Person
//{
//public:
//	Person(int id = 1, int age = 21)
//		:_id(id)
//		, _age(age)
//	{
//		cout << "Person(int, int)" << endl;
//	}
//	~Person()
//	{
//		cout << "~Person" << endl;
//	}
//protected:
//	int _id;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student(int id = 2, int age = 22, int stuId = 102)
//		:Person(id, age)
//		,_stuId(stuId)
//	{
//		cout << "Student(int, int, int)" << endl;
//	}
//	~Student()
//	{
//		cout << "~Student" << endl;
//	}
//private:
//	int _stuId = 101;
//};
//
//void test()
//{
//	Student stu;
//}

//class A
//{
//public:
//	void print()
//	{
//		cout << "A::print()" << endl;
//	}
//protected:
//	int _val = 1;
//};
//
//class B : public A
//{
//public:
//	void print()
//	{
//		cout << "B::print()" << endl;
//	}
//	void printVal()
//	{
//		cout << _val << endl;
//		cout << A::_val << endl;
//	}
//private:
//	int _val = 2;
//};

//void test()
//{
//	B b;
//	b.print(); //B::print()
//	b.A::print();//A::print()
//	b.printVal();//2 1
//}
//class Person
//{
//public:
//	void printP()
//	{
//		cout << "name = " << _name << endl;
//		cout << "age = " << _age << endl;
//	}
//protected: 
//	string _name = "WhiteShirtI"; 
//	int _age = 21;
//};
//
//class Student : public Person
//{
//public:
//	void printS()
//	{
//		cout << "name = " << _name << endl;
//		cout << "age = " << _age << endl;
//		cout << "stuId = " << _stuId << endl;
//	}
//private:
//	int _stuId = 101;
//};
//
//void test()
//{
//	Student stu;
//	Person p;
//	//父类赋值给子类
//	stu = p;//error，p中没有stuId属性，赋值属性缺失，编译器不支持
//	//父类的引用和指针不能直接赋值给子类的引用和指针
//	Student& rp = p;//error
//	Student* pp = &p;//error
//	//如果要赋值必须通过强制类型转换赋值
//	//但是存在风险，不建议，可能会产生非法访问的问题
//	Student& rp = (Student&)p;//ok
//	Student* pp = (Student*)&p;//ok
//	//当pp去访问自己的stuId时其实就是一个非法访问
//	//在p中并没有这个属性，编译器没有给这个属性分配空间
//}
//class A
//{
//private:
//	int _a = 1;
//};
//
//class B :public A
//{
//public:
//	void printA()
//	{
//		cout << _a << endl;
//	}
//};
//
//void test()
//{
//	cout << sizeof(A) << endl;//4
//	cout << sizeof(B) << endl;//8
//}

int main()
{	
	test();

	return 0;
}