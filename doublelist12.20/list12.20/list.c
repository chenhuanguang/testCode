#include"list.h"

// 创建返回链表的头结点. 
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if(head)
		head->next = head->prev = head;
	return head;
}

//创建一个带有数据的结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode)
	{
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	return newNode;
}

// 双向链表销毁 
void ListDestory(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
// 双向链表打印 
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 双向链表尾插 
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
		
	ListNode* tail = phead->prev;

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}
// 双向链表尾删
void ListPopBack(ListNode* phead)
{
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	
	free(tail);
	prev->next = phead;
	phead->prev = prev;
}
// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* first = phead->next;

	phead->next = newNode;
	newNode->next = first;
	newNode->prev = phead;
	first->prev = newNode;
}
// 双向链表头删 
void ListPopFront(ListNode* phead)
{
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;

	free(first);
	phead->next = second;
	second->prev = phead;
}
// 双向链表查找 
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->prev;
	ListNode* newNode = BuyListNode(x);

	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}
// 双向链表删除pos位置的节点 
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	next->prev = prev;
	prev->next = next;
}

void TestList()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPrint(list);
	ListNode* node =  ListFind(list, 4);
	ListInsert(node,34);
	ListPrint(list);
	ListErase(node);
	ListPrint(list);
}

int main()
{
	TestList();
	return 0;
}