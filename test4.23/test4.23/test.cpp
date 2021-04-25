#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	//整体逆置
	reverse(str.begin(), str.end());

	string::iterator start = str.begin();
	while (start != str.end())
	{
		auto end = start;
		while (end != str.end() && *end != ' ')
		{
			++end;
		}
		reverse(start, end);
		if (end != str.end())
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}

	cout << str << endl;
	return 0;
}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n+1);
//	v[n] = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//
//	int i = 0;
//	int count = 0;
//	while (i < n)
//	{
//		//进入非递减序列
//		if (v[i] < v[i + 1])
//		{
//			while (i < n && v[i] <= v[i + 1])
//			{
//				++i;
//			}
//			++count;
//			++i;
//		}
//		else if (v[i] == v[i + 1])
//		{
//			i++;
//		}
//		//进入非递增序列
//		else
//		{
//			while (i < n && v[i] >= v[i + 1])
//			{
//				++i;
//			}
//			++count;
//			++i;
//		}
//
//	}
//
//	cout << count << endl;
//
//	return 0;
//}

//int main()
//{
//    int n = 0;
//    vector<int> v;
//    cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> v[i];
//    }
//    int res = v[0];
//    for (int i = 1; i < n; ++i)
//    {
//        if (v[i - 1] > 0)
//        {
//            v[i] += v[i - 1];
//        }
//        if (v[i] > res)
//        {
//            res = v[i];
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

//bool palindrome(const string& str)
//{
//    int begin = 0;
//    int end = str.size() - 1;
//
//    while (begin < end)
//    {
//        if (str[begin++] != str[end--])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    string str1 = "";
//    string str2 = "";
//    getline(cin, str1);
//    getline(cin, str2);
//    int res = 0;
//    int sz = str1.size();
//    for (int i = 0; i <= sz; ++i)
//    {
//        string tmp = str1;
//        str1.insert(i, str2);
//        if (palindrome(str1))
//            ++res;
//        str1 = tmp;
//    }
//    cout << res << endl;
//    return 0;
//}

//int main()
//{
//	int n[][3] = { 1,2,3,4,5,6 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
//
//	return 0;
//}

//void main()
//{
//	int a;
//	float b, c;
//	scanf("%2d%3f%4f", &a, &b, &c);
//	printf("\na=%d,b=%d,c=%f\n",a,b,c);
//}