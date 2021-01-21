
#include"seqList.h"

//初始化顺序表
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

void seqListpopBack(seqList* sl)
{
	/*if (sl == NULL)
		return;
	sl->size--;*/
	seqListErase(sl, sl->size-1);
}

int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->size == 0)
		return 0;
	return 1;
}

void seqListPrint(seqList* sl)
{
	if (sl == NULL)
		return ;
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}

int seqListSize(seqList* sl)
{
	if (sl == NULL || sl->size == 0)
		return 0;
	else
		return sl->size;
}

void seqListpushBack(seqList* sl, SLDataType val)
{
	//if (sl == NULL)
	//	return;
	////检查容量
	//seqListCheckCapacity(sl);

	//sl ->data[sl->size] = val;
	//sl->size++;
	seqListInsert(sl, sl->size, val);
}

SLDataType seqListAt(seqList* sl, int pop)
{
	return sl->data[pop];
}

void seqListCheckCapacity(seqList* sl)
{
	if (sl->size == sl->capacity)
	{
		//空间已满
		//开新的空间
		int newCapacity = sl->capacity == 0 ? 1 : 2 * sl->capacity;
		
		sl->data = (SLDataType*)realloc(sl->data, newCapacity * sizeof(SLDataType));
		if (sl->data)
			return;

		//更新容量
		sl->capacity = newCapacity;

	}
}

void seqListPushFront(seqList* sl, SLDataType val)
{
	/*if (sl == NULL)
		return;
	seqListCheckCapacity(sl);

	int end = sl->size;
	while (end>0)
	{
		sl->data[end] = sl->data[end - 1];
		--end;
	}
	sl->data[0] = val;
	sl->size++;*/
	seqListInsert(sl, 0, val);
}

void seqListPopFront(seqList* sl)
{
	/*if (sl == NULL || sl->size == 0)
		return;
	int start = 0;
	while (start<(sl->size))
	{
		sl->data[start] = sl->data[start+1];
		++start;
	}
	sl->size--;*/
	seqListErase(sl, 0);
}

void seqListInsert(seqList* sl, int pos, SLDataType val)
{
	if (sl == NULL)
		return;
	if (pos <0|| pos>(sl->size))
		return;
	seqListCheckCapacity(sl);
	int end = sl->size;
	while (end > pos)
	{
		sl->data[end] = sl->data[end - 1];
		--end;
	}
	sl->data[pos] = val;
	sl->size++;
}

void seqListErase(seqList* sl, int pos)
{
	if (sl == NULL || sl->size == 0)
		return;
	if (pos <0 || pos>=(sl->size))
		return;
	seqListCheckCapacity(sl);
	int start = pos;
	while (start < (sl->size)-1)
	{
		sl->data[start] = sl->data[start + 1];
		++start;
	}
	sl->size--;
}

int seqListFind(seqList* sl, SLDataType val)
{
	if (sl == NULL || sl->size == 0)
		return -1;
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->data[i] == val)
			return i;
	}
	return -1;
}

void seqListDestroy(seqList* sl)
{
	if (sl != NULL && sl->data != NULL)
	{
		free(sl->data);
		sl->data=NULL;
	}
}

SLDataType seqListBack(seqList* sl)
{
	return sl->data[sl->size - 1];
}

//void test()
//{
//	seqList sl;
//	initseqList(&sl);
//	seqListpushBack(&sl, 1);
//	seqListpushBack(&sl, 2);
//	seqListpushBack(&sl, 3);
//	seqListPrint(&sl);
//	seqListpopBack(&sl);
//	seqListPrint(&sl);
//}

//void test()
//{
//	seqList sl;
//	initseqList(&sl);
//	seqListpushBack(&sl, 1);
//	seqListpushBack(&sl, 2);
//	seqListpushBack(&sl, 3);
//	seqListpushBack(&sl, 4);
//	seqListPushFront(&sl, 0);
//	seqListPrint(&sl);
//	seqListErase(&sl, 0);// 1 2 3 4
//	seqListPrint(&sl);
//	 // 1 2 4
//	seqListPrint(&sl);
//
//}

//void test()
//{
//	seqList sl;
//	initseqList(&sl);
//	seqListpushBack(&sl, 1);
//	seqListpushBack(&sl, 2);
//	seqListpushBack(&sl, 3);
//	seqListpushBack(&sl, 4);
//	seqListpushBack(&sl, 5);
//	seqListPrint(&sl);
//	seqListpopBack(&sl);
//	seqListPrint(&sl);
//	seqListpopBack(&sl);
//	seqListPrint(&sl);
//	seqListpopBack(&sl);
//	seqListPrint(&sl);
//	seqListpopBack(&sl);
//	seqListPrint(&sl);
//	seqListpopBack(&sl);
//	seqListPrint(&sl);
//}

//int main()
//{
//	test();
//}