#include <iostream>
#include <string>
using namespace std;

static int table[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
static string table2 = "10X98765432";

int fun(string& str)
{
    int a = 0, b = 0, c = 0;
    int flag = 0;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < str.size() - 1; ++i)
    {
        if (str[i] == '*' && flag == 0)
        {
            a = i;
            ++flag;
        }
        else if (str[i] == '*' && flag == 1)
        {
            b = i;
            ++flag;
        }
        else if (str[i] == '*' && flag == 2)
        {
            c = i;
        }
        sum = sum + ((str[i] - '0') * table[i]);
    }

    if (a == 0)
        return 1;
    if (a != 0 && b == 0 && c == 0)
    {
        for (int i = 0; i < 10; ++i)
        {
            int tmp = sum;
            tmp = tmp + i * table[a];
            int num = tmp % 11;
            if (table2[num] == str[17])
                ++cnt;
        }
    }
    else if (b != 0 && c == 0)
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int tmp = sum;
                tmp = tmp + i * table[a] + j * table[b];
                int num = tmp % 11;
                if (table2[num] == str[17])
                    ++cnt;
            }
        }
    }
    else if (c != 0)
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                for (int k = 0; k < 10; ++k)
                {
                    int tmp = sum;
                    tmp = tmp + i * table[a] + j * table[b] + k * table[c];
                    int num = tmp % 11;
                    if (table2[num] == str[17])
                        ++cnt;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int T;
    while (cin >> T)
    {
        while (T--)
        {
            string str = "52012320050116***4";
            //getline(cin, str);
                
            int res = fun(str);
            cout << res << endl;
        }
    }
}

#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define pb push_back
#define ll long long
const int N = 1e6 + 10;
const int M = 1e6;
void read(int& a)
{
    a = 0; int d = 1; char ch;
    while (ch = getchar(), ch > '9' || ch < '0') if (ch == '-') d = -1;
    a = ch ^ 48;
    while (ch = getchar(), ch >= '0' && ch <= '9') a = (a << 3) + (a << 1) + (ch ^ 48);
    a *= d;
}
int d[1005];
queue <int> q;
vector <int> v[1005];
int st[1005], cnt;
int main()
{
    int T; read(T);
    while (T--)
    {
        while (!q.empty()) q.pop();
        int n, m; cnt = 0;
        read(n), read(m);
        for (int i = 1; i <= n; i++) d[i] = 0, v[i].clear();
        while (m--)
        {
            int k; read(k);
            int a, b;
            read(a);
            for (int i = 2; i <= k; i++)
            {
                read(b);
                d[a]++;
                v[b].pb(a);
                a = b;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!d[i])
            {
                sum++; st[++cnt] = i;
                q.push(i);
            }
        }
        if (sum > 1 || sum == 0)
        {
            puts("NO");
            continue;
        }
        bool wtf = 0;
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            bool flag = 0;
            for (auto i : v[tmp])
            {
                d[i]--;
                if (!d[i])
                {
                    if (flag) wtf = 1;
                    q.push(i);
                    st[++cnt] = i;
                    flag = 1;
                }
            }
        }
        if (wtf) puts("NO");
        else
        {
            for (int i = cnt; i; i--) printf("%d ", st[i]);
            putchar('\n');
        }
    }
    return 0;
}