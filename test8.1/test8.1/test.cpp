#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> arr;
    int num;
    int k;
    bool flag = 1;
    while (cin >> num)
    {
        arr.push_back(num);
        if (cin.get() == ':')
        {
            cin >> k;
            break;
        }
    }
    vector<float> avgs;
    float maxAvg = -100000.0;
    for (int i = 0; i <= arr.size() - k; ++i)
    {
        float sum = 0;
        for (int j = i; j < k + i; ++j)
        {
            sum += arr[j];
        }
        float avg = sum / k * 1.0;
        avgs.push_back(avg);
        if (i)
        {
            maxAvg = max(maxAvg, (avg - avgs[i - 1]) / avgs[i - 1]);
        }
    }
    maxAvg *= 100;
    printf("%.2lf%%\n", maxAvg);
    return 0;
}