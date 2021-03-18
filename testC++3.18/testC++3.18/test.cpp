#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class String
{
public:
	String(const char* str = "")
		:_data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
	}
	const char* c_str() const
	{
		return _data;
	}

	String(const String& str)
		:_data(new char[strlen(str._data) + 1])
	{
		strcpy(_data, str._data);
	}
	
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			delete[] _data;
			_data = new char[strlen(str._data) + 1];
			strcpy(_data, str._data);
		}
		return *this;
	}

	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
		}
	}

private:
	char* _data;
};

//class String
//{
//public:
//	String(const char* str = "")
//		:_data(new char[strlen(str) +1])
//	{
//		strcpy(_data, str);
//	}
//	const char* c_str() const
//	{
//		return _data;
//	}
//
//	String(const String& str)
//		:_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(tmp._data, _data);
//	}
//
////	String& operator=(const String& str)
////	{
////		String tmp(str._data);
////		swap(tmp._data, _data);
////		return *this;
////	}
//
//	String& operator=(String str)
//	{
//		swap(str._data, _data);
//		return *this;
//	}
//
//	~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}
//
//private:
//	char* _data;
//};

void test()
{
	String str("white");
	String str2 = str;
	String str3 = "ShirtI";
	str2  = str3;
}

int main()
{
	test();

	return 0;
}