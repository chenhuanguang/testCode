#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;

typedef struct listNode
{
	LDataType data;
	struct listNode* next;
}listNode;

typedef struct list
{
	struct listNode* head;
}list;

//创建节点
struct listNode* creatListNode(LDataType val);

//初始化链表
void listInit(struct list* lst);

//尾插
void listPushBack(struct list* lst, LDataType val);

//尾删
void listPopBack(struct list* lst);

//前插
void listPushFront(struct list* lst, LDataType val);

//前删
void listPopFront(struct list* lst);

//在当前节点的写一个插入
void listInsertAfter(struct listNode* node, LDataType val);

//删除当前节点的下一个
void listEraseAfter(struct listNode* node);

//查找节点
listNode* listFind(struct list* lst, LDataType val);

//摧毁链表
void listDestroy(struct list* lst);

//删除当前节点
void listErase(struct listNode* node);