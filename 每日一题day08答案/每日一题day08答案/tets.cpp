#include <iostream>
#include <string>
#include <vector>
using namespace std;
//用于判断是否按字典排序
bool isDictionaries(const string& str1, const string& str2)
{
	//库中的比较以就是按字典排序的
	//前者大于后者，不满足字典排序
	if (str1 >= str2)
		return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	int a = 1;
	int b = 1;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		//不是字典排序
		if (v[i] >= v[i + 1])
		{
			a = 0;
		}
		//不是按长度排序
		if (v[i].size() >= v[i + 1].size())
		{
			b = 0;
		}
		if (b == 0 && a == 0)
			break;
	}
	if (a && b)
		cout << "both" << endl;
	else if (a && !b)
		cout << "lexicographically" << endl;
	else if (!a && b)
		cout << "lengths" << endl;
	else if (!a && !b)
		cout << "none" << endl;
	return 0;
}
