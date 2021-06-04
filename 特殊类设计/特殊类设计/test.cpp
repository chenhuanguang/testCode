#include <iostream>
#include <vector>
using namespace std;

//class HeapObj
//{
//public:
//	static HeapObj* createObj()
//	{
//		return new HeapObj();
//	}
//private:
//	HeapObj()
//	{}
//	HeapObj(const HeapObj& obj) = delete;
//	HeapObj operator=(const HeapObj& obj) = delete;
//};

//class StackObj
//{
//public:
//	static StackObj createObj()
//	{
//		return StackObj();
//	}
//private:
//	StackObj()
//	{}
//};

//class CopyBan
//{
//private:
//	CopyBan(const CopyBan& cb) = delete;
//	CopyBan& operator=(const CopyBan& cb) = delete;
//};

class A final
{
	//...
};

class B : public A
{

};

int main()
{
	//StackObj sObj = StackObj::createObj();
}