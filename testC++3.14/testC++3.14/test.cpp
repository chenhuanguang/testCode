#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void test()
{
	A* pa = (A*)malloc(sizeof(A));
	//对已有空间进行初始化
	new(pa) A(10);
	//显示调用析构
	pa->~A();
	free(pa);
}

//class ListNode
//{
//public:
//	void* operator new(size_t n)
//	{
//		//采用内存池的方式
//		cout << "operator new" << endl;
//		allocator<ListNode> alloc; //空间配置器
//		return alloc.allocate(1);
//	}
//
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete" << endl;
//		allocator<ListNode> alloc;//空间配置器
//		alloc.deallocate((ListNode*)ptr, 1);
//	}
//private:
//	int _data = 0;
//	ListNode* _next = nullptr;
//};
//void test()
//{
//	ListNode* node = new ListNode;
//	delete node;
//}

//void test()
//{
//	int* ptr = (int*)operator new(sizeof(int) * 2);
//	operator delete(ptr);
//
//	//申请失败抛异常
//	int* ptr1 = (int*)operator new(0x7fffffff);
//	operator delete(ptr1);
//}

//class A
//{
//public:
//	A(int a, int b, int c)
//		:_a(a)
//		,_b(b)
//		,_c(c)
//	{}
//
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//
//void test()
//{
//	A* pa1 = new A(10, 20, 30);
//	delete pa1;
//
//	A* arr = new A[10];
//	delete[] arr;
//}

//void test()
//{
//	//申请空间
//	int* ptr = new int;
//	//申请空间并初始化
//	int* ptr2 = new int(1);
//	//申请连续的空间，空间大小为4*10=40
//	int* arr = new int[10];
//
//	//释放单个空间
//	delete ptr;
//	delete ptr2;
//
//	//释放连续的多个空间
//	delete[] arr;
//}

int main()
{
	test();
	return 0;
}