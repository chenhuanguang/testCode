#include<string.h>
#include<stdlib.h>
#include<stdio.h>
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
	if (sl == NULL)
		return;
	sl->size--;
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
	if (sl == NULL)
		return;
	//检查容量
	seqListCheckCapacity(sl);

	sl ->data[sl->size] = val;
	sl->size++;
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


		//更新容量
		sl->capacity = newCapacity;

	}
}

void test()
{
	seqList sl;
	initseqList(&sl);
	seqListpushBack(&sl, 1);
	seqListpushBack(&sl, 2);
	seqListpushBack(&sl, 3);
	seqListpushBack(&sl, 4);
	seqListpushBack(&sl, 5);
	seqListPrint(&sl);
	seqListpopBack(&sl);
	seqListPrint(&sl);
	seqListpopBack(&sl);
	seqListPrint(&sl);
	seqListpopBack(&sl);
	seqListPrint(&sl);
	seqListpopBack(&sl);
	seqListPrint(&sl);
	seqListpopBack(&sl);
	seqListPrint(&sl);
}

int main()
{
	test();
}