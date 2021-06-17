#include <iostream>
#include <vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len) 
{
    int num1 = 0;//奇数个数
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] / 2 == 1)
            ++num1;
    }
    bool flag = true;//计算偶数
    if (len - num1 < num1)
        flag = false; //计算奇数
    int idx1 = 0;
    int idx2 = len - 1;
    while (idx1 < idx2)
    {
        if (flag)//偶数位上都是偶数
        {
            if (idx1 % 2 == 0 && arr[idx1] % 2 == 1 || idx1 % 2 == 1 && arr[idx1] % 2 == 0)
            {
                while (idx1 < idx2)
                {
                    if (idx2 % 2 == 1 && arr[idx2] % 2 == 0)
                        break;
                    --idx2;
                }
                swap(arr[idx1], arr[idx2]);
            }
        }
        else
        {
            if (idx1 % 2 == 1 && arr[idx1] % 2 == 0 || idx1 % 2 == 0 && arr[idx1] % 2 == 1)
            {
                while (idx1 < idx2)
                {
                    if (idx2 % 2 == 0 && arr[idx2] % 2 == 1)
                        break;
                    --idx2;
                }
                swap(arr[idx1], arr[idx2]);
            }
        }
        ++idx1;
    }
}

int main()
{
    vector<int> arr = {2, 3, 5, 8, 6, 4, 0, 1, 7};
    oddInOddEvenInEven(arr, arr.size());
    for (auto& e : arr)
    {
        cout << e << " ";
    }
    return 0;
}