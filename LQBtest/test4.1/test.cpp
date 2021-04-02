#include <iostream>
using namespace std;

/* 初始时，小明充满体力，体力值计为 10000。如果小明跑步，每分钟损耗600 的体力。
如果小明休息，每分钟增加 300 的体力。体力的损耗和增加都是均匀变化的。小明打算跑一分钟、休息一分钟、再跑一分钟、再休息一分钟……如此循环。
如果某个时刻小明的体力到达 0，他就停止锻炼。请问小明在多久后停止锻炼。为了使答案为整数，请以秒为单位输出答案。
*/
//int main()
//{
//	int a = 10000;
//	int b = 300;
//	int res = 0;
//	int count = 0;
//	while (res < 9400)
//	{
//		res += 300;
//		++count;
//	}
//	cout << res << endl;
//	
//	int c = a - res;
//
//	int d = c / 10;
//	count = count * 2 * 60;
//	cout << d + count << endl;
//	return 0;
//}

class Date
{
public:
	int getDay(int year, int month)
	{
		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//判断当年是否为闰年
		if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0))
		{
			++day;
		}
		return day;
	}

	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		,_day(day)
	{}

	Date& operator+=(int day)
	{
		_day += day;
		while (_day > getDay(_year, _month))
		{
			_day -= getDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	Date& operator++() 
	{
		*this += 1;
		return *this;
	}

	bool operator!=(Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return false;
		return true;
	}

	int operator-(Date& d)
	{
		int count = 0;
		while (*this != d)
		{
			++count;
			++d;
		}
		return count;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 7, 1);
	Date d2(1921, 7, 23);
	int res = d1 - d2;
	res = res * 24 * 60;
	cout << res << endl;
	return 0;
}