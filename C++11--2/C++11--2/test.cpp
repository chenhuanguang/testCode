#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <memory>
using namespace std;

//实现auto_ptr
template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr)
		:_ptr(ptr)
	{}
	~Auto_ptr()
	{
		if (_ptr)
			delete _ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}

	Auto_ptr(Auto_ptr<T>& ap)
		:_ptr(ap._ptr)
	{
		//资源管理权转移 
		ap._ptr = nullptr;
	}

	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			//资源管理权转移 
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}
private:
	T* _ptr;
};

void test()
{
	Auto_ptr<int> ap(new int);
}

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

//void test()
//{
//	//通常异常模板
//	try
//	{
//		vector<int> v;
//		//v.at(3) = 10;
//		v.reserve(1000000000000);
//	}
//	catch (exception& e)//引用形成多态
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "..." << endl;
//	}
//}

int main()
{
	test();
	return 0;
}

//void fun1()
//{
//	//抛异常
//	throw "string error";
//	cout << "fun1()" << endl;
//}
//
//void fun2()
//{
//	int* arr = new int[100];
//	try
//	{
//		fun1();
//	}
//	catch (int i)
//	{ }
//	catch (double d)
//	{ }
//	catch (...)
//	{
//		delete[] arr;
//		cout << "delete[]" << endl;
//		//重新抛出异常
//		throw;
//	}
//	cout << "fun2()" << endl;
//}
//
//void fun3()
//{
//	fun2();
//	cout << "fun3()" << endl;
//}
//
//int main()
//{
//	try
//	{
//		fun3();
//	}
//	catch (int i)
//	{ }
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	catch (...)
//	{
//		cout << "..." << endl;
//	}
//
//	cout << "main()" << endl;
//
//	return 0;
//}



//template<class Mtx>
//class LockGuard //也是利用RAII思想
//{
//public:
//	LockGuard(Mtx& mtx)
//		:_mtx(mtx)
//	{
//		_mtx.lock();//构造并加锁
//	}
//	~LockGuard()
//	{
//		_mtx.unlock();//释放解锁
//	}
//
//	LockGuard(const LockGuard<Mtx>& lg) = delete;
//	LockGuard& operator=(const LockGuard<Mtx>& lg) = delete;
//private:
//	Mtx& _mtx;
//};
//
//mutex mtx;
//void fun1()
//{
//	//mtx.lock();
//	LockGuard<mutex> lg(mtx);
//	cout << "fun1()" << endl;
//	int n;
//	cin >> n;
//	if (n == 0)
//		return;
//	//mtx.unlock();
//}
//
//void fun2()
//{
//	//mtx.lock();//阻塞
//	LockGuard<mutex> lg(mtx);
//	cout << "fun2()" << endl;
//	//mtx.unlock();
//}
//void test()
//{
//	thread t1(fun1);
//	thread t2(fun2);
//	t1.join();
//	t2.join();
//}

//mutex mtx;
////int sum = 0;
//atomic<int> sum(0);//原子变量
//void fun(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		//加解锁会引用效率
//		//mt.lock();
//		//一行代码可能有多条指令
//		//指令之间的执行不是原子操作
//		//mtx.try_lock();//非阻塞加锁
//		sum++;
//		//mt.unlock();
//	}
//}
//
//void test()
//{
//	int n;
//	cin >> n;
//	thread t1(fun, n);
//	thread t2(fun, n);
//	t1.join();
//	t2.join();
//	cout << sum << endl;
//}

//class threadManager
//{
//public:
//	explicit threadManager(thread& t)
//		:_t(t)
//	{}
//
//	~threadManager()
//	{
//		if (_t.joinable())//当前线程有效
//		{
//			_t.join();
//		}
//	}
//
//	threadManager(const threadManager &) = delete;
//	threadManager& operator=(const threadManager const&) = delete;
//private:
//	thread& _t;
//};
//
//void test()
//{
//	thread t1([] {});
//	//将线程由一个类来管理
//	threadManager tm(t1);//该变量时局部变量，声明周期结束会自动调用析构函数释放线程
//	//vector<int> v;
//	//v.at(3) = 10;//越界异常导致程序提前结束
//	return;
//}

//class A
//{
//public:
//	void fun1(int a, int b)
//	{
//		cout << "fun1(int, int)" << a << b << endl;
//	}
//};
//
//void fun(int& a)
//{
//	a *= 2;
//}
//
//void fun2(int* a) 
//{
//	*a += 2;
//}
//
//void test()
//{
//	A a;
//	//调用类中的成员函数，需要作用域之前取地址
//	thread t1(&A::fun1, &a, 1, 2);
//	t1.join();
//	int a1 = 1;
//	//fun参数虽然是引用，但是其底层是引用了线程栈的变量，对外部并不影响
//	thread t2(fun, a1);
//	t2.join();
//	cout << a1 << endl;
//
//	thread t3(fun2, &a1);
//	t3.join();
//	cout << a1 << endl;
//
//	//参数想为引用，需要使用ref(参数)来转换
//	thread t4(fun2, ref(a1));
//	t4.detach();//进行线程分离
//	cout << a1 << endl;
//}

//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//
//struct Fun
//{
//	void operator()()
//	{
//		cout << "operator())" << endl;
//	}
//};
//
//void test()
//{
//	//函数指针
//	thread t(fun, 10);
//	//判断线程是否结束
//	t.joinable();
//	t.join();//线程等待
//
//	//仿函数对象
//	Fun f;
//	thread t2(f);
//
//	//lambda
//	thread t3([] {cout << "lambda" << endl; });
//	cout << "test()" << endl;
//}

//struct Sum
//{
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//void test()
//{
//	auto f = [](int a, int b) {return a + b; };
//	int sum = f(10, 20);
//	Sum s;
//	s(10, 20);
//}

//void test()
//{
//	int t = 20;
//	auto f = [t](int a) {return a + t; };
//	auto f1 = [t](int a) {return a + t; };
//	f = f1;//error
//	auto f2(f);//ok
//}

