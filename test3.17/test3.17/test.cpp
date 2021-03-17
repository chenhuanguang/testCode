#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2)
    {
        string res;
        int len1 = num1.size() - 1;
        int len2 = num2.size() - 1;
        int len3 = num2.size();
        string* str = new string[len3];
        int idx = 0;
        while (len2 >= 0)
        {
            int step = 0;
            int val2 = num2[len2--] - '0';
            int tmp1 = len1;

            while (tmp1 >= 0)
            {
                int sum = 0;
                int val1 = num1[tmp1--] - '0';
                sum = step + val1 * val2;
                if (sum > 9)
                {
                    step = sum / 10;
                    sum = sum % 10;
                }
                else
                {
                    step = 0;
                }
                str[idx] += sum + '0';
            }
            if (step != 0)
            {
                str[idx] += step + '0';
            }
            int tmp = idx;
            reverse(str[idx].begin(), str[idx].end());
            while (tmp--)
            {
                str[idx] += '0';
            }
            idx++;
        }

        string tmp;
        for (int i = 0; i < len3; ++i)
        {
            tmp = addStrings(tmp, str[i]);
            res = tmp;
        }
        return res;
    }

    //×Ö·û´®Ïà¼Ó
    string addStrings(string num1, string num2)
    {
        string res;
        int len1 = num1.size();
        int len2 = num2.size();
        int step = 0;
        while (len1 > 0 || len2 > 0)
        {
            int val1 = 0;
            int val2 = 0;
            int sum = 0;
            if (len1 > 0)
            {
                val1 = num1[--len1] - '0';
            }
            if (len2 > 0)
            {
                val2 = num2[--len2] - '0';
            }
            sum = val1 + val2 + step;
            if (sum > 9)
            {
                step = 1;
                sum -= 10;
            }
            else
            {
                step = 0;
            }
            res += sum + '0';
        }
        if (step == 1)
        {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = "123";
    string s2 = "456";
    string s3 = s.multiply(s1, s2);
    cout << s3 << endl;
    return 0;
}