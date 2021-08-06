#include <iostream>
#include<vector>
using namespace std;

string GetXMLValue(string inxml, string path)
{
    bool flag = false;
    vector<string> paths;
    string data;
    for (int i = 0; i < inxml.size(); ++i)
    {
        if (inxml[i] == '<')
        {
            flag = !flag;
            continue;
        }
        if (flag)
        {
            string tmp;
            while (i < inxml.size() && inxml[i] != '>')
            {
                tmp += inxml[i++];
            }
            paths.push_back(tmp);
            flag = !flag;
        }
        else
        {
            while (inxml[i] != '<')
            {
                data += inxml[i++];
            }
            break;
        }
    }

    int idx = 0;
    for (int i = 0; i < path.size(); ++i)
    {
        string tmp = paths[idx++];
        int j = 0;
        while (i < path.size() && path[i] != '.')
        {
            if (tmp[j++] == path[i++])
                continue;
            return "";
        }
    }

    return data;
}
int main()
{
    GetXMLValue("<people><name>shopee</name></people>", "people.name");
	return 0;
}