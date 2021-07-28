#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> vec(32);
    long long tmp = 2;
    for (int i = 0; i < 32; ++i)
    {
        vec[i] = tmp;
        tmp *= 2;
    }
    int n;
    cin >> n;
    while (n--)
    {
        long long num;
        cin >> num;
        int cnt = -1;
        for (int i = 31; i >= 0; --i)
        {
            if (num <= vec[i])
            {
                ++cnt;
                num -= vec[i];
                if (num == 0)
                    break;
            }
        }
        if (num == 0)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}