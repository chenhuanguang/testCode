#include <iostream>
#include <queue>
using namespace std;

template<class T, class Container = deque<T>>
class Stack
{
public:
	Stack()
	{}
	void push(const T& x)
	{
		con.push_back(x);
	}
	void pop()
	{
		con.pop_back();
	}
	T& top()
	{
		return con.back();
	}
	const T& top()const
	{
		return con.back();
	}
	size_t size()const
	{
		return con.size();
	}
	bool empty()const
	{
		return con.empty();
	}
private:
	Container con;
};
template<class T, class Container = deque<T>>
class Queue
{
public:
	Queue()
	{}
	void push(const T& x)
	{
		con.push_back(x);
	}
	void pop()
	{
		con.pop_front();
	}
	T& back()
	{
		return con.back();
	}
	const T& back()const
	{
		return con.back();
	}
	T& front()
	{
		return con.front();
	}
	const T& front()const
	{
		return con.front();
	}
	size_t size()const
	{
		return con.size();
	}
	bool empty()const
	{
		return con.empty();
	}
private:
	Container con;
};

//void test()
//{
//	Queue<int> q;
//	q.push(14);
//	q.push(9);
//	q.push(23);
//	q.push(12);
//	q.push(22);
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}