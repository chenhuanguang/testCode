#include<iostream>

using namespace std;

//int main()
//{
//	int num1 = 10;
//	int& num2 = num1;
//
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//	printf("num1地址 = %p\n",&num1);
//	printf("num2地址 = %p\n", &num2);
//
//	return 0;
//}

//int main()
//{
//	int num1 = 10;
//	//int num1; 编译报错
//	int& num2 = num1;
//	int & num3 = num1;
//	int& num4 = num3;
//
//	printf("num1地址 = %p\n", &num1);
//	printf("num2地址 = %p\n", &num2);
//	printf("num3地址 = %p\n", &num3);
//	printf("num4地址 = %p\n", &num4);
//
//	return 0;
//}

//int main()
//{
//
//	const int num1 = 10;
//	int& num2 = num1; //编译出错
//	const int& num3 = num1;//ok
//
//	int num4 = 20;
//	const double num5 = num4; //为什么这个可以编译通过呢？？？
//
//	return 0;
//}

//void Swap(int& num1, int& num2)
//{
//	int tmp = num1;
//	num1 = num2;
//	num2 = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "a = " << a << " b = " << b << endl;
//	Swap(a, b);
//	cout << "a = " << a << " b = " << b << endl;
//
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//		n++;
//	return n;
//}
//
//int main()
//{
//	int num1 = Count();
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
//struct A 
//{ 
//	int a[10000]; 
//};
//void TestFunc1(A a) 
//{}
//void TestFunc2(A& a) 
//{}
//void main()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//#include <time.h>
//struct A { 
//	int a[10000];
//};
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void main()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}

//封装
//1、将数据和方法放到定义一起
//2、把想给你看到的数据给你看，不想给你看的封装起来 访问限定符
//class Stack
//{
//public:
//	//在类里面定义
//	void Push(int x)
//	{
//
//	}
//	//在类里面声明
//	void Pop();
//	bool Empty();
//	
//	//声明不是定义，不占空间。
//private:
//	int *_a;
//	int _size;
//	int _capitity;
//};
//
////类外面定义
//void Stack::Pop()
//{
//
//}
//
////声明是承诺，定义是落实
//
//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//	char _c;
//};
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//
//int main()
//{
//	//类实例化出对象 定义类的成员变量
//	Stack s1;
//	Stack s2;
//	Stack s3;
//	s1.Pop();
//	s1.Push(1);
//	s2.Push(1);
//
//	//对象中只存储成员变量，不存储成员函数 变量之和并考虑内存对齐
//	cout << sizeof(s1) << endl;
//	//一个类实例化成N个对象，每个对象的成员变量都可以存储不同的值
//	//但是调用的函数却都是同一个函数,如果每个对象都存放成员函数，浪费空间
//	
//	// 没有成员变量的类的大小为1 原因：开一个字节不是为了存放数据，而是为了占位，表示存在
//	cout << sizeof(A1) << endl; //8
//	cout << sizeof(A2) << endl; //1
//	cout << sizeof(A3) << endl; //1
//
//	return 0;
//}

//class Date
//{
//public:
//	//this是谁调用这个成员函数，this就指向谁
//	void Init(int year, int month, int day) //Init(Date* this,int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print() //编译器帮助传参了
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	/*
//	void Print(Data* this) //隐含的this指针
//	{
//		cout << this->_year << "-" << this->_month << "-" << this._day << endl;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////this指针是存在栈上的:this指针是一个形参(vs在寄存器上的)
//int main()
//{
//	Date d1;
//	d1.Init(2020, 12, 11); //d1.Init(&d1, 2020, 12, 11);
//	d1.Print(); //d1.Print(&d1);
//	
//
//
//	return 0;
//}

// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->PrintA(); //崩溃
//	p->Show(); //正常
//	//成员函数存在公共的代码段，所以p->Show()这里不会去p指向的对象上找
//	//访问成员函数 才回去找
//
//	A a;
//	a.PrintA(); //p->PrintA(&a)；
//
//}


//class Date
//{
//public:
//	//C++中的默认函数
//	// 构造函数 ->在对象构造时调用的函数，这个函数完成初始化工作
//	Date(int year, int month, int day)// 带参构造
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date() //无参构造
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	//对象实例化自动调用构造函数
//	Date d1(2020, 4, 12); 
//	d1.Print();
//
//	Date d2; //不能加括号
//	d2.Print();
//
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	
//	//没定义构造函数，编译器默认构造无参构造
//	//默认生成无参构造
//	//1、针对内置类型成员变量没有做处理
//	//2、针对自定义类型的成员变量，调用它的构造函数初始化
//
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time t;
//};
//
//
//int main()
//{
//	Date d1; //调用编译器 生成的构造函数
//	d1.Print();
//
//	return 0;
//}
//
//class Date
//{
//public:
//		
//	//更好的方式->全缺省构造函数
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1; //调用默认构造函数->1、自己实现无参构造函数 2、自己实现全缺省构造函数 3、编译器默认的无参函数
//	d1.Print();
//
//	Date d2(2020,12,11);
//	d2.Print();
//
//	return 0;
//}

class Date
{
public:

	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//析构函数：对象声明周期到了以后，自动调用，完成对象里面的资源清理工作，不是完成对象的摧毁
	~Date() //栈帧，先析构后来创建的对象
	{
		cout << "~Date()" << endl;
		//加入有有动态内存开辟的空间，析构函数就可以起作用
		//free(a);
		//a = nullptr;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2;

	return 0;
}