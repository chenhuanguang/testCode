#include <iostream>
#include <string>
using namespace std;
string replaceSpace(string s)
{
    int cnt = 0;
    for (const auto& ch : s)
    {
        if (ch == ' ')
            ++cnt;
    }
    string res;
    res.resize(s.size() + 2 * cnt);
    int tail = s.size() - 1;
    int head = tail;
    int idx = res.size() - 1;
    while (head >= 0)
    {
        while (head >= 0 && s[head] != ' ')
        {
            --head;
        }
        while (tail != head)
        {
            res[idx--] = s[tail--];
        }
        res[idx--] = '0';
        res[idx--] = '2';
        res[idx--] = '%';
        --head;
        --tail;
    }
    return res;
}

int main()
{
    string s = "We Are Happy";
    replaceSpace(s);
    return 0;
}