#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int hash[256] = { 0 };
	for (int i = 0; i < str2.size(); ++i)
	{
		hash[str2[i]]++;
	}
	string res = "";
	for (int i = 0; i < str1.size(); ++i)
	{
		if (hash[str1[i]] == 0)
		{
			res += str1[i];
		}
	}
	cout << res << endl;
	return 0;
}

//int main()
//{
//	
//	int n;
//	while (cin >> n)
//	{
//		long long res = 0;
//		vector<int> v;
//		int sz = 3 * n;
//		v.resize(sz);
//		for (int i = 0; i < sz; ++i)
//		{
//			cin >> v[i];
//		}
//		sort(v.begin(), v.end());
//		for (int i = 1; i <= n; ++i)
//		{
//			res += v[sz - 2 * i];
//		}
//		cout << res << endl;
//	}
//}


//bool isDigit(char ch)
//{
//    int num = ch - '0';
//    return (num >= 0 && num < 10);
//}
//
//int main()
//{
//    string str;
//    getline(cin, str);
//    int sz = str.size();
//    int idx = 0;
//    string res;
//    string tmp;
//    while (idx < sz)
//    {
//        if (!isDigit(str[idx]))
//        {
//            ++idx;
//            continue;
//        }
//        while (idx > sz && isDigit(str[idx]))
//        {
//            tmp += str[idx];
//            idx++;
//        }
//        if (tmp.size() > res.size())
//        {
//            res = tmp;
//        }
//    }
//    cout << res << endl;
//    return 0;
//}
//int cnt;
//int fib(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	fib(8);
//	cout << cnt;
//}

//int main()
//{
//    vector<int> num;
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    for (int i = 0; i < 4; ++i)
//    {
//        int tmp;
//        cin >> tmp;
//        num[i] = tmp;
//    }
//    a = (num[0] + num[2]) / 2;
//    b = (num[1] + num[3]) / 2;
//    c = b - num[1];
//    if (a < 0 || b < 0 || c < 0)
//    {
//        cout << "No" << endl;
//    }
//    else
//    {
//        cout << a << " " << b << " " << c << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//string res = "";
//const char* num = "0123456789ABCDEF";
//
//void fun1(int m, int n)
//{
//    res.clear();
//    while (m)
//    {
//        int tmp = m % n;
//        m /= n;
//        res += num[tmp];
//    }
//}
//
//void fun2(int m, int n)
//{
//    res.clear();
//    int reM = -1 * m;
//    fun1(reM, 2);
//    for (int i = 0; i < res.size(); ++i)
//    {
//        if (res[i] == '1')
//        {
//            res[i] = '0';
//        }
//        else
//        {
//            res[i] = '1';
//        }
//    }
//    for (int i = res.size(); i < 32; ++i)
//    {
//        res += '1';
//    }
//    reverse(res.begin(), res.end());
//    int i = 32;
//    int sum = 0;
//    int idx = 0;
//    while (i--)
//    {
//        sum += pow(res[i] - '0', idx++);
//    }
//    fun1(sum, n);
//}
//
//int main()
//{
//    int m = 0;
//    int n = 0;
//    cin >> m >> n;
//    if (m >= 0)
//    {
//        fun1(m, n);
//    }
//    else
//    {
//        fun2(m, n);
//    }
//    reverse(res.begin(), res.end());
//    cout << res << endl;
//    return 0;
//}