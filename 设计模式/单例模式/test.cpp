#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//懒汉式
class Singleton
{
public:
	static Singleton* getSingleton()
	{
		if (_singleton == nullptr)
		{
			_mutex.lock();
			if (_singleton == nullptr)
			{
				_singleton = new Singleton();
			}
			_mutex.unlock();
		}
		return _singleton;
	}

private:
	Singleton() {};
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static mutex _mutex;//互斥锁
	static Singleton* _singleton;
};
Singleton* Singleton::_singleton = nullptr;
mutex Singleton::_mutex;

//饿汉式
//class Singleton
//{
//public:
//	//获取唯一实例的静态方法
//	static Singleton* getSingleton()
//	{
//		return &_singleton;
//	}
//
//private:
//	//私有构造
//	Singleton() {};
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	
//	static Singleton _singleton;
//};
//
////在程序入口之前就完成单例对象的初始化
//Singleton Singleton::_singleton; 

int main()
{
	return 0;
}