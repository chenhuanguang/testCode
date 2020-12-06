#include<iostream>
#include<assert.h>
using namespace std;

int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	int a = BinarySearch(arr, 10, 3);
	printf("%d\n", a);
	return 0;
}

/*√∞≈›≈≈–Ú
void BubbleSort(int *a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,10 };

	BubbleSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/