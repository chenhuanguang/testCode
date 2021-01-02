#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef int HDataType;

typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//初始化堆
void HeapInit(heap* hp);

//检查容量
void CheckCapacity(heap* hp);

//小堆向下调整
void SShiftDown(HDataType* arr, int n, int curPos);

//大堆向下调整
void BShiftDown(HDataType* arr, int n, int curPos);

//交换两个数
void Swap(int* a, int* b);

//小堆向上调整
void SShiftUp(int* arr, int n, int cur);

//大堆向上调整
void BShiftUp(int* arr, int n, int cur);

//小堆插入
void SHeapPush(heap* hp, HDataType val);

//大堆插入
void BHeapPush(heap* hp, HDataType val);

//小堆删除
void SHeapPop(heap* hp);

//大堆 删除
void BHeapPop(heap* hp);

//判空
int HeapEmpty(heap* hp);

//获取堆顶元素
HDataType HeapTop(heap* hp);

//小堆排序
void SHeapSort(heap* hp);

//大堆排序
void BHeapSort(heap* hp);

//摧毁堆
void HeapDestory(heap* hp);