#include <iostream>
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
		,_left(nullptr)
		,_right(nullptr)
		,_val(val)
		,_bf(0)//初始化为0，叶子无左右孩子
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

		//1.查找到要插入的位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;//记录插入节点的父节点
			if (cur->_val == val)//存在相同节点退出
				return false;
			else if (cur->_val > val)//插入节点比当前节点小，则硬插入当前节点的左子树中
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		//2.连接节点关系
		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//3.修改平衡因子，调整成AVL树
		while (parent)
		{
			//更新父节点的平衡因子，判断是否还平衡
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;

			if (parent->_bf == 0) //表示parent的子树比较短的子树高度+1，不影响parent的父节点的平衡因子，插入完毕
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)//表示parent更新前为0，更新后不为0，树的高度有变，会影响parent的父节点
			{
				//向上追溯修改parent父节点的平衡因子
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)//左边的左边高
				{
					//右单旋
					RotateR(parent);
				}
				//...
				break;
			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)//如果不为空需要更新_parent
			subLR->_parent = parent;

		if (parent == _root) //父节点为根，则不考虑pparent的连接
		{
			//更新根节点
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
private:
	Node* _root = nullptr;
};

void test()
{
	AVLTreeNode<int> avl;
	avl.insert(5);
	avl.insert(3);
	//    5
	// 3
	avl.insert(1); //右单旋
	//    3
	// 1     5 
	avl.insert(0);
	avl.insert(2);
	avl.insert(-1);//右单旋
	//右旋前
	//       3
	//    1      5
	//  0  2
	//-1
	//右旋后
	//       1
	//    0      3
	// -1      2   5
}

int main()
{
	test();
	return 0;
}