#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template <class V>
struct RBTreeNode
{
	RBTreeNode<V>* _parent; //父节点
	RBTreeNode<V>* _left; //左孩子
	RBTreeNode<V>* _right; //右孩子
	V _val;
	COLOR _color; //颜色

	RBTreeNode(const V& val = V())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _color(RED)
	{}
};

template <class  V>
struct RBTreeIterator
{
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V> Self;
	Node* _node;

	RBTreeIterator(Node* node)
		:_node(node)
	{}

	//解引用
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
		if (_node->_right)
		{
			//右子树的最左结点
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		else
		{
			Node* parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if (_node->_right != parent)
				_node = parent;
		}
		return *this;
	}
	
	Self& operator--()
	{
		if (_node->_left)
		{
			//右子树的最左结点
			_node = _node->_left;
			while (_node->_right)
			{
				_node = _node->_right;
			}
		}
		else
		{
			Node* parent = _node->_parent;
			while (_node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if (_node->_left != parent)
				_node = parent;
		}
		return *this;
	}
};

template <class K, class V, class KeyOfValue>
class RBTree
{
public:
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V> iterator;

	iterator begin()
	{
		return iterator(_header->_left);
	}
	iterator end()
	{
		return iterator(_header);
	}
	iterator rbegin()
	{
		return iterator(_header->_right);
	}

	RBTree()
		:_header(new Node)
	{
		//创建空树
		_header->_left = _header->_right = _header;
	}

	//bool insert(const V& val)
	pair<iterator, bool> insert(const V& val)
	{
		if (_header->_parent == nullptr)
		{
			Node* root = new Node(val);

			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;

			//根节点为黑色
			root->_color = BLACK;
			return make_pair(iterator(root), true);
		}

		Node* cur = _header->_parent;
		Node* parent = nullptr;

		KeyOfValue kov;
		//1.寻找到要插入的结点的位置
		while (cur)
		{
			parent = cur;
			if (kov(cur->_val) == kov(val))
				return make_pair(iterator(cur), false);
			else if (kov(cur->_val) > kov(val))
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		//2.创建节点
		cur = new Node(val);
		Node* node = cur;
		if (kov(parent->_val) > kov(cur->_val))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//3.颜色的修改或者结构的调整
		while (cur != _header->_parent && cur->_parent->_color == RED)//不为根且存在连续红色，则需要调整
		{
			parent = cur->_parent;
			Node* gfather = parent->_parent;

			if (gfather->_left == parent)
			{
				Node* uncle = gfather->_right;
				//情况1.uncle存在且为红
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//向上追溯
					cur = gfather;
				}
				else
				{
					if (parent->_right == cur)//情况3
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//情况2.uncle不存在或者uncle为黑
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				Node* uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//向上追溯
					cur = gfather;
				}
				else
				{
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}

		//根节点为黑色
		_header->_parent->_color = BLACK;
		//更新头结点的左右指向
		_header->_left = leftMost();
		_header->_right = rightMost();
		//return true;
		return make_pair(iterator(node), true);
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _header->_parent)
		{
			_header->_parent = subR;
			subR->_parent = _header;
		}
		else
		{
			Node* gfather = parent->_parent;
			if (gfather->_left == parent)
				gfather->_left = subR;
			else
				gfather->_right = subR;
			subR->_parent = gfather;
		}
		subR->_left = parent;
		parent->_parent = subR;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (parent == _header->_parent)
		{
			_header->_parent = subL;
			subL->_parent = _header;
		}
		else
		{
			Node* gfather = parent->_parent;
			if (gfather->_left == parent)
				gfather->_left = subL;
			else
				gfather->_right = subL;
			subL->_parent = gfather;
		}
		subL->_right = parent;
		parent->_parent = subL;
	}

	Node* leftMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}

	Node* rightMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}
private:
	Node* _header;
};

template<class K, class T>
class Map
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, T>& val)
		{
			return val.first;
		}
	};
public:

	typedef typename RBTree<K, pair<K, T>, MapKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _rbt.begin();
	}
	iterator end()
	{
		return _rbt.end();
	}
	iterator rbegin()
	{
		return _rbt.rbegin();
	}
	pair<iterator, bool> insert(const pair<K, T>& kv)
	{
		return _rbt.insert(kv);
	}

	T& operator[](const K& key)
	{
		pair<iterator, bool> ret = _rbt.insert(make_pair(key, T()));
		return ret.first->second;
	}

private:
	typedef RBTree<K, pair<K, T>, MapKeyOfValue> rbt;
	rbt _rbt;
};

template <class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& val)
		{
			return val;
		}
	};

public:
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;
	pair<iterator, bool> insert(const K& val)
	{
		return _rbt.insert(val);
	}

private:
	typedef RBTree<K, K, SetKeyOfValue> rbt;
	rbt _rbt;
};

void test()
{
	Map<int, int> m;
	m[1] = 1;
	m[2] = 20;
	m[3] = 300;
	m[4] = 4000;
	m[1] = 10;
	m[5] = 10;
	m[9] = 10;

	Map<int, int>::iterator it = m.rbegin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		--it;
	}
}

//void test()
//{
//	Map<int, int> m;
//	m.insert(make_pair(1, 1));
//	m.insert(make_pair(2, 1));
//	m.insert(make_pair(3, 1));
//	m.insert(make_pair(4, 1));
//
//	//Map<int, int>::iterator it = m.begin();
//	Map<int, int>::iterator it = m.rbegin();
//	while (it != m.end())
//	{
//		//it-> 获得结点的val的地址 => pair指针
//		//pair->first获得pair对象的第一个值
//		//pair->second获得pair对象的第二个值
//		cout << it->first << " " << it->second << endl;
//		--it;
//	}
//}

int main()
{
	test();
	return 0;
}