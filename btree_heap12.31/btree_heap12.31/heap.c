#include<stdio.h>

//假设为小堆
void SShiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置
		if ((child + 1 < n) && (arr[child + 1] < arr[child]))
		{
			//右孩子
			++child;
		}
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp; 

			curPos = child;
			child = 2 * curPos + 1;
		}
		else
		{
			break;
		}
	}
} 

//假设为大堆
void BShiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;

	while (child < n)
	{
		//从左右孩子中找到一个最大值的位置
		if ((child + 1 < n) && (arr[child + 1] > arr[child]))
		{
			//右孩子
			++child;
		}
		//需要调整的数据和最大 值进行比较
		if (arr[child] > arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;

			curPos = child;
			child = 2 * curPos + 1;
		}
		else
		{
			break;
		}
	}
}

void CreatSmallHeap(int* arr, int n)
{
	//从最后一个非叶子开始向下调整
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		SShiftDown(arr, n, i);
	}
}

void CreaBigHeap(int* arr, int n)
{
	//从最后一个非叶子开始向下调整
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		BShiftDown(arr, n, i);
	}
}

void test()
{
	int arr[] = { 56, 12, 58, 87, 45, 36, 12, 3, 99 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CreatSmallHeap(arr, size);
	
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}

//void test()
//{ 
//	int arr[] = { 10, 5, 3, 8, 7, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	SShiftDown(arr, size, 0);
//}

int main()
{
	test();

	return 0;
}