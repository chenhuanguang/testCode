#include <vector>
#include <iostream>
using namespace std;

template<class K>
struct HashNode
{
	typedef HashNode<K> Node;
	K _val;
	Node* _next;

	HashNode(const K& val)
		:_val(val)
		, _next(nullptr)
	{}
};

template<class K>
class HTable
{
public:
	typedef HashNode<K> Node;

	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	bool insert(const K& val)
	{
		//0.检查容量
		checkCapacity();

		//1.计算hash位置
		int idx = val % _ht.size();

		//2.查找
		Node* cur = _ht[idx];
		while (cur)
		{
			if (cur->_val == val)
				return false;
			cur = cur->_next;
		}

		//3.插入--头插
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		return true;
	}

	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;

			//创建新的指针数组
			vector<Node*> newHt(newC);

			//遍历旧表
			for (size_t i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				//遍历单链表
				while (cur)
				{
					Node* next = cur->_next;
					//计算新的位置
					int idx = cur->_val % newHt.size();
					//头插
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					cur = next;
				}
				//旧表指针置空
				_ht[i] = nullptr;
			}

			//交换新表和旧表
			swap(_ht, newHt);
		}
	}

	Node* find(const K& val)
	{
		int idx = val % _ht.size();
		Node* cur = _ht[idx];
		while (cur)
		{
			if (cur->_val == val)
				return cur;
			cur = cur->_next;
		}
		return nullptr;
	}

	bool erase(const K& val)
	{
		Node* node = find(val);
		if (node)
		{
			int idx = val % _ht.size();
			Node* cur = _ht[idx];
			Node* prev = nullptr;
			while (cur != node)
			{
				prev = cur;
				cur = cur->_next;
			}
			Node* next = cur->_next;
			if (prev)
				prev->_next = next;
			else
				_ht[idx] = next;
			--_size;
			delete node;
			return true;
		}
		return false;
	}
private:
	//指针数组
	vector<Node*> _ht;
	int _size;
};

//template<class K>
//class Set
//{
//	struct SetKeyOfValue
//	{
//		const K& operator()(const K& key)
//		{
//			return key;
//		}
//	};
//public:
//	bool insert(const K& key)
//	{
//		_ht.insert(key);
//		return true;
//	}
//private:
//	HTable<K, K, SetKeyOfValue> _ht;
//};

//void test()
//{
//	HTable<int> h;
//	h.insert(1);
//	h.insert(2);
//	h.insert(3);
//	h.insert(4);
//	h.insert(5);
//	h.insert(16);
//	h.insert(13);
//	h.insert(18);
//	h.insert(15);
//	h.insert(21);
//	h.insert(20);
//	cout << h.erase(21) << endl;
//	cout << h.erase(100) << endl;
//
//
//	/*Set<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(16);
//	s.insert(13);
//	s.insert(18);
//	s.insert(15);
//	s.insert(21);
//	s.insert(20);*/
//}
//
//int main()
//{
//	test();
//	return 0;
//}