#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

//class String
//{
//public:
//
//	String(const char* str = "")
//	{
//		//str不能为空
//		assert(str != nullptr);
//		//开辟一个与传入的字符串的长度 + 1的空间 +1是保存 \0
//		_str = new char[strlen(str) + 1];
//		//将传入的字符串内容拷贝到当前类的内容中
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str != nullptr)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//	const char* c_str() const 
//	{
//		return _str;
//	}
//private:
//	char* _str;
//};

//class String
//{
//public:
//
//	String(const char* str = "")
//	{
//		//str不能为空
//		assert(str != nullptr);
//		//开辟一个与传入的字符串的长度 + 1的空间 +1是保存 \0
//		_str = new char[strlen(str) + 1];
//		//将传入的字符串内容拷贝到当前类的内容中
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//
//	String& operator=(String s)
//	{
//		if (this != &s)
//		{
//			swap(_str, s._str);
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str != nullptr)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//	const char* c_str() const
//	{
//		return _str;
//	}
//private:
//	char* _str;
//};

class String
{
public:
	//迭代器
	typedef char* iterator;
	//const迭代去
	typedef const char* const_iterator;

	iterator begin()
	{
		//第一个元素的位置
		return _str;
	}

	iterator end()
	{
		//最后一个元素的下一个位置
		return _str + _size;
	}

	const_iterator begin() const
	{
		//第一个元素的位置
		return _str;
	}

	const_iterator end() const 
	{
		//最后一个元素的下一个位置
		return _str + _size;
	}

	String(const char* str = "")
	{
		assert(str != nullptr);
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}

	//自己实现一个交换函数，交换两个对象的所有内容
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	String& operator=(String s)
	{
		if (this != &s)
		{
			Swap(s);
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

	const char* c_str() const
	{
		return _str;
	}

	size_t size() const
	{
		return _size;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const 
	{
		assert(pos < _size);
		return _str[pos];
	}



	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//申请空间 
			char* tmp = new char[n + 1];
			//拷贝原来的数据
			strcpy(tmp, _str);
			//释放原有空间
			delete[] _str;
			//将拷贝的内容重新赋值给_str
			_str = tmp;
			//更新容量大小
			_capacity = n;
		}
	}

	void push_back(const char& ch)
	{
		//检查空间
		if (_size == _capacity)
		{
			size_t newCapcity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapcity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void resize(size_t n, const char& ch = '\0')
	{
		//3、n > capacity 增容
		if (n > _capacity)
		{
			reserve(n);
		}
		//2、_size < n <= capacity  填充ch
		if (n > _size)
		memset(_str + _size, ch, (n - _size) * sizeof(char));

		//1、n < size
		_size = n;
		_str[_size] = '\0';
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void test()
{
	String str = ("White");
	str.resize(3); //Whi
	str.resize(5, 'a'); //Whiaa
	str.resize(10, 'b'); //Whiaabbbbb
}

int main()
{
	test();

	return 0;
}