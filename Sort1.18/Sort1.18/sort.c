#include <stdio.h>

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
		while (end >=0 && arr[end] >= data)
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

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	PrintArr(arr, size);

	return 0;
}