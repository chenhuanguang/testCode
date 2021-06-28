#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		bool flag = false;
		for (int j = 0; j < arr.size() - 1; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j + 1], arr[j]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

//int main()
//{
//	vector<int> arr = { 200,1,9,7,5,3,8,2,4,6, 100 };
//	bubbleSort(arr);
//	return 0;
//}