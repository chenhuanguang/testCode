#include <iostream>
#include <utility>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template <class T>
struct RBTreeNode
{
	RBTreeNode<T>* _parent; //父节点
	RBTreeNode<T>* _left; //左孩子
	RBTreeNode<T>* _right; //右孩子
	T _val; //键值对
	COLOR _color; //颜色

	RBTreeNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _color(RED)
	{}
};

template <class T>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;

	RBTree()
		:_root(nullptr)
	{}

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			//根节点为黑色
			_root->_color = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		//1.寻找到要插入的结点的位置
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)//key值相同插入失败
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		//2.创建节点
		cur = new Node(val);
		if (parent->_val > cur->_val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//3.颜色的修改或者结构的调整
		while (cur != _root && cur->_parent->_color == RED)//不为根且存在连续红色，则需要调整
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
		_root->_color = BLACK;
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
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

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
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

	void inoder()
	{
		_inoder(_root);
		cout << endl;
	}
	void _inoder(Node* root)
	{
		if (root)
		{
			_inoder(root->_left);
			cout << root->_val << " ";
			_inoder(root->_right);
		}
	}

	bool isRBTree()
	{
		if (_root == nullptr) //空树也属于红黑树
			return true;
		if (_root->_color == RED) //不满足条件二：根节点必须为黑色
			return false;

		int bCount = 0; //某条路径上的黑色结点数
		Node* cur = _root;
		while (cur)
		{
			if (cur->_color == BLACK)
				++bCount;
			cur = cur->_left;
		}
		int pathCount = 0;
		return _isRBTree(_root, bCount, pathCount);//遍历判断每条路径上的黑色结点个数是否相同
	}

	bool _isRBTree(Node* root, const int bCount, int pathCount)
	{
		if (root == nullptr)//路径走完，判断黑色结点个数
		{
			if (pathCount == bCount)
				return true;
			else
				return false;//不满足条件三： 每一条路径上的黑色结点个数相同
		}

		if (root->_color == BLACK)//遇到黑色结点就++
			++pathCount;

		Node* parent = root->_parent;
		if (parent && parent->_color == RED && root->_color == RED)
			return false; //不满足条件四：不能存在连续红色的节点

		return _isRBTree(root->_left, bCount, pathCount) //继续遍历左子树和右子树
			&& _isRBTree(root->_right, bCount, pathCount);
	}

private:
	Node* _root;
};

void test()
{
	RBTree<int> rbt;
	srand(time(nullptr));
	int n;
	cout << "num：" << endl;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		rbt.insert(rand());
	}
	rbt.inoder();
	cout << rbt.isRBTree() << endl;
}

int main()
{
	test();
	return 0;
}

//int main()
//{
//	RBTree<int> rbt;
//	for (int i = 10; i > 0; --i)
//	{
//		rbt.insert(i);
//	}
//	//rbt.insert(10);
//	//rbt.insert(15);
//	//rbt.insert(5);
//	//rbt.insert(2);
//	return 0;
//}