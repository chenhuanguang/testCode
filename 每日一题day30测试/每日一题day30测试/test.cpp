#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

bool fun2(vector<int>& vec, int num)
{
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            vec.push_back(i);
            vec.push_back(num / i);;
            return true;
        }
    }
    return false;
}

int fun(int n)
{
    vector<int> vec;
    int idx = 1;
    int count = 0;
    bool flag = fun2(vec, n);
    if (flag == false)
        return 1;
    while (flag)
    {
        flag = fun2(vec, vec[idx]);
        if (flag == false)
            break;
        idx += 2;
        n = vec[idx];
        ++count;
    }
    set<int> s(vec.begin(), vec.end());
    return s.size() - count;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << fun(n) << endl;
    }
    return 0;
}