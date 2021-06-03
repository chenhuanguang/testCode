#include <iostream>
#include <vector>
using namespace std;
int maxDivNum(int a, int b)
{
    while (a != 0)
    {
        int tmp = b % a;
        b = a;
        a = tmp;
    }
    return b;
}
int power(int n, int a, vector<int> vec)
{
    for (int i = 0; i < n; ++i)
    {
        if (vec[i] <= a)
            a += vec[i];
        else
            a += maxDivNum(a, vec[i]);
    }
    return a;
}
int main()
{
    int n, a;
    while (cin >> n >> a)
    {
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> vec[i];
        }
        cout << power(n, a, vec) << endl;;
    }
    return 0;
}
