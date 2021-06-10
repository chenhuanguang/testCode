#include <iostream>
#include <vector>
using namespace std;

vector<int>& init(int n)
{
    vector<int> vec(n + 1);
    vec[0] = 1;
    vec[1] = 2;
    for (int i = 2; i <= n; ++i)
    {
        vec[i] = (vec[i - 1] + vec[i - 2]) % 1000000;
    }
    return vec;
}

int main()
{
    vector<int> table = init(100000);
    int n;
    while (cin >> n)
    {
        cout << table[n - 1] << endl;
    }
    return 0;
}