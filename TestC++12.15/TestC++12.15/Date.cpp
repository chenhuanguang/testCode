//#include"Date.h"
//
//int Date::GetMonthDay(int year, int month) const
//{
//	static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//	{
//		return 29;
//	}
//	return monthDays[month];
//}
//
//Date::Date(int year, int month, int day)
//{
//	if (year >= 0
//		&& month >= 1 && month <= 12
//		&& day >= 1 && day <= GetMonthDay(year, month))
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	else
//	{
//		cout << "非法日期" << endl;
//	}
//
//}
//
//Date::Date(const Date& d)
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
//
//Date& Date::operator=(const Date& d)
//{
//	if (this != &d)
//		_year = d._year;
//	_month = d._month;
//	_day = d._day;
//	return *this;
//}
//
//bool Date::operator<=(const Date& d) const
//{
//	return *this < d || *this == d;
//}
//
//bool Date::operator>(const Date& d) const
//{
//	return !(*this <= d);
//}
//
//bool  Date::operator>=(const Date& d) const
//{
//	return !(*this < d);
//}
//
//bool Date::operator!=(const Date& d) const
//{
//	return !(*this == d);
//}
//
//Date Date::operator-(int day)  const
//{
//	Date ret = *this;
//	return ret -= day;;
//}
//
//Date& Date::operator--()
//{
//	return *this -= 1;
//}
//
//Date Date::operator--(int)
//{
//	Date tmp = *this;
//	*this -= 1;
//	return tmp;
//}
//
//Date Date::operator+(int day) const
//{
//	Date ret = *this; 
//
//	return ret += day;
//}
//
//Date& Date::operator++()
//{
//	return *this += 1;
//}
//
////d1++
//Date Date::operator++(int)
//{
//	Date tmp(*this);
//	*this += 1;
//	return tmp;
//}
//
//int Date::operator-(const Date& d) const
//{
//	Date max = *this;
//	Date min = d;
//	int flag = 1;
//	if (*this < d)
//	{
//		min = *this;
//		max = d;
//		flag = -1;
//	}
//	int n = 0;
//	while (min != max)
//	{
//		++min;
//		++n;
//	}
//	return flag * n;
//}
//
//void Date::print() const
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
