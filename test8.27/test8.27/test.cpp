#include <iostream>
using namespace std;

int cnt = 1;
void  fun(int div, int num)
{
	for (int i = div; i < sqrt(num); i++)
	{
		//20 -> 2 10 -> 2 2 5
		//20 ->4 5
		//i = 5£¬ 5*5>20break;
		if (num % i == 0)
		{
			cnt++;
			fun(i, num / i);     
		}
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		int num = 0;
		while (n--)
		{
			cnt = 1;
			cin >> num;
			fun(2, num);
			cout << cnt << endl;
		}
	}
	return 0;
}