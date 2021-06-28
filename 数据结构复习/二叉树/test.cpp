#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

bool IsValidExp(string s)
{
    stack<char> st;
    unordered_map<char, int> m = {
        {'(', 1}, {'[', 2}, {'{', 3},
        {')', 4}, {']', 5}, {'}', 6}
    };
    for (const auto& ch : s)
    {
        if (m[ch] <= 3)
            st.push(ch);
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();
            if (m[top] != m[ch] - 3)
                return false;
        }
    }

    return st.empty();
}

//int main()
//{
//    string s = "({}[])";
//    IsValidExp(s);
//    return 0;
//}