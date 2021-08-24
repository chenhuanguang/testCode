#include <iostream>
#include <string>
using namespace std;

char num[1000000];
int A[1000000];
int B[1000000];
int count1(string& ver)
{
    int x = 0, y = 0, cnt = 0;
    for (int i = 0; i < ver.size(); ++i)
    {
        if (ver[i] == '.')
        {
            cnt++;
            num[x] = '\0';
            A[y++] = atoi(num);
            x = 0;
            continue;
        }
        num[x++];
    }
    num[x] = '\0';
    A[y++] = atoi(num);

    return cnt;
}

int count2(string& ver)
{
    int x = 0, y = 0, cnt = 0;
    for (int i = 0; i < ver.size(); ++i)
    {
        if (ver[i] == '.')
        {
            cnt++;
            num[x] = '\0';
            B[y++] = atoi(num);
            x = 0;
            continue;
        }
        num[x++];
    }
    num[x] = '\0';
    B[y++] = atoi(num);

    return cnt;
}

int main()
{
    string ver1, ver2;

    int len = 0;
    int res = 0;
    while (cin >> ver1 >> ver2)
    {
        int aLen = count1(ver1);
        int bLen = count2(ver2);
        cout << A[0] << endl;
        cout << A[1] << endl;
    }
}