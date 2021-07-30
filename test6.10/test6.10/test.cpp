#include<iostream>
#include <string>
#include <vector>
using namespace std;
    void inputNum(string& str, vector<int>& res)
    {
        bool flag = true;
        string tmp = "";
        for (int i = 0; i < str.size(); ++i)
        {
            if (flag && str[i] != '0')
                flag = !flag;
            if (!flag)
                tmp += str[i];
        }
        res.push_back(stoi(tmp));
    }

    bool increment(string& str)
    {
        int step = 0;
        bool flag = false;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            int sum = str[i] - '0' + step;
            if (i == str.size() - 1)
                ++sum;
            if (sum > 9)
            {
                if (i == 0)
                    flag = true;
                else
                {
                    sum -= 10;
                    step = 1;
                    str[i] = sum + '0';
                }
            }
            else
            {
                str[i] = sum + '0';
                break;
            }
        }
        return false;
    }

    vector<int> printNumbers(int n)
    {
        vector<int> res;
        if (n <= 0)
            return res;
        string str;
        str.resize(n, '0');
        while (!increment(str))
        {
            inputNum(str, res);
        }
        return res;
    }

    int main()
    {
        printNumbers(1);
        return 0;
    }