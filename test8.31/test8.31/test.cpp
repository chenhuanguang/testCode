#include <iostream>
#include <vector>
using namespace std;
//����һֻ��Ʊ�ļ۸����ߣ�Ҫ��ֻ����һ�ν��ף�����������档��ע��һЩ�쳣���߽�����������ÿ�ν���1�ɡ�
int getMaxProfit(const vector<int>& prices) 
{
	int sz = prices.size();
	if (sz <= 1)
		return 0;
	int profit = 0;
	int max = prices[sz - 1];
	int maxProfit = 0;
	for (int i = sz - 2; i >= 0; --i)
	{
		profit = max - prices[i];
		if (profit < 0)
		{
			max = prices[i];
		}
		else if (profit > maxProfit)
		{
			maxProfit = profit;
		}
	}

	return maxProfit;
}

int getMaxProfit2(const vector<int>& prices)
{
	int sz = prices.size();
	int maxProfit = 0;
	for (int i = 1; i < sz; ++i)
	{
		if (prices[i] > prices[i - 1])
		{
			maxProfit += (prices[i] - prices[i - 1]);
		}
	}
	return maxProfit;
}

int getMaxProfit3(const vector<int>& prices)
{
	int sz = prices.size();
	if (sz <= 1)
		return 0;
	vector<vector<int>> arr(sz, vector<int>(5))
}

int main()
{
	vector<int> prices = { 3, 5, 2, 8, 7 };
	int res = getMaxProfit(prices);
	cout << res << endl;
	return 0;
}