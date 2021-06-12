#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> nTable(n);
        getchar();
        string name = "";
        for (int i = 0; i < n; ++i)
        {
            getline(cin, name);
            nTable[i] = name;
        }
        for (int i = 0; i < n; ++i)
        {
            int flag = false;
            for (const auto& ch : nTable[i])
            {
                if (ch == ',' || ch == ' ')
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << "\"" << nTable[i] << "\"";
            else
                cout << nTable[i];
            if (i != n - 1)
                cout << ", ";
        }
        cout << endl;
    }
    return 0;
}