#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;

    while (getline(cin, str))
    {
        vector<string> res;
        bool flag = true;
        for (int i = 0; i < str.size(); ++i)
        {
            string tmp;
            if (str[i] == '"')
            {
                flag = false;
                continue;
            }
            if (!flag)
            {
                while (i < str.size() && str[i] != '"')
                {
                    tmp += str[i++];
                }
                res.push_back(tmp);
                flag = true;
            }
            else
            {
                while (i < str.size() && str[i] != ' ')
                {
                    tmp += str[i++];
                }
                res.push_back(tmp);
            }
        }
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i] << endl;
        }

    }
    return 0;
}