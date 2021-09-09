#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> arr;
        arr.push_back(num);
        while (cin >> num)
        {
            arr.push_back(num);
        }
        int n = arr.size();

        int min = arr[0];
        int res = -1;
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] >= arr[i - 1])
                continue;
            else
            {
                res = max(res, arr[i - 1] - min);
                min = arr[i];
            }
        }

        cout << res << endl;
    }

    return 0;
}