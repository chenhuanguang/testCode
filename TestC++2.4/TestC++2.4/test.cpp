#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2021, 2, 4);
	Date d2(2021, 2, 4);

	if (d1 == d2) // d1.operator(d2)
	{
		cout << "========" << endl;
	}
	else
	{
		cout << "!=!=!=!=!=" << endl;
	}

	return 0;
}