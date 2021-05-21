#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int res = 0;
		int count = 0;
		while (n)
		{
			if (n & 1)
			{
				++count;
				res = max(res, count);
			}
			else
				count = 0;
			n = n >> 1;
		}
		cout << res << endl;
	}
	return 0;
}