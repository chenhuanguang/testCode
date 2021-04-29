#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	static string table = "0123456789ABCDEF";
	string res;
	int m, n;
	cin >> m >> n;
	bool flag = false;
	if (m < 0)
	{
		m *= -1;
		flag = true;
	}

	while (m != 0)
	{
		res +=table[m % n];
		m /= n;
	}
	if (flag == true)
	{
		res += '-';
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
	return 0;
}

//int main()
//{
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	int A = (a + c) / 2;
//	int B1 = (c - a) / 2;
//	int B2 = (b + d) / 2;
//	int C = (d - b) / 2;
//	if (B1 != B2)
//	{
//		cout << "No" << endl;
//	}
//	cout << A << " " << B1 << " " << C << endl;
//}