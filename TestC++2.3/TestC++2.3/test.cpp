#include <iostream>
using namespace std;

//class Person
//{
//public:
//	void Display()
//	{
//		cout << _id << "-" << _age << "-" << _heigh << endl;
//	}
//	void SetInfo(int id, int age, int heigh)
//	{
//		_id = id;
//		_age = age;
//		_heigh = heigh;
//	}
//
//private:
//	int _id;
//	int _age;
//	int _heigh;
//};
//
//int main()
//{
//	Person p1, p2;
//	p1.SetInfo(1, 18, 170);
//	p2.SetInfo(2, 19, 175);
//	p1.Display();
//	p2.Display();
//	Person* p = nullptr;
//
//
//	return 0;
//}

class A
{
public:

private:
	int _a;
};

class Date
{
public: 

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	 ~Date()
	 {}

	 Date(const Date& d)
	 {
		 _year = d._year;
		 _month = d._month;
		 _day = d._day;
	 }

	 void Print()
	 {
		 cout << _year << "-" << _month << "-" << _day << endl;
	 }
private: 
	int _year; 
	int _month;
	int _day;
};


int main() 
{
	Date d1(2020, 2, 3);
	Date d2(d1);

	d1.Print();
	d2.Print();

	return 0;
}