#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <iostream>       
#include <vector>
using namespace std;
int main(void)
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << " ";
	}
	return 0;
}

//int StrToInt(string str)
//{
//    if (str.empty())
//        return 0;
//    int sz = str.size();
//    int sum = 0;
//    int flag = 1;
//    int idx = 0;
//    if (str[0] == '+')
//        ++idx;
//    if (str[0] == '-')
//    {
//        flag = -1;
//        idx++;
//    }
//    for (int i = idx; i < sz; ++i)
//    {
//        if (isdigit(str[i]))
//        {
//            int tmp = str[i] - '0';
//            sum = sum * 10 + tmp;
//        }
//        else
//        {
//            return 0;
//        }
//    }
//    return sum * flag;
//}
//
//int main()
//{
//    string str = "023456";
//    int res = StrToInt(str);
//    cout << res << endl;
//    return 0;
//}

//char fun(char x, char y)
//{
//	if (x < y)
//		return x;
//	return y;
//}
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}

//int main()
//{
//	int m = 0123;
//	int n = 123;
//	printf("%o %o\n", m, n);
//	
//	return 0;
//}

//int f(int n)
//{
//	if (n == 1)
//		return 1;
//	else
//		return (f(n - 1) + n * n * n);
//}
//
//int main()
//{
//	int s = f(3);
//	cout << s << endl;
//	return 0;
//}