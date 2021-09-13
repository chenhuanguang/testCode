#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string str;
    vector<vector<int>> vv(501, vector<int>(501));
    int idx = 0;
    while (getline(cin, str))
    {
        int j = 0;
        for (size_t i = 0; i < str.size(); ++i)
        {
            int cnt = 0;
            int b = i;
            while (i < str.size() && str[i] != ',')
            {
                ++cnt;
                ++i;
            }
            vv[idx][j++] = stoi(str.substr(b, cnt));
        }
        ++idx;
    }
    vector<int> arr;
    for (size_t i = 0; i < vv.size(); ++i)
    {
        for (size_t j = 0; j < vv[0].size(); ++j)
        {
            arr.push_back(vv[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    int sz = idx;
    bool flag = false;
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        if (arr[i] == arr[i + 1])
        {
            int cnt = 1;
            while (i < arr.size() - 1 && arr[i] == arr[i + 1])
            {
                ++cnt;
                ++i;
            }
            if (cnt == sz)
            {
                cout << arr[i] << endl;
                flag = true;
                break;
            }
        }
    }
    if (!flag)
        cout << -1 << endl;
    return 0;
}