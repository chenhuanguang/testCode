#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& vec, int idx)
{
    int preMax = 0;
    for (int i = 0; i < idx; ++i)
    {
        if (vec[i] < vec[idx])
        {
            preMax = max(vec[i], preMax);
        }
    }
    return preMax;
}

void fun(vector<int>& vec, int n)
{
    int sum = 0;
    for (int i = 1; i < n; ++i)
    {
        int preMax = find(vec, i);
        sum += preMax * (i + 1);
    }
    cout << sum << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> vec[i];
        }
        fun(vec, n);
    }

    return 0;
}