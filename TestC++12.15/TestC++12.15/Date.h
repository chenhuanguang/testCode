//#pragma once
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//
//	int GetMonthDay(int year, int month) const;
//
//	Date(int year = 0, int month = 1, int day = 1);
//
//	Date(const Date& d);
//
//	Date& operator=(const Date& d); 
//
//	inline bool operator<(const Date& d) const
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month < d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	inline bool operator==(const Date& d) const
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//
//	bool operator<=(const Date& d) const;
//
//	bool operator>(const Date& d) const;
//
//	bool operator>=(const Date& d) const;
//
//	bool operator!=(const Date& d) const;
//
//	inline Date& operator+=(int day)
//	{
//		if (day < 0)
//		{
//			return *this -= -day;
//		}
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				++_year;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//
//	inline Date& operator -= (int day)
//	{
//		if (day < 0)
//		{
//			return *this += -day;
//		}
//		_day -= day;
//		while (_day <= 0)
//		{
//			--_month;
//			if (_month == 0)
//			{
//				--_year;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//	Date operator-(int day) const;
//
//	Date& operator--();
//
//	Date operator--(int);
//
//	Date operator+(int day) const;
//
//	Date& operator++();
//
//	Date operator++(int);
//
//	int operator-(const Date& d) const;
//
//	void print()const;
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};