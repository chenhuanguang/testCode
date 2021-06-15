#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        getchar();
        vector<string> conn(n);
        for (int i = 0; i < n; ++i)
        {
            getline(cin, conn[i]);
        }
        int max = 0;
        int curMax = 0;
        for (int i = 0; i < n; ++i)
        {
            string str = conn[i];
            if (str[2] == 'c')
            {
                curMax++;
                if (curMax > max)
                    max = curMax;
            }
            else
                curMax--;
        }
        cout << max << endl;
    }
    return 0;
}