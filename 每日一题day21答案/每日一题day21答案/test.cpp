//#include <iostream>
//#include <vector>
//using namespace std;
//void fun1(vector<int>& vec)
//{
//	int sz = vec.size();
//	int left = 0;
//	int right = sz / 2;
//	vector<int> res;
//	while (left < sz / 2)//一次放两张，交替放牌
//	{
//		res.push_back(vec[left++]);
//		res.push_back(vec[right++]);
//	}
//	vec = res;
//}
//void fun(vector<int>& vec, int k)
//{
//	while (k--)//洗k次牌
//	{
//		fun1(vec);
//	}
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int t, n, k;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> k;
//		vector<int> vec(2 * n);
//		for (int i = 0; i < 2 * n; ++i)
//		{
//			cin >> vec[i];
//		}
//		fun(vec, k);
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//小于4首歌曲
void fun1(string& str, int n, vector<int>& vec, int& idx)
{
	vec.resize(n);
	for (int i = 0; i < n; ++i)
	{
		vec[i] = i + 1; //设置歌曲位置
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'U') //光标向上移
		{
			if (idx == 1)//如果是第一页需要将光标移至最后一行
				idx = n;
			else
				--idx; //光标向上移一行
		}
		else    //光标向下移
		{
			if (idx == n) //如果是最后一页需要将光标移至第一行
				idx = 1;
			else
				++idx;//光标向下移一行
		}
	}
}
void fun2(string& str, int n, vector<int>& vec, int& idx)
{
	vec.resize(4);
	for (int i = 0; i < 4; ++i)
	{
		vec[i] = i + 1;//初始化第一页的歌的显示
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'U')
		{
			if (idx == 1) //需要翻页到最后一页
			{
				for (int i = 0; i < 4; ++i)
				{
					vec[i] += n - 4;//页面都需要更新
				}
				idx = n;//光标移至最后一行
			}
			else 
			{
				if (idx == vec[0])//光标在一页中的第一首歌，一页一页得翻
				{
					for (int i = 0; i < 4; ++i)
					{
						--vec[i];
					}
				}
				--idx;
			}
		}
		else
		{
			if (idx == n)//需要翻页至第一页
			{
				for (int i = 0; i < 4; ++i)
				{
					vec[i] -= n - 4;
				}
				idx = 1;
			}
			else
			{
				if (idx == vec[3])//光标在一页中最后一个位置，需要一页一页得翻
				{
					for (int i = 0; i < 4; ++i)
					{
						++vec[i];
					}
				}
				++idx;
			}
		}
	}
}
void fun(string& str, int n)
{
	vector<int> res;
	int idx = 1;
	if (n <= 4)
		fun1(str, n, res, idx);
	else
		fun2(str, n, res, idx);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	cout << idx << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		string str;
		cin >> str;
		fun(str, n);
	}
	return 0;
}