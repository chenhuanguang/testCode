#include <iostream>
#include <string>
using namespace std;

template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_data(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

template<class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	ListIterator(Node* node = nullptr)
		: _node(node)
	{}

	ListIterator(const Self& s)
		: _node(s._node)
	{}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(_node);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
};


template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		return iterator(_header->_next);
	}

	iterator end()
	{
		return iterator(_header);
	}

	const_iterator cbegin() const
	{
		return const_iterator(_header->_next);
	}

	const_iterator cend() const
	{
		return const_iterator(_header);
	}

	List()
		:_header(new Node())
	{
		//循环结构
		_header->_next = _header->_prev = _header;
	}

	List(int n, const T& val = T())
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		for (size_t i = 0; i < n; ++i)
		{
			pushBack(val);
		}
	}

	template<class inputIterator>
	List(inputIterator first, inputIterator last)
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	List(List<T>& l)
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		List<T> tmp(l.begin(), l.end());
		swap(tmp);
	}

	List<T>& operator=(List<T> tmp)
	{
		swap(tmp);
		return *this;
	}

	void swap(List<T>& l)
	{
		Node* tmp = l._header;
		l._header = this->_header;
		this->_header = tmp;
	}

	void pushBack(const T& val)
	{
		/*Node* tail = _header->_prev;
		Node* newNode = new Node(val);

		tail->_next = newNode;
		newNode->_prev = tail;

		newNode->_next = _header;
		_header->_prev = newNode;*/
		insert(end(), val);
	}

	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	void popBack()
	{
		erase(--end());
	}

	void popFront()
	{
		erase(begin());
	}

	T& font()
	{
		return _header->_next->_data;
	}

	const T& font()const 
	{
		return _header->_next->_data;
	}

	T& back()
	{
		return _header->_prev->_data;
	}

	const T& back()const
	{
		return _header->_prev->_data;
	}

	bool empty()const 
	{
		return _header->_next == _header;
	}

	size_t size()const
	{
		int sz = 0;
		Node* cur = _header->_next;
		while (cur != _header)
		{
			++sz;
			cur = cur->_next;
		}
		return sz;
	}

	iterator erase(iterator pos)
	{
		if (pos != end())
		{
			Node* next = pos._node->_next;
			Node* prev = pos._node->_prev;

			prev->_next = next;
			next->_prev = prev;
			delete[] pos._node;
			return iterator(next);
		}
		return pos;
	}

	void insert(iterator pos, const T& val)
	{
		Node* newNode = new Node(val);
		Node* cur = pos._node;
		Node* prev = cur->_prev;

		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = cur;
		cur->_prev = newNode;
	}

	void clear()
	{
		if (_header != nullptr)
		{
			Node* cur = _header->_next;
			while (cur != _header)
			{
				Node* next = cur->_next;
				delete[] cur;
				cur = nullptr;
				cur = next;
			}
		}
	}

	~List()
	{
		clear();
		delete _header;
		_header = nullptr;
	}

private :
	Node* _header;
};

struct A
{
	int _a;
	A(int a = 0)
		:_a(a)
	{}
};

template<class T>
void printfFor(List<T>& lst)
{
	for (auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
}



void test()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	lst.pushBack(5);
	List<int> lst1 = lst; //拷贝构造
	List<int> lst2;
	lst2 = lst1; //=重载
	printfFor(lst);
	printfFor(lst);
	printfFor(lst);
}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//
//	/*List<A>::iterator it = lst.begin();
//
//	while (it != lst.end())
//	{
//		cout << it->_a<< " ";
//		it++;
//	}
//	cout << endl;*/
//	/*lst.insert(lst.begin(), 0);
//	lst.insert(lst.end(), 6);
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it<< " ";
//		it++;
//	}
//	cout << endl;*/
//	size_t res = lst.size();
//	cout << res << endl;
//}

int main()
{
	test();
	return 0;
}