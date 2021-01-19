#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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
	TestHeapSort();
	return 0;
}