#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MLS(vector<int>& arr)
{
    int res = 0;
    //≈≈–Ú
    sort(arr.begin(), arr.end());
    //»•÷ÿ
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        int cnt = 1;
        while ((i < arr.size() - 1) && ((arr[i] + 1 == arr[i + 1]) || (arr[i] == arr[i + 1])))
        {
            if (arr[i] + 1 == arr[i + 1])
                ++cnt;
            ++i;
        }
        if (cnt > res)
            res = cnt;
    }

    return res;
}

int main()
{

    vector<int> arr = { 100,1,2,3,4,7,6,5 };
    MLS(arr);
    return 0;
}
