#pragma once

#define N 100

typedef int SLDataType;

//静态顺序表
struct seqList1
{
	SLDataType data[N];
	int size;
};

//动态链表
typedef struct seqList
{
	SLDataType* data;
	int size;
	int capacity;
}seqList;

void initseqList(seqList* sl);

//操作 增删改查
//尾插：给顺序表最后一个有效数据的末尾插入新的数据
void seqListpushBack(seqList* sl, SLDataType val);

//尾删：删除最后一个数据
void seqListpopBack(seqList* sl);

//查找当前下标的元素
SLDataType seqListAt(seqList* sl, int pop);

//判断表是否为空
int seqListEmpty(seqList* sl);

//打印表
void seqListPrint(seqList* sl);

//查看表的有效个数
int seqListSize(seqList* sl);

//检查容量
void seqListCheckCapacity(seqList* sl);