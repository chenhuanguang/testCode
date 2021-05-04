#include <iostream>
#include <string>
using namespace std;

int StrToInt(string str)
{
	if (str.empty())
		return 0;
	int flag = 1;
	if (str[0] == '-')
	{
		flag = -1;
	}

}

int main()
{


	return 0;
}


//int main()
//{
//	int h, w;
//	cin >> h >> w;
//	vector<vector<int>> vv;
//	vv.resize(h);
//	int count = 0;
//	for (auto& v : vv)
//	{
//		v.resize(w, 1);
//	}
//	for (int i = 0; i < h; ++i)
//	{
//		for (int j = 0; j < w; ++j)
//		{
//			if (vv[i][j] == 1)
//			{
//				++count;
//				if (i + 2 < h)
//				{
//					vv[i + 2][j] = 0;
//				}
//				if (j + 2 < w)
//				{
//					vv[i][j + 2] = 0;
//				}
//			}
//		}
//	}
//	cout << count << endl;
//	return 0;
//}