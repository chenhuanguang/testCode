#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isDictionaries(const string& str1, const string& str2)
{
    if (str1.compare(str2) < 0)
    {
        return true;
    }
    return false;
}


int main()
{
    int n;
    cin >> n;
    int a = 1;
    int b = 1;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (!isDictionaries(v[i], v[i + 1]))
        {
            a = 0;
        }
        if (v[i].size() > v[i + 1].size())
        {
            b = 0;
        }
        if (a == b == 0)
            break;
    }
    if (a == b == 1)
        cout << "both" << endl;
    else if (a == 1)
        cout << "×Öµä" << endl;
    else if (b == 1)
        cout << "³¤¶È" << endl;
    else
        cout << "none" << endl;
    return 0;
}


//bool chkParenthesis(string A, int n)
//{
//    if (n % 2 == 1)
//        return false;
//    stack<char> st;
//    for (int i = 0; i < n; ++i)
//    {
//        if (A[i] == '(')
//        {
//            st.push(A[i]);
//        }
//        else if (A[i] == ')')
//        {
//            if (!st.empty())
//            {
//                st.pop();
//            }
//        }
//        else
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    string str = "()A()()";
//    int n = 6;
//    int res = chkParenthesis(str, n);
//    cout << res << endl;
//    return 0;
//}

//#include <iostream>
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int getMin(int a, int b)
//{
//    return a < b ? a : b;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    int a = 3;
//    int b = 5;
//    while (b <= n)
//    {
//        int tmp = b;
//        b = b + a;
//        a = tmp;
//    }
//    int res = getMin(b - n, n - a);
//    cout << res << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 1, b = 0, c = 1, d = 0;
//	d = ++a || ++b && ++c;
//	cout << d << endl;
//	cout << b << endl;
//
//	return 0;
//}

//int main()
//{
//	int p[][4] = { {1}, {3,2}, {4,5,6},{0} };
//	cout << p[1][2] << endl;
//	return 0;
//}