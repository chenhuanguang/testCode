#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) //Date& d = d1;
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void func(Date dd)//调用拷贝构造 Date dd = d1;(调用拷贝构造的一种形式)
//{
//
//}
//
//int main()
//{
//	Date d1(2020, 12, 13);
//	Date d2(d1); //拷贝构造==Date d2(2020, 12, 13);
//	Date d3 = d2;//等价
//	d1.print();
//	d2.print();
//	d3.print();
//	
//	//func(d1);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) //Date& d = d1;
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
////自定义类型是不能用运算符的，要用就得实现重载函数，自定义类型用得时候就等价于调用这个重载函数
//int main()
//{
//	Date d1(2020, 12, 13);
//	Date d2(2020, 12, 14);
//
//	int flag =d1 == d2;//->operator ==(d1, d2);
//	//但是我们一般不会这样子写，因为可读性不好
//	operator ==(d1, d2);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) //Date& d = d1;
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//d1 ==d2
//	//d1.operator==(&d1,d2)
//	bool operator==(const Date& d) //bool operator==(Date* this, const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}		
//		else if (_year == d._year&&_month > d._month)
//		{
//			return true;
//		}	
//		else if (_year == d._year&&_month == d._month&&_day > d._day)
//		{
//			return true;
//		}
//		return false;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////自定义类型是不能用运算符的，要用就得实现重载函数，自定义类型用得时候就等价于调用这个重载函数
//int main()
//{
//	Date d1(2020, 12, 15);
//	Date d2(2020, 12, 14);
//
//	int flag = d1 == d2;//->d1.operator ==(d2);
//	int flag1 = d1 > d2;
//	cout << flag << endl;
//	cout << flag1 << endl;
//
//	return 0;
//}

//实现一个完善的日期类
//class Date
//{
//public:
//
//	//获得当前年份月份的天数
//	int GetMonthDay(int year, int month)
//	{
//		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		//是2月且是闰年返回29
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 ==0))
//		{
//			return 29;
//		}
//		return monthDays[month];
//	}
//
//	//构造函数
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		if (year >= 0 
//			&& month>=1 && month<=12 
//			&& day >=1 && day<=GetMonthDay(year,month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			cout << "非法日期" << endl;
//		}
//		
//	}
//	
//	//拷贝函数
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//只要出了作用域还在，就尽量用引用
//	Date& operator=(const Date& d) //传值返回会去调用拷贝构造
//	{
//		if(this != &d)
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this; 
//	}
//
//	//判断当前日期是否比d日期小
//	inline bool operator<(const Date& d)
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
//	//判断当前日期和d日期是否相等
//	inline bool operator==(const Date& d)
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//
//	//d1<=d2 =>d1<d2||d1==d2 
//	bool operator<=(const Date& d)//bool operator<=(Date* this, const Date& d)
//	{
//		return *this < d || *this == d; //复用上面的实现
//	}
//
//	//d1 > d2 =>!(d1<=d2)
//	bool operator>(const Date& d)
//	{
//		return !(*this <= d);
//	}
//
//	//d1>=d2
//	bool operator>=(const Date& d)
//	{
//		return !(*this < d);
//	}
//
//	//d1!=d2
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	//d1+10; 一个新的日期等于当前日期+天数
//	Date operator+(int day)
//	{
//		Date ret = *this; //用d1拷贝构造一个ret;
//		ret._day += day;
//		while (ret._day > GetMonthDay(ret._year, ret._month))
//		{
//			//如果日期的天不合法，就需要往月进位
//			ret._day -= GetMonthDay(ret._year, ret._month);
//			ret._month++;
//
//			if (ret._month == 13)
//			{
//				ret._year++;
//				ret._month = 1;
//			}
//		}
//		return ret;
//	}
//
//	//d1+=10
//	Date operator+=(int day)
//	{
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
//	Date& operator -= (int day)
//	{
//		_day -= day;
//		while (_day <= 0)
//		{
//			_month--;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//
//	Date operator-(int day)
//	{
//		Date ret = *this;
//		ret._day -= day;
//		while (ret._day<=0)
//		{
//			ret._month--;
//			if (ret._month == 0)
//			{
//				ret._year--;
//				ret._month = 12;
//			}
//			ret._day += GetMonthDay(ret._year, ret._month);
//		}
//		return ret;
//	}
//
//	//++d
//	Date& operator++()
//	{
//		_day ++;
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
//	Date& operator--()
//	{
//		_day --;
//		while (_day <= 0)
//		{
//			_month--;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//	int operator-(const Date& d) //返回天数
//	{
//
//	}
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day<<endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////自定义类型传参数和返回值时，在可以的情况下尽量使用引用，减少拷贝构造的调用
//int main()
//{
//	Date d;
//	d.print();
//
//	Date d2(2020, 12, 13);
//
//	Date d3(2021, 12, 14);
//
//	
//	////调用operator=
//	//d2 = d3;//两个对象都已经存在且初始化好了，现在我想把d2赋值（拷贝）给d1
//	////调用拷贝构造
//	//Date d4(d2);//d3还不存在，构造d3时用d1去初始化
//	//Date d5 = d2;//特别注意，这里是拷贝，不是operator=
//
//	/*1、我们不实现时，编译器生成的默认构造函数和析构函数，针对成员变量：
//	内置类型就不处理，自定义类型会调用这个成员对象的 构造和析构
//	  2、我们不实现时，编译器生成拷贝构造和operator=，会完成按字节的值拷贝（浅拷贝）
//	  也就是说有些类，我们是不需要去实现拷贝构造和operator=的，因为编译器默认生成就
//	  可以用，比如Date就是这样子的
//	*/
//
//	d2 = d3;
//	d2.print();
//	d3.print();
//
//	return 0;
//}

//实现一个完善的日期类
class Date
{
public:

	//获得当前年份月份的天数
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//是2月且是闰年返回29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}

	//构造函数
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}

	}

	//拷贝函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d) 
	{
		if (this != &d)
			_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	//判断当前日期是否比d日期小
	inline bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		return false;
	}

	//判断当前日期和d日期是否相等
	inline bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	//d1<=d2 =>d1<d2||d1==d2 
	bool operator<=(const Date& d)//bool operator<=(Date* this, const Date& d)
	{
		return *this < d || *this == d; //复用上面的实现
	}

	//d1 > d2 =>!(d1<=d2)
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	//d1>=d2
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	//d1!=d2
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//d1+=10
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	//d1-=10
	Date& operator -= (int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	Date operator-(int day)
	{
		Date ret = *this;	
		return ret -= day;;
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

	//d1+10; 一个新的日期等于当前日期+天数
	Date operator+(int day)
	{
		Date ret = *this; //用d1拷贝构造一个ret;

		return ret += day;
	}

	//++d1
	Date& operator++() //直接返回加之后的
	{
		return *this += 1;
	}

	//d1++
	Date operator++(int)//为了构造函数重载
	{
		Date tmp(*this); //返回的是加之前的
		*this += 1;
		return tmp;
	}

	int operator-(const Date& d) //返回天数
	{
		Date max = *this; //拷贝构造
		Date min = d;
		int flag = 1;
		if (*this < d)
		{
			min = *this; //赋值 operator=
			max = d;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++min; //自定义类型尽量调前置，少拷贝两次构造
			++n;
		}
		return flag*n;
	}

	void print()
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

	Date d1(2020, 12, 15);
	Date d2(2020, 12, 12);
	int res = d1 - d2;
	cout << res << endl;
	

	return 0;
}