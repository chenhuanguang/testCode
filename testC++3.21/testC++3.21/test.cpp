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

	void append(const char* str)
	{
		//检查容量
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		//尾插
		memcpy(_str + _size, str, sizeof(char) * len);

		//更新
		_size += len;
		_str[_size] = '\0';
	}

	String& operator+=(const String& str)
	{
		append(str._str);
		return *this;
	}
	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	String& operator+=(const char ch)
	{
		push_back(ch);
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//检查位置有效性
		assert(pos <= _size);
		//检查容量
		if (_size == _capacity)
		{
			size_t  newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapacity);
		}

		//移动元素，从后往前移
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		//插入新元素并更新有效字符个数
		_str[pos] = ch;
		++_size;
	}

	void insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		if (_size + len >= _capacity)
		{
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		memcpy(_str + pos, str, sizeof(char) * len);
		_size += len;
	}

	void erase(size_t pos, size_t len)
	{
		//检查位置有效性
		assert(pos < _size);
		//要删除的个数大于剩下的字符个数
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			//移动元素，从前向后移动
			size_t start = pos + len;
			while (start <= _size)
			{
				_str[pos++] = _str[start];
				++start;
			}
			_size -= len;
		}
	}

	size_t find(const char& ch, size_t pos = 0)
	{
		//检查位置的有效性
		assert(pos < _size);
		
		for (size_t i = pos; i < _size; ++i)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		//返回值：
		//NULL：未找到
		//有效地址：子串出现的首地址
		char* ptr = strstr(_str, str);
		if (ptr != NULL)
		{
			return ptr - _str;
		}
		return npos;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};

const size_t String::npos = -1;

String operator+(const String& str1, const String& str2)
{
	String tmp = str1;
	tmp += str2;
	return tmp;
}
String operator+(const String& str1, const char* str2)
{
	String tmp = str1;
	tmp += str2;
	return tmp;
}
String operator+(const char& ch, const String& str1)
{
	String tmp = str1;
	tmp += ch;
	return tmp;
}

ostream& operator<<(ostream& out, const String& str)
{
	for (const auto& ch : str)
	{
		cout << ch;
	}
	return out;
}

istream& operator>>(istream& in, String& str)
{
	char ch;
	while (ch = getchar())
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
		{
			break;
		}
		str += ch;
	}

	return in;
}

bool operator==(const String& str1, const String& str2)
{
	int res =  strcmp(str1.c_str(), str2.c_str());
	if (res == 0)
		return true;
	else
		return false;
}

bool operator==(const String& str1, const char*& str)
{
	int res = strcmp(str1.c_str(),str);
	if (res == 0)
		return true;
	else
		return false;
}

bool operator!=(const String& str1, const String& str2)
{
	return !(str1 == str2);
}

bool operator!=(const String& str1, const char*& str)
{
	return !(str1 == str);
}

void test()
{
	String str1 = "White";
	String str2 = "white";
	cout << (str1 != str2) << endl;
	cout << (str1 == "White") << endl;
}

int main()
{
	test();

	return 0;
}