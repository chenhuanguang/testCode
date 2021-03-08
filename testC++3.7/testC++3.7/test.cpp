#include <iostream>
using namespace std;

//class Date
//{
//public:
//	//友元函数的声明：规定此函数可以访问当前类的所有成员
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//
//	Date(int year =  1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	//Date d1(2021, 3, 6);
//	//Date d2(2021, 3, 7);
//	Date d1;
//	Date d2;
//	cout << d1 << d2 << endl;
//	cin >> d1 >> d2;
//	cout << d1 << d2 << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	class B
//	{
//	public:
//		void setA(A a)
//		{
//			a._a = 100;
//			_sa = 200;
//		}
//	private:
//		int _b = 2;
//	};
//
//	void createB()
//	{
//		B b;
//	}
//private:
//	int _a = 1;
//	static int _sa;
//};
//
//int main()
//{
//	
//
//	return 0;
//}


//int isDay(int year, int month)
//{
//    static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    int day = days[month];
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//    {
//        ++day;
//    }
//    return day;
//}
//
//int isBigDate(int y1, int m1, int d1, int y2, int m2, int d2)
//{
//    if (y1 > y2)
//    {
//        return 1;
//    }
//    else if (y1 == y2 && m1 > m2)
//    {
//        return 1;
//    }
//    else if (y1 == y2 && m1 == m2 && d1 > d2)
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//int main()
//{
//    int y1, m1, d1, y2, m2, d2, res;
//    res = 1;
//    cin >> y1 >> m1 >> d1;
//    cin >> y2 >> m2 >> d2;
//    int flag = isBigDate(y1, m1, d1, y2, m2, d2);
//    if (flag == 1)
//    {
//        while (!(y1 == y2 && m1 == m2 && d1 == d2))
//        {
//            ++d2;
//            if (d2 > isDay(y2, m2))
//            {
//                d2 = 1;
//                ++m2;
//                if (m2 == 13)
//                {
//                    m2 = 1;
//                    ++y2;
//                }
//            }
//            ++res;
//        }
//    }
//    else if (flag == 0)
//    {
//        while (!(y1 == y2 && m1 == m2 && d1 == d2))
//        {
//            ++d1;
//            if (d1 > isDay(y1, m1))
//            {
//                d1 = 1;
//                ++m1;
//                if (m1 == 13)
//                {
//                    m1 = 1;
//                    ++y1;
//                }
//            }
//            ++res;
//        }
//    }
//
//    printf("%d\n", res);
//    return 0;
//}

int isDay(int year, int month)
{
    static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day = days[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        ++day;
    }
    return day;
}

int isBigDate(int y1, int m1, int d1, int y2, int m2, int d2)
{
    if (y1 > y2)
    {
        return 1;
    }
    else if (y1 == y2 && m1 > m2)
    {
        return 1;
    }
    else if (y1 == y2 && m1 == m2 && d1 > d2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int y1, m1, d1, y2, m2, d2, res;
    res = 1;
    int date1, date2;
    cin >> date1;
    cin >> date2;
  
    y1 = date1 / 10000;
    y2 = date2 / 10000;
    m1 = date1 / 100 % 100;
    m2 = date2 / 100 % 100;
    d1 = date1 % 100;
    d2 = date2 % 100;
    if (date2 > date1)
    {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }

    while (!(y1 == y2 && m1 == m2 && d1 == d2))
    {
        ++d2;
        if (d2 > isDay(y2, m2))
        {
            d2 = 1;
            ++m2;
            if (m2 == 13)
            {
                m2 = 1;
                ++y2;
            }
        }
        ++res;
    }

    printf("%d\n", res);
    return 0;
}