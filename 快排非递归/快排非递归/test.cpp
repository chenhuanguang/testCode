//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
////第一个参数为引用
//int partion(vector<int>& arr, int left, int right)
//{
//	int key = arr[left];
//	int start = left;
//	while (left < right)
//	{
//		//必须先从后面开始找
//		while (left < right && arr[right] >= key)
//		{
//			--right;
//		}
//		while (left < right && arr[left] <= key)
//		{
//			++left;
//		}
//		swap(arr[left], arr[right]);
//	}
//	swap(arr[start], arr[left]);
//	return left;
//}
//
//void quickSort(vector<int>& arr, int begin, int end)
//{
//	stack<int> st;
//	st.push(end);
//	st.push(begin);
//	while (!st.empty())
//	{
//		int left = st.top();
//		st.pop();
//		int right = st.top();
//		st.pop();
//		int div = partion(arr, left, right);
//		if (left < div - 1)
//		{
//			st.push(div - 1);
//			st.push(left);
//		}
//		if (right > div + 1)
//		{
//			st.push(right);
//			st.push(div + 1);
//		}
//	}
//}
//int main()
//{
//	vector<int> v = { 4,1,3,7,9,2,6,5,10,8};
//	quickSort(v, 0, v.size() - 1);
//	for (const auto& e : v)
//	{
//		cout << e << " ";
//	}
//}

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void topK(vector<int>& arr, int k)
{
	vector<int> res(arr.begin(), arr.begin() + k);
	make_heap(res.begin(), res.end(), greater<int>());
	for (size_t i = k; i < arr.size(); ++i)
	{
		if (arr[i] > res[0])
		{
			res[0] = arr[i];
			make_heap(res.begin(), res.end(), greater<int>());
		}
	}
	for (int i = 0; i < k; ++i)
	{
		arr[i] = res[i];
	}
}

int main()
{
	vector<int> v = { 4,1,3,7,9,2,6,5,10,8 };
	int key = 3;
	topK(v, key);
	for (int i = 0; i < 3; ++i)
	{
		cout << v[i] << " ";
	}
	return 0;
}

//void shiftDown(vector<int>& arr, int n, int curPos)
//{
//	//左孩子=2 * 父 + 1
//	int child = 2 * curPos + 1;
//	while (child < n)
//	{
//		if ((child + 1 < n) && (arr[child + 1] < arr[child]))
//		{
//			++child;
//		}
//		if (arr[child] < arr[curPos])
//		{
//			swap(arr[child], arr[curPos]);
//			curPos = child;
//			child = 2 * curPos + 1;
//		}
//		else
//			break;
//	}
//}
//
//void creatHeap(vector<int>& arr, int n)
//{
//	//从最后一个非叶子开始向下调整
//	for (int i = (n - 2) / 2; i >= 0; --i)
//	{
//		shiftDown(arr, n, i);
//	}
//}
//
//void heapSort(vector<int>& arr)
//{
//	int sz = arr.size();
//	//建堆
//	creatHeap(arr, sz);
//
//	int end = sz - 1;
//	for (int i = 0; i < sz; ++i)
//	{
//		swap(arr[0], arr[end]);//交换首尾元素
//		shiftDown(arr, end, 0);//对end个元素重新建堆
//		--end;
//	}
//}

