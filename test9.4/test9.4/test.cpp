#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;

int func(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int res = INT_MIN;
    for (int l = 0; l < n; ++l)
    {
        vector<int> sums(n, 0);
        for (int r = l; r < n; ++r)
        {
            for (int i = 0; i < n; ++i)
            {
                sums[i] = sums[i] + matrix[i][r];
            }
            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums)
            {
                curSum = curSum + sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - 10000);
                if (it != accuSet.end())
                    curMax = max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            res = max(res, curMax);
        }
    }
    return res;
}

int main()
{
    int n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    int res = func(matrix);
    cout << res << endl;
}