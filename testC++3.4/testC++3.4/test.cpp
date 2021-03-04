#include <iostream>
using namespace std;

//class A
//{
//public:
//	A(int a )
//		: _a(a)
//	{
//		cout << "***" << endl;
//	}
//private:
//	int _a;
//};
//class Date 
//{
//public: 
//	Date(int year, int month, int day) 
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private: 
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d(2021, 3, 4);
//
//	return 0;
//}

//class A
//{
//public:
//	explicit A(int a)
//		:_a(a)
//	{}
//
//	A(const A& a)
//	{
//		_a = a._a;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A b(10); 
//	A c = b;	
//	A d = 20; 
//}

//class A
//{
//public:
//	static int getCount()
//	{
//		return _count;
//	}
//
//private:
//	static int _count;
//};
//
//int A::_count = 0;


class Date 
{
public: 
	friend void operator<<(ostream& _cout, Date d);
	Date(int year, int month, int day) 
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private: 
	int _year;
	int _month;
	int _day;
};

void operator<<(ostream& _cout, Date d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
}

int main()
{
	Date d(2021, 3, 4);
	cout << d;
	return 0;
}