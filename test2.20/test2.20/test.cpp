#include <iostream>
using namespace std;

//int fun(int i, int j)
//{
//	if (i <= 0 || j <= 0)
//		return 1;
//	return 2 * fun(i - 3, j / 2);
//}
//
//int main()
//{
//	//cout << fun(15, 20) << endl;
//
//	//int a[] = { 2, 4, 6, 8 };
//	//int* p = a;
//	//for (int i = 0; i < 4; ++i)
//	//{
//	//	a[i] = *p++;
//	//}
//	//cout << a[2] << endl;
//
//	int a = 1, b = 2;
//
//	for (; a < 8; ++a)
//	{
//		b += a;
//		a += 2;
//	}
//
//	cout << a << " " << b << endl;
//
//	return 0;
//}

int findUnsortedSubarray(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 0;
    }

    int start = 0;
    int tail = numsSize;
    int left = 0;
    int right = 1;
    bool flag = true;
    while (right < numsSize)
    {
        if (nums[left] > nums[right])
        {
            flag = false;
            if (start == 0)
            {
                start = left;

            }
            else
            {
                tail = right + 1;
            }
        }
        ++left;
        ++right;
    }

    if (flag == false)
        return tail - start;
    return 0;
}

int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    findUnsortedSubarray(arr, 5);
    return 0;
}