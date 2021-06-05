#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	while (n)
	{
		sum += n /= 5;
	}
	cout << sum << endl;
	return 0;
}