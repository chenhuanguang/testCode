#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> table(81);
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i <= 80; ++i)
    {
        table[i] = table[i - 1] + table[i - 2];
    }
    int from, to;
    while (cin >> from >> to)
    {
        int sum = 0;
        for (int i = from - 1; i < to; ++i)
        {
            sum += table[i];
        }
        cout << sum << endl;
    }
    return 0;
}