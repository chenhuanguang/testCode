#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getMaxComStr(string& str1, string& str2)
{
    if (str1.size() > str2.size())
        swap(str1, str2);
    int len1 = str1.size();
    int len2 = str2.size();
    
    vector<vector<int>> msc(len1, vector<int>(len2, 0));
    int max_len = 0;
    int start = 0;
    for (int i = 0; i < len1; ++i)
    {
        for (int j = 0; j < len2; ++j)
        {
            if (str2[j] == str1[i])
            {
                if (i >= 1 && j >= 1)
                    msc[i][j] = msc[i - 1][j - 1] + 1;
                else
                    msc[i][j] = 1;
                if (msc[i][j] > max_len)
                {
                    max_len = msc[i][j];
                    start = i - max_len + 1;
                }
            }
                
        }
    }
    string res = str1.substr(start, max_len);
    return res;
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        cout << getMaxComStr(str1, str2) << endl;
    }
    return 0;
}