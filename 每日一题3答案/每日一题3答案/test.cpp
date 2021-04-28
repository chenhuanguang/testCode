#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int count = 0;
        int res = 0;
        int sz = numbers.size();
        for (int i = 0; i < sz; ++i)
        {
            if (count == 0)
            {
                res = numbers[i];
                ++count;
            }
            else if (numbers[i] == res)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
        count = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (numbers[i] == res)
                ++count;
        }
        if (count <= sz / 2)
            return 0;
        return res;
        return 0;
    }
};

//int main()
//{
//    string str, tmp, res;
//    getline(cin, str);
//    int sz = str.size();
//    int idx = 0;
//    while (idx < sz)
//    {
//        if (!isdigit(str[idx]))
//        {
//            ++idx;
//            continue;
//        }
//        while (idx < sz && isdigit(str[idx]))
//        {
//            tmp += str[idx];
//            idx++;
//        }
//        if (tmp.size() > res.size())
//        {
//            res = tmp;
//        }
//        tmp.clear();
//    }
//    cout << res << endl;
//    return 0;
//}