#include <iostream>
using namespace std;

class Date
{
public:
	int GetDay(int year, int month)
	{
		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0))
		{
			++day;
		}
		return day;
	}

	Date(int year = 1, int month = 1, int day = 1)
	{
		if (year <= 0 || month <= 0 || month > 12
			|| day <= 0 || day > GetDay(year, month))
		{
			_year = 1;
			_month = 1;
			_day = 1;
			cout << "输入日期有误，恢复默认日期 1-1-1" << endl;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
		}
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		
		return false;
	}

	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}

	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date& operator+=(int day)
	{
		if (day < 0)
		{
			*this -= -day;
		}
		else
		{
			_day += day;
			while (_day > GetDay(_year, _month))
			{
				_day -= GetDay(_year, _month);
				++_month;

				//年份进位
				if (_month == 13)
				{
					++_year;
					_month = 1;
				}
			}
		}
		
		return *this;
	}

	Date operator+(int day)
	{
		Date tmp = *this;
		return tmp += day;
	}

	Date& operator++()
	{
		return *this += 1;
	}

	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			*this += -day;
		}
		else
		{
			_day -= day;
			while (_day <= 0)
			{
				--_month;
				//年份进位
				if (_month == 0)
				{
					--_year;
					_month = 12;
				}
				_day += GetDay(_year, _month);

			}
		}
		
		return *this;
	}

	Date operator-(int day)
	{
		Date tmp = *this;
		return tmp -= day;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	int operator-(const Date& d)
	{
		Date min = d;
		Date max = *this;
		int flag = 1;
		if (min > max)
		{
			Date tmp = min;
			min = max;
			max = tmp;
			flag = -1;
		}
		int res = 0;
		while (min != max)
		{
			++min;
			++res;
		}
		return flag * res;
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
	Date d1(2025, 2, 2);
	Date d2(2021, 2, 3);
	//d1 = d2;
	//d1 = d2 + 3;
	//d1 += -401;
	//d1 -= -300;
	//d1.Print();
	cout << (d1 - d2) << endl;
	//d2.Print();
	//cout << (d2 < d1) << endl;
	//Date d1(2021, 2, 4);
	//Date d2(2021, 2, 3);
	//Date d3(2021, 2, 3);
	//
	//cout << (d1 == d2) << endl;
	//cout <<(d1 == d3) << endl;
	//cout << (d2 == d3) << endl;

	//d1 = d2;
	//d1.Print();

	/*Date d(2021, 2, 4);
	d += 400;
	d.Print();

	Date d2 = d + 400;
	d2.Print();

	d = d2++;
	d.Print();
	d2.Print();*/
	return 0;
}