#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string nTable, name;
    while (getline(cin, nTable) && getline(cin, name))
    {
        vector<string> vec;
        for (int i = 0; i < nTable.size(); ++i)
        {
            //存在双引号
            if (nTable[i] == '\"')
            {
                //从双引号的下一个位置开始分割字符，直到遇到下一个双引号
                string tmp = nTable.substr(i + 1, nTable.find('\"', i + 1) - i - 1);
                vec.push_back(tmp);
                i = nTable.find('\"', i + 1)+1;
            }
            else
            {
                if (nTable.find(',', i) != string::npos)
                {
                    string tmp = nTable.substr(i, nTable.find(',', i) - i);
                    vec.push_back(tmp);
                    i = nTable.find(',', i);
                }
                else
                {
                    string tmp = nTable.substr(i, nTable.size() - i);
                    vec.push_back(tmp);
                    i = nTable.size();
                }
            }
        }
        auto it = find(vec.begin(), vec.end(), name);
        if (it == vec.end())
            cout << "Important!" << endl;
        else
            cout << "Ignore" << endl;
    }
    return 0;
}