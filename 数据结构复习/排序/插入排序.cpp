#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int data = arr[i];
		int end = i - 1;
		while (end >= 0 && arr[end] > data)
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//int main()
//{
//	vector<int> arr = { 200,1,9,7,5,3,8,2,4,6, 100 };
//	insertSort(arr);
//	return 0;
//}