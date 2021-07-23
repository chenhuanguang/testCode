#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct AVLNode
{
	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	T _val;
	int _bf;//平衡因子

	AVLNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _bf(0)//初始化为0，叶子无左右孩子
	{}
};

//AVL树
template<class T>
class AVLTreeNode
{
public:
	typedef AVLNode<T> Node;

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		while (parent)
		{
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;

			if (parent->_bf == 0)
				break;
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
					RotateR(parent);
				else if (parent->_bf == 2 && cur->_bf == 1)
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					Node* subLR = cur->_right;
					int bf = subLR->_bf;
					RotateL(cur);
					RotateR(parent);

					if (bf == 1)
					{
						parent->_bf = 0;
						cur->_bf = -1;
					}
					if (bf == -1)
					{
						parent->_bf = 1;
						cur->_bf = 0;
					}
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					Node* subRL = cur->_left;
					int bf = subRL->_bf;
					RotateR(cur);
					RotateL(parent);

					if (bf == 1)
					{
						parent->_bf = -1;
						cur->_bf = 0;
					}
					if (bf == -1)
					{
						parent->_bf = 0;
						cur->_bf = 1;
					}
				}
			}
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		subL->_right = parent;
		parent->_parent = subL;

		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_left = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _root)
		{
			subR = _root;
			subR->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left = parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}

		subR->_left = parent;
		parent->_parent = subR;

		subR->_bf = parent->_bf = 0;
	}


private:
	Node* _root;
};


template <class T>
struct AVLNode
{
	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	int _bf;
	T val;
	AVLNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _bf(0)
		, _val(val)
	{}
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	AVLTree()
		:_root(nullptr)
	{}
private:
	Node* _root;
};

enum COLOR
{
	BLACK,
	RED
};

template <class T>
class RBNode
{
	RBNode<T>* _parent;
	RBNode<T>* _left;
	RBNode<T>* _right;
	T _val;
	COLOR _color;

	RBNode(const T& val = T())
		:_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_val(val)
		,_color(RED)
	{}
};

template <class T>
class RBTree
{
public:
	typedef RBNode<T> Node;

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			_root->_color = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		while (cur != _root && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node* gfather = parent->_parent;

			if (gfather->_left == parent)
			{
				Node* uncle = gfather->_right;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (parent->_right == cur)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					RotateR(gfather);
					gfather->_color = RED;
					parent->_color = BLACK;
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
					cur = gfather;
				}
				else
				{
					if (parent->_left == cur)
					{
						RotateL(parent);
						swap(parent, cur);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}


		_root->_color = BLACK;
		return true;

	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		subL->_left = parent;
		parent->_parent = subL;

		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_left = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _root)
		{
			subR = _root;
			subR->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left = parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}

		subR->_left = parent;
		parent->_parent = subR;

		subR->_bf = parent->_bf = 0;
	}
	RBTree()
		:_root(nullptr)
	{}
private:
	Node* _root;
};

class BitMap
{
public:
	BitMap(const int range)
		:arr(range/32 + 1)
	{
	}

	void insert(const int val)
	{
		int idx = val / 32;
		int bitIdx = val % 32;
		arr[idx] |= (1 << bitIdx);
	}

	bool find(const int val)
	{
		int idx = val / 32;
		int bitIdx = val % 32;

		return (arr[idx] >> bitIdx) & 1;
	}

	void erase(const int val)
	{
		int idx = val / 32;
		int bitIdx = val % 32;

		arr[idx] &= ~(1 << bitIdx);
	}

private:
	vector<int> arr;
};

int main()
{

	return 0;
}