#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	long long a = 0;
	int flag = 1;
	if (num < 0)
	{
		flag = 0;
		num *= -1;
	}
	
	while (num)
	{
		a = a * 10 + num % 10;
		num /= 10;
	}

	long long tmp = a;
	long long pre = a;
	while (a > INT_MAX)
	{
		
		a = 0;
		while (tmp)
		{
			a = a * 10 + tmp % 10;
			tmp /= 10;
		}
		tmp = a % pre;
	}

	if (flag == 0)
		a *= -1;
	cout << a << endl;

	return 0;
}