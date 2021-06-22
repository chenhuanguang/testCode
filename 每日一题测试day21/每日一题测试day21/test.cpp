#include <iostream>
#include <string>
#include <vector>
using namespace std;
void fun2(string& str, int n, vector<int>& vec, int& idx)
{
    vec.resize(n);
    for (int i = 0; i < n; ++i)
    {
        vec[i] = i + 1;
    }
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'U')
        {
            if (idx == 1)
                idx = n;
            else
                --idx;
        }
        else
        {
            if (idx == n)
                idx = 1;
            else
                ++idx;
        }
    }
}

void fun2(string& str, int n, vector<int>& vec, int& idx)
{
    vec.resize(4);
    for (int i = 0; i < 4; ++i)
    {
        vec[i] = i + 1;
    }
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'U')
        {
            if (idx == 1)
            {
                for (int i = 0; i < 4; ++i)
                {
                    vec[i] += n - 4;
                }
                idx = n;
            }
            else
            {
                if (idx == vec[0])
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        --vec[i];
                    }
                }
                --idx;
            }
        }
        else
        {
            if (idx == n)
            {
                for (int i = 0; i < 4; ++i)
                {
                    vec[i] -= n - 4;
                }
                idx = 1;
            }
            else
            {
                if (idx == vec[3])
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        ++vec[i];
                    }
                }
                ++idx;
            }
        }
    }
}

void fun(string& str, int n)
{
    vector<int> res;
    int idx = 1;
    if (n <= 4)
        fun1(str, n, res, idx);
    else
        fun2(str, n, res, idx);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << idx << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        string str;
        cin >> str;
        fun(str, n);
    }
    return 0;
}