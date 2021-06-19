#include <iostream>
#include <vector>
using namespace std;

int backPackII(int m, vector<int>& A, vector<int>& V)
{
    // write your code here
    //int n = A.size();
    //vector<vector<int>> maxValue(n + 1, vector<int>(m + 1, 0));
    //for (int i = 1; i <= n; ++i)//可选择的物品个数
    //{
    //    for (int j = 1; j <= m; ++j)//背包的大小
    //    {
    //        if (A[i - 1] > j)//物品大小大于背包容量，则此物品放不下，背包总价值还是上一个物品的总价值
    //            maxValue[i][j] = maxValue[i - 1][j];
    //        else
    //            //背包容量大于物品容量，则有两种情况：1、不放该物品；2、放该物品
    //            //1、不放该物品则价值还是上一个物品的总价值
    //            //2、放物品则需要将背包大小减去当前物品的大小，然后再利用剩下的容量的最大价值+当前物品价值
    //            //判断哪个价值大，则就表示该[i][j]的最大价值就为谁
    //            maxValue[i][j] = max(maxValue[i - 1][j], maxValue[i - 1][j - A[i - 1]] + V[i - 1]);
    //    }
    //}

    //return maxValue[n][m];

    int n = A.size();
    vector<int> maxValue(m + 1, 0);
    for (int i = 1; i <= n; ++i)//可选择的物品个数
    {
        for (int j = m; j > 0; --j)//背包的大小
        {
            if (A[i - 1] <= j)
                maxValue[j] = max(maxValue[j], maxValue[j - A[i - 1]] + V[i - 1]);
        }
    }

    return maxValue[m];
}

int main()
{

	return 0;
}