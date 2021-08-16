#include <iostream>
#include <string>
using namespace std;

int fun(const string& str1, const string& str2)
{
	int sz1 = str1.size();
	int sz2 = str2.size();

	if (sz1 < sz2)
		return -1;

	for (int i = 0; i <= sz1 - sz2; ++i)
	{
		if (str1[i] == str2[0])
		{
			int j;
			for (j = 1; j < sz2; ++j)
			{
				if (str1[i + j] != str2[j])
				{
					break;
				}
			}
			if (j == sz2)
			{
				return i;
				break;
			}
		}
	}

	return -1;
}

int fun1(const string& str1, const string& str2)
{
	if (str1.size() < str2.size())
		return -1;
	int idx = str1.find(str2);
	return idx;
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		cout << fun1(str1, str2) << endl;
	}
	return 0;
}