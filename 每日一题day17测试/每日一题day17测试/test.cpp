//#include <iostream>
//#include <vector>
//using namespace std;
//
//int fun1(int n)
//{
//    if (n == 1 || n == 2)
//        return -1;
//    vector<vector<int>> vv;
//    vv.resize(n);
//    vv[0].resize(1, 1);
//    vv[1].resize(3, 1);
//    for (int i = 2; i < n; ++i)
//    {
//        vv[i].resize(vv[i - 1].size() + 2);
//    }
//
//    for (int i = 2; i < n; ++i)
//    {
//        //上一行的大小
//        int sz = vv[i - 1].size();
//        vv[i][0] = vv[i][sz+1] = 1; //此行头尾置为1
//        for (int j = 1; j < sz; ++j) //除第一个元素和后两个元素，都满足同一规律
//        {
//            if (j == 1) //第二个元素等于上一行前两行数字之和
//            {
//                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//            }
//            else //除了倒数第二个元素，其他元素都是长一行3个元素之和
//            {
//                vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
//            }
//        }
//        //倒数第二个元素为当前列前两个元素之和
//        vv[i][sz] = vv[i - 1][sz - 2] + vv[i - 1][sz - 1];
//    }
//    vector<int> res = vv[n - 1];
//    for (int i = 0; i < n; ++i)
//    {
//        if (res[i] % 2 == 0)
//            return i + 1;
//    }
//
//    //for (int i = 0; i < n; ++i)
//    //{
//    //    for (int j = 0; j < vv[i].size(); ++j)
//    //    {
//    //        cout << vv[i][j] << " ";
//    //    }
//    //    cout << endl;
//    //}
//    return -1;
//}
//
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        cout << fun1(n) << endl;
//    }
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string addLongInteger(string& str1, string& str2)
{
    string res = "";
    int idx1 = str1.size() - 1;
    int idx2 = str2.size() - 1;
    int step = 0;
    while (idx1 >= 0 || idx2 >= 0)
    {
        int left = 0, right = 0;
        if (idx1 >= 0)
            left = str1[idx1--] - '0';
        if (idx2 >= 0)
            right = str2[idx2--] - '0';
        int sum = left + right + step;
        if (sum > 9)
        {
            step = 1;
            sum -= 10;
        }
        else
            step = 0;
        char c = sum + '0';
        res += c;
    }
    if (step == 1)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        cout << addLongInteger(str1, str2) << endl;
    }
    return 0;
}