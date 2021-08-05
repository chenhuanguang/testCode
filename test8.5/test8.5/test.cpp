#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int>& arr)
{
	int i = 0;
	int j = 0;
	while (i < arr.size())
	{
		swap(arr[i], arr[j]);

		while (i < arr.size() && arr[i] == arr[j])
			++i;
		++j;
	}
	return j + 1;
}

int main()
{

	vector<int> arr = { 1,1,1,2,2,3,4,4,6,8,8 };
	int res = fun(arr);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << res << endl;
	return 0;
}