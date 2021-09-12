#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getNext(const string& sub, vector<int>& next)
{
	next[0] = -1;
	next[1] = 0;
	int k = 0;//前一项的k
	int i = 2;
	while (i < sub.size())
	{
		if ((k == -1) || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			++k;
			++i;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(const string& str, const string& sub, int pos)
{
	int strLen = str.size();
	int subLen = sub.size();
	if (strLen == 0 || subLen == 0)
		return -1;
	if (pos < 0 || pos >= strLen)
		return -1;

	vector<int> next(subLen);
	getNext(sub, next);

	int i = pos;//遍历主串
	int j = 0;//遍历子串

	while (i < strLen && j < subLen)
	{
		if ((j == -1) || str[i] == sub[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= subLen)
		return i-j;
	return -1;
}
int main()
{

	cout << KMP("abccba", "cb", 0) << endl;
	return 0;
}