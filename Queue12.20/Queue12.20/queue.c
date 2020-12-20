#include"queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->_data = data;
	newNode->_next = NULL;

	if (q->_back == NULL)
	{
		q->_front = q->_back = newNode;
	}
	else
	{
		q->_back->_next = newNode;
		q->_back = newNode;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QueueNode* second = q->_front->_next;
		free(q->_front);
		q->_front = second;
	}
	
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	int count = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		++count;
		cur = cur->_next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_back = q->_front = NULL;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}

int main()
{

	TestQueue();
	return 0;
}