#include <vector>
#include <iostream>
using namespace std;

template<class K, class V, class KeyOfValue>
class HTable;//声明

template<class V>
struct HashNode
{
	typedef HashNode<V> Node;
	V _val;
	Node* _next;

	HashNode(const V& val)
		:_val(val)
		,_next(nullptr)
	{}
};


template<class K, class V, class KeyOfValue>
struct HashIterator
{
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue> Self;
	typedef HTable<K, V, KeyOfValue> HT;
	Node* _node;
	HT* _hPtr;

	HashIterator(Node* node, HT* hPtr)
		:_node(node)
		,_hPtr(hPtr)
	{}

	V& operator*()
	{
		return _node->_val;
	}

	V* operator->()
	{
		return &_node->_val;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		//下一个结点存在
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else//不存在下一个节点
		{
			//则需要找到下一个非空的链表的头结点
			//计算当前节点在哈希表中的位置
			KeyOfValue kov;
			size_t idx = kov(_node->_val) % _hPtr->_ht.size();
			//从下一个哈希位置开始查找
			++idx;
			for (; idx < _hPtr->_ht.size(); ++idx)
			{
				if (_hPtr->_ht[idx])//找到下一个非空结点
				{
					_node = _hPtr->_ht[idx];
					break;
				}
			}
			//没找到非空链表，则表示走到末尾，则为空
			if (idx == _hPtr->_ht.size())
				_node = nullptr;
		}
		return *this;
	}

};

template<class K, class V, class KeyOfValue>
class HTable
{
public:
	typedef HashIterator<K, V, KeyOfValue> iterator;
	typedef HashNode<V> Node;

	template<class K, class V, class KeyOfValue>
	friend struct HashIterator;

	HTable(int n = 10)
		:_ht(n)
		,_size(0)
	{}

	iterator begin()
	{
		//第一个非空链表的头结点
		for (size_t i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
			{
				return iterator(_ht[i], this);
			}
		}
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	pair<iterator, bool> insert(const V& val)
	{
		//0.检查容量
		checkCapacity();

		//1.计算hash位置
		KeyOfValue kov;
		int idx = kov(val) % _ht.size();

		//2.查找
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}

		//3.插入--头插
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		return make_pair(iterator(cur, this), true);
	}

	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;

			//创建新的指针数组
			vector<Node*> newHt(newC);

			KeyOfValue kov;
			//遍历旧表
			for (size_t i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				//遍历单链表
				while (cur)
				{
					Node* next = cur->_next;
					//计算新的位置
					int idx = kov(cur->_val) % newHt.size();
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
private:
	//指针数组
	vector<Node*> _ht;
	int _size;
};

template<class K, class V>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename HTable<K, pair<K, V>, MapKeyOfValue>::iterator iterator;
	
	pair<iterator, bool> insert(const pair<K, V>& val)
	{
		return _ht.insert(val);
	}
	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
		return ret.first->second;
	}
private:
	HTable<K, pair<K, V>, MapKeyOfValue> _ht;
};

template<class K>
class UnorderedSet
{
	
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename HTable<K, K, SetKeyOfValue>::iterator iterator;
	pair<iterator, bool> insert(const K& key)
	{
		return _ht.insert(key);
	}

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}
private:
	HTable<K, K, SetKeyOfValue> _ht;
};

void test()
{
	UnorderedMap<int, int> m;
	m.insert(make_pair(1, 1));
	m[2] = 2;
	m[3] = 3;
	m[2] = 20;

	UnorderedMap<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << "--------" << endl;
	for (auto& p : m)
	{
		cout << p.first << "--->" << p.second << endl;
	}
}

//void test()
//{
//	UnorderedSet<int> s;
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
//	s.insert(20);
//
//	UnorderedSet<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}