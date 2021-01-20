#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

void ShiftDown(int* arr, int size, int parent)
{
	int child = 2 * parent + 1;
	
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			int tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;

			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}

}

//插入排序
void InsertSort(int* arr, int size)
{
	//空数组  或 只有一个元素的数组
	if (arr == NULL || size == 1)
	{
		return;
	}

	//遍历未排序的元素
	for (int i = 1; i < size; ++i)
	{
		//保存未排序部分的第一个元素
		int data = arr[i];
		//已排序的最后一个元素的索引
		int end= i - 1;
		while (end >=0 && arr[end] > data)
		{
			//前面元素覆盖后面元素
			arr[end + 1] = arr[end];
			//向前查找
			--end;
		}
		//找到位置并在该位置的下一个位置插入
		arr[end + 1] = data;
	}
}

//希尔排序
void ShellSort(int* arr, int size)
{
	int gap = size;
	while (gap > 0)
	{
		gap = gap / 2;
		//最后一趟排序，间隔必须是1，保证所有有效数据在同一组
		for (int i = gap; i < size; ++i)
		{
			//同一组数据，最后一个有序数据的位置
			int end = i - gap;
			//待插入排序
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

//选择排序
void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			Swap(arr, i, minIdx);
		}
	}
}

//优化选择排序
void SelectSort2(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIdx = i;
		int maxIdx = i;
		int end = size - 1;
		for (int j = i + 1; j <= end; ++j)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
			if (arr[j] > arr[maxIdx])
			{
				maxIdx = j;
			}
		}

		Swap(arr, i, minIdx);
		if (maxIdx == i)
		{
			maxIdx = minIdx;
		}
		Swap(arr, end--,maxIdx);
	}
}

//堆排序
void HeapSort(int* arr, int size)
{
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		ShiftDown(arr, size, i);
	}

	int end = size - 1;
	while (end > 0)
	{
		Swap(arr, 0, end);
		ShiftDown(arr, end, 0);
		--end;
	}
}

void BubbleSort(int* arr, int size)
{
	int n = size - 1;
	//用于记录每轮冒泡最后交换的位置，优化。
	int pos = 0;

	for (int i = 0; i < size; ++i)
	{
		//用于标记该轮冒泡是否有数据交换
		bool flag = false;
		for (int j = 0; j < n; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j + 1);
				flag = true;
				//最后一次交换位置，下轮冒泡时后面就不用遍历了。
				pos = j;
			}
		}
		if (flag != true)
		{
			//元素未交换，说明已有序，退出
			break;
		}
		n = pos;
	}
}

//获取基准值：三数取中法：起始， 中间， 结束
int GetMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}

//返回基准值位置
int Partion(int* arr, int begin, int end)
{
	//获取基准值的位置
	int mid = GetMid(arr, begin, end);
	//把基准值放到起始位置
	Swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;

	while (begin < end)
	{
		//从后向前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
		{
			--end;
		}
		//从前向后再找大于基准值的位置
		while (begin < end && arr[begin] <= key)
		{
			++begin;
		}
		Swap(arr, begin, end);
	}
	//交换相遇位置的数据和基准值
	Swap(arr, start, begin);
	return begin;
}

//数据有序时，没有优化可能会导致栈溢出（代码优化，重新找基准值）
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div:一次划分之后，基准值的位置
	int div = Partion(arr, begin, end);
	//左右两部分进行快速排序
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void TestInsertSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	PrintArr(arr, size);
}

void TestShellSort()
{
	int arr[] = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	PrintArr(arr, size);
}

void TestSelectSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	PrintArr(arr, size);
}

void TestHeapSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	PrintArr(arr, size);
}

void TestBubbleSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	PrintArr(arr, size);
}

void TestQuickSort()
{
	int arr[] = { 4, 1, 3, 7, 9, 2, 6, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	PrintArr(arr, size);
}

void Test()
{
	int n = 0;
	printf("数据量： ");
	scanf("%d", &n);

	srand((unsigned)time(NULL));
	int* src = (int*)malloc(sizeof(int) * n);
	int* dest1 = (int*)malloc(sizeof(int) * n);
	int* dest2 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		src[i] = rand();
	}
	memcpy(dest1, src, sizeof(int) * n);
	memcpy(dest2, src, sizeof(int) * n);

	time_t begin = clock();
	InsertSort(dest1, n);
	time_t end = clock();
	printf("InsertSort：%lld\n", end - begin);

	begin = clock();
	ShellSort(dest2, n);
	end = clock();
	printf("ShellSort：%lld\n", end - begin);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//Test();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	TestQuickSort();
	return 0;
}