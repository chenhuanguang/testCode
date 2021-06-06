#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int GetMid(vector<int>& arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	int beginNum= arr[begin];
	int midNum = arr[mid];
	int endNum = arr[end];
	if ((midNum - beginNum) * (beginNum - endNum) >= 0)
		return begin;
	else if ((endNum - midNum) * (midNum - beginNum) >= 0)
		return mid;
	else
		return end;
}

//第一个参数为引用
int partion(vector<int>& arr, int left, int right)
{
	int mid = GetMid(arr, left, right);
	swap(arr[left], arr[mid]);
	int key = arr[left];
	int start = left;
	while (left < right)
	{
		//必须先从后面开始找
		while (left < right && arr[right] >= key)
		{
			--right;
		}
		while (left < right && arr[left] <= key)
		{
			++left;
		}
		swap(arr[left], arr[right]);
	}
	swap(arr[start], arr[left]);
	return left;
}

void quicksort(vector<int>& arr, int begin, int end)
{
	stack<int> st;
	st.push(end);
	st.push(begin);
	while (!st.empty())
	{
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		int div = partion(arr, left, right);
		if (left < div - 1)
		{
			st.push(div - 1);
			st.push(left);
		}
		if (right > div + 1)
		{
			st.push(right);
			st.push(div + 1);
		}
	}
}
int main()
{
	vector<int> v = { 4,1,3,7,9,2,6,5,10,8};
	quicksort(v, 0, v.size() - 1);
	for (const auto& e : v)
	{
		cout << e << " ";
	}
}


