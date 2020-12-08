#include"list.h"

struct listNode* creatListNode(LDataType val)
{
	struct listNode* node = (struct listNode*)malloc(sizeof(listNode));
	node->data = val;
	node->next = NULL;
	return node;
}

void listInit(struct list* lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL; 
}

void listPushBack(struct list* lst, LDataType val)
{
	if (lst == NULL)
		return;

	if (lst->head == NULL)
	{
		lst->head = creatListNode(val);
	}
	else
	{
		struct listNode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = creatListNode(val);
	}
}

void listPopBack(struct list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* prev = lst->head;
	struct listNode* cur = lst->head->next;
	while (cur->next!= NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	if (prev == NULL)
	{
		prev = NULL;
	}
	else
	{
		prev->next = NULL;
	}
	
}

void listPushFront(struct list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct listNode* node = creatListNode(val);
	node->next = lst->head;
	lst->head = node;
}

void listPopFront(struct list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* temp = lst->head->next;
	free(lst->head);
	lst->head = temp;
}

void listInsertAfter(struct listNode* node, LDataType val)
{
	if (node == NULL)
		return;
	struct listNode* newNode = creatListNode(val);
	struct listNode* next = node->next;
	node->next = newNode;
	newNode->next = next;
}

void listEraseAfter(struct listNode* node)
{
	if (node == NULL || node->next ==NULL)
		return;
	struct listNode* next = node->next;
	struct listNode* nextnext = node->next->next;
	free(next);
	node->next = nextnext;
}

listNode* listFind(struct list* lst, LDataType val)
{
	if (lst == NULL)
		return NULL;
	struct listNode* tail = lst->head;
	while (tail != NULL)
	{
		if (tail->data == val)
			return tail;
		tail = tail->next;
	}
	return NULL;
}

void listDestroy(struct list* lst)
{
	if (lst == NULL)
		return;
	
	struct listNode* prev = lst->head;
	while (prev != NULL)
	{
		struct listNode* tail = prev->next;
		free(prev);
		prev = tail;
	}
}

void listErase(struct listNode* node , struct list* lst)
{
	if (lst->head == node)
	{
		free(lst->head);
	}
	else
	{
		struct listNode* prev = lst->head;
		struct listNode* cur = prev->next;
		struct listNode* next = node->next;
		while (cur != node)
		{
			prev = prev->next;
			cur = prev->next;
		}
		free(cur);
		prev->next = next;
	}
	
}

void test()
{
	struct list lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	struct listNode* node = listFind(&lst, 2);
	listInsertAfter(node, 30);
	listEraseAfter(node);
	listDestroy(&lst);
}

int main()
{
	test();
	return 0;
}