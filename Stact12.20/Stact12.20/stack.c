#include"stack.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

//检查容量
void CheckCapacity(Stack* ps)
{
	if (ps->_top == ps->_capacity)
	{
		size_t newCapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newCapacity * sizeof(STDataType));
		if (!ps->_a)
			return;
			ps->_capacity = newCapacity;
	}
}

// 入栈
void StackPush(Stack* ps, STDataType data)
{
	CheckCapacity(ps);
	ps->_a[ps->_top++] = data;

}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}

int main()
{
	TestStack();

	return 0;
}
