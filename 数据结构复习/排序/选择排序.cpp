#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void selectSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		int minIdx = i;
		for (int j = i; j < arr.size(); ++j)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		swap(arr[i], arr[minIdx]);
	}
}

//int main()
//{
//	vector<int> arr = { 200,1,9,7,5,3,8,2,4,6, 100 };
//	selectSort(arr);
//	return 0;
//}