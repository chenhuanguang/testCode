#include <iostream>
#include <stack>
using namespace std;


bool chkParenthesis(string A, int n)
{
	if (n % 2 == 1)
		return false;
	stack<char> st;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] == '(')
			st.push(A[i]);
		else if (A[i] == ')' && !st.empty())
			st.pop();
		else
			return false;
	}
	if (st.empty())
		return true;
	return false;
}
	int main()
	{
		string s = "((()";
		cout << chkParenthesis(s, 4) << endl;
		return 0;
	}

//
//int main()
//{
//	int f;
//	int f1 = 0;
//	int f2 = 1;
//	int N, left, right;
//	cin >> N;
//	while (1)
//	{
//		f = f1 + f2;
//		f1 = f2;
//		f2 = f;
//		if (f <= N)
//		{
//			left = f;
//		}
//		else
//		{
//			right = f;
//			break;
//		}
//	}
//	cout << min(N - left, right - N) << endl;
//	return 0;
//}