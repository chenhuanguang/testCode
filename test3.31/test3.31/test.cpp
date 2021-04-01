#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums{ 1, 2, 4, 4, 5 };
    int target = 4;
    int res;
    int sz = nums.size();
    int left = 0;
    int right = sz - 1;
    int mid;
    if (sz <= 0)
        res = -1;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] <= target)
        {
            left = mid;
        }
        else if (nums[mid] < target)
        {
            right = mid - 1;
        }
    }

    if (nums[right] != target)
        res= -1;
    res = right;
    cout << res;
}