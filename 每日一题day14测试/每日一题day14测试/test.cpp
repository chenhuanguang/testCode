#include <iostream>
using namespace std;

int getOutDay(int year, int month)
{
    static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day = days[month];
    if (month == 2)
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            ++day;
    }
    return day;
}

int iConverDateToDay(int year, int month, int day)
{
    int m = 1, d = 1;
    int count = 0;
    while (m <= month)
    {
        int maxDay = getOutDay(year, m);
        while (d <= maxDay)
        {
            ++d;
            count++;
            if (m == month && d == day)
                break;
        }
        d = 1;
        ++m;
    }
    return count;
}

int main()
{
    int year, month, day;
    cin >> year;
    cout << endl;
    cin >> month;
    cout << endl;
    cin >> day;

    int res = iConverDateToDay(year, month, day);
    cout << res << endl;
    return 0;
}