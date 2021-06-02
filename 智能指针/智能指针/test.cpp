#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
using namespace std;

template<class T>
struct DeleteDel
{
	void operator()(T* ptr)
	{
		delete ptr;
	}
};

template<class T>
struct FreeDel
{
	void operator()(T* ptr)
	{
		free(ptr);
	}
};

template<class T>
struct DeleteArrDel
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

template<class T, class Del = DeleteDel<T>>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr)
		:_ptr(ptr)
		, _countPtr(new size_t(1))//初始化为1
		, _mtx(new mutex)
	{}
	Shared_ptr(T* ptr = nullptr, Del del = DeleteDel<T>)
		:_ptr(ptr)
		, _countPtr(new size_t(1))//初始化为1
		, _mtx(new mutex)
		, _del(del)
	{}
	Shared_ptr(const Shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _countPtr(sp._countPtr)
		,_mtx(sp._mtx)
	{
		//计数器累加
		//++(*_countPtr);
		addCount();
	}
	Shared_ptr<T> operator=(const Shared_ptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			//本身计数器自减
			//计数器为0，则当前对象需要释放资源
			//if (--(*_countPtr) == 0)
			if (subCount() == 0)
			{
				//delete _ptr;
				//通过删除器来释放空间
				_del(_ptr);
				delete _countPtr;
				delete _mtx;
			}

			_ptr = sp._ptr;
			_countPtr = sp._countPtr;

			addCount();
		}
		return *this;
	}

	~Shared_ptr()
	{
		//计数器自减
		if (subCount() == 0)
		{
			//delete _ptr;
			//通过删除器来释放空间
			_del(_ptr);
			delete _countPtr;
			delete _mtx;
			_ptr = nullptr;
			_countPtr = nullptr;
			_mtx = nullptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

	size_t getCount()
	{
		return *_countPtr;
	}

	size_t addCount()
	{
		_mtx->lock();
		++(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}

	size_t subCount()
	{
		_mtx->lock();
		--(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}
private:
	T* _ptr;
	size_t* _countPtr;//计数器指针
	mutex* _mtx;
	Del _del;
};

class A
{
public:
	int _a = 10;
	~A()
	{
		cout << "~A()" << endl;
	}
};

void test()
{
	//Shared_ptr<A> sp(new A[100], DeleteArrDel<A>());//调用析构会报错
}

//struct ListNode
//{
//	shared_ptr<ListNode> _next;
//	shared_ptr<ListNode> _prev;
//	int _data;
//
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//
//void test()
//{
//	shared_ptr<ListNode> n1(new ListNode);
//	shared_ptr<ListNode> n2(new ListNode);
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//}

//void fun(const Shared_ptr<A>& sp, int n)
//{
//	for (int i = 0; i < n; ++i)
//		Shared_ptr<A> copy(sp);
//}
//
//void test()
//{
//	Shared_ptr<A> sp(new A);
//	int n = 100000;
//	thread t1(fun, ref(sp), n);
//	thread t2(fun, ref(sp), n);
//	t1.join();
//	t2.join();
//	cout << sp.getCount() << endl;
//}

//void test()
//{
//	Share_ptr<A> sp(new A);
//	Share_ptr<A> sp2(new A);
//	Share_ptr<A> copy(sp);
//	sp2 = sp;
//}

//void test()
//{
//	shared_ptr<A> sp(new A);
//	cout << sp.use_count() << endl;//1
//	shared_ptr<A> sp2(sp);
//	cout << sp.use_count() << endl;//2
//	cout << sp2.use_count() << endl;//2
//	shared_ptr<A> sp3(new A);
//	cout << sp.use_count() << endl;//2
//	cout << sp2.use_count() << endl;//2
//	cout << sp3.use_count() << endl;//1
//	sp3 = sp;
//	sp3 = sp2;
//	cout << sp.use_count() << endl;//2
//	cout << sp2.use_count() << endl;//2
//	cout << sp3.use_count() << endl;//2
//}

int main()
{
	test();
	return 0;
}
//template<class T>
//class Unique_ptr
//{
//public:
//	Unique_ptr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	Unique_ptr(const Unique_ptr<T>& up) = delete;
//	Unique_ptr<T>& operator=(const Unique_ptr<T>& up) = delete;
//
//	~Unique_ptr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//private:
//	T* _ptr;
//};
//
//void test()
//{
//	unique_ptr<int> up(new int(10));
//	unique_ptr<int> up2(up);//error
//}

//实现auto_ptr
//template<class T>
//class Auto_ptr
//{
//public:
//	Auto_ptr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~Auto_ptr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	Auto_ptr(Auto_ptr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		//资源管理权转移 
//		ap._ptr = nullptr;
//	}
//
//	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
//	{
//		if (this != &ap)
//		{
//			if (_ptr)
//				delete _ptr;
//			//资源管理权转移 
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//		return *this;
//	}
//private:
//	T* _ptr;
//};
//
//void test()
//{
//	Auto_ptr<int> ap(new int);
//}

//void test()
//{
//	auto_ptr<int> ap(new int);
//	auto_ptr<int> ap2(new int(2));
//	*ap = 10;
//	*ap2 = 20;
//	auto_ptr<int> ap3 = ap;
//	*ap = 10;//空引用报错
//}

//RAII
//template<class T>
//class SmartPtr
//{
//public:
//	//构造函数获取资源管理权
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	//通过析构函数释放资源
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//private:
//	T* _ptr;
//};
//
//class A
//{
//public:
//	int _a = 10;
//};
//
//void test()
//{
//	//智能指针--编译器调用析构自动释放资源--不存在内存泄漏
//	SmartPtr<A> sp(new A);
//	(*sp)._a = 10;
//	sp->_a = 100;
//
//	//普通指针--手动释放内存
//	int* p = new int;
//	A* pa = new A;
//	*p = 1;
//	pa->_a = 10;
//	//return  //提前结束普通指针就会导致内存泄漏
//	delete p;
//	delete pa;
//}
