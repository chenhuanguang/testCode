#include"heap.h"

void HeapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_capacity = hp->_size = 0;
}

void SShiftDown(HDataType* arr, int n, int curPos)
{
	int child = 2 * curPos + 1;

	while (child < n)
	{
		if ((child + 1 < n) && (arr[child + 1] < arr[child]))
		{
			++child;
		}
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

void BShiftDown(HDataType* arr, int n, int curPos)
{
	int child = 2 * curPos + 1;

	while (child < n)
	{
		if ((child + 1 < n) && (arr[child + 1] > arr[child]))
		{
			++child;
		}
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


void SShiftUp(int* arr, int n, int cur)
{
	while (cur > 0)
	{
		int parent = (cur - 1) / 2;

		if (arr[cur] < arr[parent])
		{
			Swap(&arr[cur], &arr[parent]);

			cur = parent;
		}
		else
		{
			break;
		}
	}
}

void BShiftUp(int* arr, int n, int cur)
{
	while (cur > 0)
	{
		int parent = (cur - 1) / 2;

		if (arr[cur] > arr[parent])
		{
			Swap(&arr[cur], &arr[parent]);

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
		if (hp->_data == NULL)
			return;
		hp->_capacity = newCapacity;
	}
}

void SHeapPush(heap* hp, HDataType val)
{
	CheckCapacity(hp);
	hp->_data[hp->_size++] = val;
	SShiftUp(hp->_data, hp->_size, hp->_size - 1);
}

void BHeapPush(heap* hp, HDataType val)
{
	CheckCapacity(hp);
	hp->_data[hp->_size++] = val;
	BShiftUp(hp->_data, hp->_size, hp->_size - 1);
}

void SHeapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	hp->_size--;
	SShiftDown(hp->_data, hp->_size, 0);
}

void BHeapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	hp->_size--;
	BShiftDown(hp->_data, hp->_size, 0);
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


void SHeapSort(heap* hp)
{
	int end = hp->_size - 1;
	
	for (int i = 0; i < hp->_size; ++i)
	{
		Swap(&hp->_data[0], &hp->_data[end]);
		SShiftDown(hp->_data, end, 0);
		--end;
	} 

}

void BHeapSort(heap* hp)
{
	int end = hp->_size - 1;

	for (int i = 0; i < hp->_size; ++i)
	{
		Swap(&hp->_data[0], &hp->_data[end]);
		BShiftDown(hp->_data, end, 0);
		--end;
	}
}

void HeapDestory(heap* hp)
{
	if (hp == NULL)
		return;
	free(hp->_data);
	hp->_data = NULL;
}

void PrintTopK(int* a, int n, int k)
{
	heap hp;
	HeapInit(&hp);
	for (int i = 0; i < n; ++i)
	{
		BHeapPush(&hp, a[i]);
	}

	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		BHeapPop(&hp);
	}
	printf("\n");
}

void test()
{
	heap hp;
	HeapInit(&hp);
	BHeapPush(&hp, 15);
	BHeapPush(&hp, 56);
	BHeapPush(&hp, 10);
	BHeapPush(&hp, 30);
	BHeapPush(&hp, 70);
	BHeapPush(&hp, 25);
	BHeapPop(&hp);
	BHeapSort(&hp);
	
	for (int i = 0; i < hp._size; ++i)
	{
		printf("%d ", hp._data[i]);
	}
	printf("\n");


	/*while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		SHeapPop(&hp);
	}
	printf("\n");*/
}

int main()
{
	//test();
	int arr[] = { 54,56,98,35,75,12,3,6,9,8,546,235,1856,6985 };
	int n = sizeof(arr) / sizeof(int);
	PrintTopK(arr, n, 5);

	return 0;
}


