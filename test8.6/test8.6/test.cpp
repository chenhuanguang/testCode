#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int q1;
    int q2;
    int p;
    cin >> q1 >> q2 >> p;
    int x;
    cin >> x;
    vector<vector<int>> vv(x, vector<int>(2, 0));
    for (int i = 0; i < x; ++i)
    {
        cin >> vv[i][0] >> vv[i][1];
    }
    int y;
    cin >> y;
    vector<int> v(y);
    for (int i = 0; i < y; ++i)
    {
        cin >> v[i];
    }

    int cnt = 0;
    int total = q1 + q2;
    for (int i = 0; i < x; ++i)
    {
        int score = vv[i][0] + vv[i][1];
        if (score <= total + p && score >= total - p)
            cnt++;
    }

    for (int i = 0; i < y - 1; ++i)
    {
        for (int j = i + 1; j < y; ++j)
        {
            int score = v[i] + v[j];
            if (score <= total + p || score >= total - p)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}