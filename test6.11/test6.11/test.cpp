#include <string>
using namespace std;

bool matchCore(string& s, string& p, int idx1, int idx2)
{
    if (idx1 == s.size() && idx2 == p.size())
        return true;
    if (idx1 < s.size() && idx2 == p.size())
        return false;

    if (idx2 + 1 < p.size() && p[idx2 + 1] == '*')
    {
        if (s[idx1] == p[idx2] || (p[idx2] == '*' && idx1 < s.size()))
        {
            return matchCore(s, p, idx1, idx2 + 2)
                || matchCore(s, p, idx1 + 1, idx2 + 2)
                || matchCore(s, p, idx1 + 1, idx2);
        }
        else
            return matchCore(s, p, idx1, idx2 + 2);
    }

    if (s[idx1] == p[idx2] || (p[idx2] == '*' && idx1 < s.size()))
        return matchCore(s, p, idx1 + 1, idx2 + 1);
    return false;
}

bool isMatch(string s, string p)
{
    if (s.size() == 0 || p.size() == 0)
        return false;

    return matchCore(s, p, 0, 0);
}



int main()
{
    string s = "";
    string p = ".*";
    isMatch(s, p);
    return 0;
}