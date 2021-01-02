#include<stdio.h>
#include<stdlib.h>
typedef int HDataType;

typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

void HeapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_capacity = hp->_size = 0;
}

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

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//logn
void SShiftUp(int* arr, int n, int cur)
{
	while (cur > 0)
	{
		//父节点的位置
		int parent = (cur - 1) / 2;

		//和父结点进行比较
		if (arr[cur] < arr[parent])
		{
			//交换
			Swap(&arr[cur], &arr[parent]);

			//更新到父节点并继续执行向上调整算法
			cur = parent;
		}
		else
		{
			break;
		}
	}
}

void CheckCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * newCapacity);
	}
}

//堆的插入
void HeapPush(heap* hp, HDataType val)
{
	//检查容量
	CheckCapacity(hp);
	//尾插
	hp->_data[hp->_size++] = val;
	//向上调整
	SShiftUp(hp->_data, hp->_size, hp->_size - 1);
}

//堆的删除(堆顶元素)
void HeapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	//交换
	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	hp->_size--;
	//向下调整
	SShiftDown(hp->_data, hp->_size, 0);
}

int HeapEmpty(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

HDataType HeapTop(heap* hp)
{
	return hp->_data[0];
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


void HeapSort()
{
	int arr[] = { 56, 12, 58, 87, 45, 36, 13 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//建堆
	CreatSmallHeap(arr, size);

	//堆的最后一个元素
	int end = size - 1;
	//循环交换向下调整
	for (int i = 0; i < size; ++i) //n
	{
		Swap(&arr[0], &arr[end]);
		SShiftDown(arr, end, 0); //logn
		--end;
	} //堆排序的时间复杂度nlogn

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//void test()
//{
//	heap hp;
//	HeapInit(&hp);
//	HeapPush(&hp, 28);
//	HeapPush(&hp, 29);
//	HeapPush(&hp, 45);
//	HeapPush(&hp, 46);
//	HeapPush(&hp, 25);
//	HeapPush(&hp, 38);
//	HeapPush(&hp, 19);
//	HeapPush(&hp, 8);
//
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//}

//void test()
//{ 
//	int arr[] = { 10, 5, 3, 8, 7, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	SShiftDown(arr, size, 0);
//}

int main()
{
	HeapSort();

	return 0;
}


