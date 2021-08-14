#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int prio(char x)
{
    if (x == '*' || x == '/')  return 2;
    if (x == '+' || x == '-')  return 1;
    if (x == '(')  return 0;
    else return -1;
}

vector<string> inToPost(const string& s)
{
    stack<char> st;
    vector<string> res;
    int idx = 0;
    while (idx < s.size())
    {
        if (s[idx] >= '0' && s[idx] <= '9')
        {
            int num = 0;
            while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9')
            {
                num = 10 * num + (s[idx] - '0');
                ++idx;
            }
            stringstream ss;
            ss << num;
            string tmp;
            ss >> tmp;
            res.push_back(tmp);
            continue;
        }
        else
        {
            if (st.empty() || s[idx] == '(')
                st.push(s[idx]);
            else if (s[idx] == ')')
            {
                while (st.top() != '(')
                {
                    string tmp;
                    tmp += st.top();
                    res.push_back(tmp);
                    st.pop();
                }
                st.pop();
            }
            else 
            {
                while (prio(s[idx]) <= prio(st.top()))
                {
                    string tmp;
                    tmp += st.top();
                    res.push_back(tmp);
                    st.pop();
                    if (st.empty())
                        break;
                }

                st.push(s[idx]);
            }
        }
        ++idx;
    }

    if (!st.empty())
    {
        string tmp;
        tmp += st.top();
        res.push_back(tmp);
        st.pop();
    }

    return res;
}

int main()
{
    string s = "9+(3-1)*3+10/2";
    inToPost(s);
    return 0;
}