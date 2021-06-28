#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int getMid(vector<int>& arr, int low, int high)
{
    int mid = low + ((high - low) >> 1);

    if (arr[mid] > arr[high])
    {
        swap(arr[mid], arr[high]);
    }
    if (arr[low] > arr[high])
    {
        swap(arr[low], arr[high]);
    }
    if (arr[mid] > arr[low])
    {
        swap(arr[mid], arr[low]);
    }

    return arr[low];
}

int helper(vector<int>& arr, int left, int right)
{
    int key =getMid(arr, left, right);
    int start = left;
    while (left < right)
    {
        while (left < right && arr[right] >= key)
            --right;
        while (left < right && arr[left] <= key)
            ++left;
        swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[start]);
    return left;
}

void quickSort(vector<int>& arr)
{
    stack<int> st;
    st.push(arr.size() - 1);
    st.push(0);

    while (!st.empty())
    {
        int left = st.top();
        st.pop();
        int right = st.top();
        st.pop();
        int div = helper(arr, left, right);
        if (left < div - 1)
        {
            st.push(div - 1);
            st.push(left);
        }
        if (div + 1 < right)
        {
            st.push(right);
            st.push(div + 1);
        }
    }
}

int main()
{
    vector<int> arr;
    int n = 0;
    cin >> n;
    for (int i = n; i >= 0; --i)
    {
        arr.push_back(i);
    }
	quickSort(arr);
	//int a = getMid(arr, 8, 10);
	return 0;
}