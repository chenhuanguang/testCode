#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string decompress(string compressed_str)
{
    string res = "";
    stack<char> s;
    int idx = 0;
    if (compressed_str[idx] == '(')
        s.push(compressed_str[idx++]);
    string tmp = "";
    while (!s.empty() || idx < compressed_str.size())
    {
        if (compressed_str[idx] == '(')
        {
            s.push(compressed_str[idx]);
        }
        else if (compressed_str[idx] != ')')
        {
            
            string tmp2 = "";
            while (compressed_str[idx] != ')')
            {
                tmp2 += compressed_str[idx++];
            }
            s.pop();
            ++idx;
            int cnt = compressed_str[idx] - '0'; 
            while (cnt--)
            {
                tmp += tmp2;
            }
            if (s.empty())
            {
                res += tmp;
                tmp = "";
            }

        }
        else
        {
            s.pop();
        }
        ++idx;
    }

    return res;
}

int purchase(vector<int>& nums, int budget)
{
    int cnt = 0;
    size_t n = nums.size();
    sort(nums.begin(), nums.end());
    bool flag = true;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            int j = i + 1;
            flag = false;
            for ( ; j < n; ++j)
            {
                if (nums[i] + nums[j] <= budget)
                {
                    cnt++;
                    flag = true;
                }
                else
                    break;
            }
            n = j + 1;
            if (!flag)
                break;
        }
    return cnt % 1000000007;
}

void numberOfShelves(int N) 
{
    int digit = 1;
    int top = 0;
    int left = 0;
    int botton = N;
    //int right = N;

    vector<vector<int>> vr(N, vector<int>(N, 0));
    while (1)
    {
        for (int i = top; i < botton; ++i)
        {
            vr[i][left] = digit++;
        }
        ++left;
        botton -= 2;
        int right = left;
        for (int i = botton; i >= top; --i, ++right)
        {
            vr[i][right] = digit++;
        }
        right--;
        for (int i = right; i >= left; --right)
        {
            vr[top][right] = digit++;
        }
        if (--top == botton)
            break;
    }
}

int main()
{
    //string s = "(a)2(b)2(c)2";
    //decompress(s);
    //vector<int> nums = { 5,2,3,5 };
    //purchase(nums, 6);
    numberOfShelves(3);
    return 0;
}