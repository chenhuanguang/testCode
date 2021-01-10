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

void listInit(struct list* lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL;
}

struct listNode* creatListNode(LDataType val)
{
	struct listNode* node = (struct listNode*)malloc(sizeof(listNode));
	if (node == NULL)
		exit(0);
	node->data = val;
	node->next = NULL;
	return node;
}

void listPushBack(struct list* lst, LDataType val)
{
	if (lst == NULL)
		return;

	if (lst->head == NULL)
	{
		lst->head = creatListNode(val);
		lst->head->next = lst->head;
	}
	else
	{
		struct listNode* tail;
		struct listNode* cur = lst->head->next;
		while (cur->next != lst->head)
		{
			cur = cur->next;
		}
		cur->next = creatListNode(val);
		tail = cur->next;
		tail->next = lst->head;
	}
}

void creatList(struct list* lst, int n)
{

	for (int i = 0; i < n; ++i)
	{
		listPushBack(lst, i);
	}
}

void josephCycle(int n, int m)
{
	list lst;
	listInit(&lst);
	creatList(&lst, n);
	struct listNode* cur = (&lst)->head;
	struct listNode* prev = (&lst)->head;
	struct listNode* tail = NULL;

	while (prev->next != (&lst)->head)
	{
		prev = prev->next;
	}

	while (cur->next != cur)
	{
		for (int i = 1; i < m; ++i)
		{
			prev = cur;
			cur = cur->next;
		}
		tail = cur->next;
		prev->next = tail;
		free(cur);
		cur = tail;
	}

	printf("%d\n", cur->data);
}

int main()
{
	josephCycle(5, 3);
	return 0;
}