#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <mutex>
using namespace std;

//template <class T>
//void swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}


class String
{
public:
	String(const char* str = "")
	{
		assert(str != nullptr);
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);

	}

	String(String&& s)
		:_str(s._str)
	{
		s._str = nullptr;
	}

	String& operator=(String&& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = s._str;
			s._str = nullptr;
		}
		return *this;
	}

	String& operator=(String s)
	{
		if (this != &s)
		{
			swap(_str, s._str);
		}
		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

template <class T>
class Share_ptr
{
public:
	Share_ptr(T* ptr)
		:_ptr(ptr)
		,_cntPtr(new size_t(1))
		,_mtx(new mutex)
	{}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~Share_ptr()
	{
		if (subCnt() == 0)
		{
			if (_ptr != nullptr)
			{
				delete _ptr;
				delete _cntPtr;
				delete _mtx;
				_ptr = nullptr;
				_cntPtr = nullptr;
				_mtx = nullptr;
			}
		}
	}

	Share_ptr(Share_ptr<T>& sp)
		:_ptr(sp._ptr)
		,_cntPtr(sp._cntPtr)
		,_mtx(sp._mtx)
	{
		addCnt();
	}

	Share_ptr<T>& operator=(Share_ptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			if (subCnt() == 0)
			{
				delete _ptr;
				delete _cntPtr;
				delete _mtx;
			}
			_ptr = sp._cntPtr;
			_cntPtr = sp._cntPtr;
			_mtx = sp._mtx;

			addCnt();
		}

		return *this;
	}

	void addCnt()
	{
		_mtx.lock();
		++(*_cntPtr);
		_mtx->unlock();
	}

	size_t subCnt()
	{
		_mtx->lock();
		--(*_cntPtr);
		_mtx->unlock();
		return *_cntPtr;
	}
private:
	T* _ptr;
	size_t* _cntPtr;
	mutex* _mtx;
};

//class Singleton
//{
//public:
//	static Singleton* getSingleton()
//	{
//		return &_singleton;
//	}
//
//private:
//	Singleton() {};
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton _singleton;
//};
//Singleton Singleton::_singleton;

class Singleton
{
public:
	static Singleton* getSingleton()
	{
		if (_singleton == nullptr)
		{
			_mtx.lock();
			if (_singleton == nullptr)
			{
				_singleton = new Singleton();
			}
			_mtx.unlock();
		}
		return _singleton;
	}

private:
	Singleton() {};
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* _singleton;
	static mutex _mtx;
};
Singleton* Singleton::_singleton = nullptr;
mutex Singleton::_mtx;

int main()
{

	int a = 10;
	int b = 20;
	auto fun = [a, b](int c)mutable->int {return a + b + c; };
	int sum = fun(30);
	cout << sum << endl;
	return 0;
}

template <class T>
class Shared_ptr
{
public:
	Shared_ptr(const T& val = T())
		:_ptr(new T())
		,_cnt(new size_t(1))
		,_mtx(new mutex())
	{}

	Shared_ptr(const Shared_ptr<T>& s)
		:_ptr(s._ptr)
		,_cnt(s._cnt)
		,_mtx(s._mtx)
	{
		addcnt();
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	Shared_ptr<T>& operator=(Shared_ptr<T>& s)
	{
		if (_ptr != s._ptr)
		{
			if (subCnt() == 0)
			{
				delete _ptr;
				delete _cnt;
				delete _mtx;
			}
			_ptr = s._ptr;
			_cnt = s._cnt;
			_mtx = s._mtx;

			addCnt();
		}

		return *this;
	}

	~Shared_ptr()
	{
		if (subCnt() == 0)
		{
			delete _ptr;
			delete _cnt;
			delete _mtx;
			_ptr = nullptr;
			_cnt = nullptr;
			_mtx = nullptr;
		}
	}

	void addCnt()
	{
		_mtx->lock();
		(*_cnt)++;
		_mtx->unlock();
	}

	size_t subCnt()
	{
		_mtx->lock();
		(*_cnt)--;
		_mtx->unlock();
		return *_cnt;
	}
private:
	T* _ptr;
	size_t* _cnt;
	mutex* _mtx;
};


//class Singleton1
//{
//public:
//	static Singleton1* getOne()
//	{
//		return &_singleton;
//	}
//private:
//	Singleton1()
//	{}
//	Singleton1(const Singleton1&) = delete;
//	Singleton1& operator=(const Singleton1&) = delete;
//	static Singleton1 _singleton;
//};
//
//Singleton1 Singleton1::_singleton;

class Singleton1
{
public:
	static Singleton1* getOne()
	{
		if (_singleton1 == nullptr)
		{
			_mtx->lock();
			if (_singleton1 == nullptr)
			{
				_singleton1 = new Singleton1();
			}
			_mtx->unlock();
		}

		return _singleton1;
	}
private:
	Singleton1(){}
	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;
	static  Singleton1* _singleton1;
	static mutex* _mtx;
};
Singleton1* Singleton1::_singleton1 = nullptr;
mutex* Singleton1::_mtx;