#include <iostream>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> st;
    char preSign = '+';
    int num = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        if (isdigit(s[i])) {
            num = num * 10 + int(s[i] - '0');
        }
        if (!isdigit(s[i]) || i == n - 1) {
            switch (preSign) {
            case '+':
                st.push(num);
                break;
            case '-':
                st.push(-num);
                break;
            case '*':
                st.top() *= num;
                break;
            default:
                st.top() /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}

int main()
{
    calculate("3/2");
	return 0;
}