#include <iostream>
#include <time.h>
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
				else if (parent->_bf == 2 && cur->_bf == 1)//右边的右边高
				{
					//左单旋
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) //左边的右边高
				{
					//左右双旋
					Node* subLR = cur->_right;
					int bf = subLR->_bf;
					RotateL(cur);
					RotateR(parent);
					if (bf == -1)
					{
						parent->_bf = 1;
						cur->_bf = 0;
					}
					if (bf == 1)
					{
						parent->_bf = 0;
						cur->_bf = -1;
					}
				}
				else if(parent->_bf == 2 && cur->_bf == -1) //右边的左边高
				{
					//右左单旋时
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
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		subR->_left = parent;
		parent->_parent = subR;

		subR->_bf = parent->_bf = 0;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val << " ";
			_inorder(root->_right);
		}
	}

	int height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = height(root->_left);
		int right = height(root->_right);

		return left > right ? left + 1 : right + 1;
	}

	bool _isBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		//查看平衡因子是否和左右子树的高度差一致
		int left = height(root->_left);
		int right = height(root->_right);

		if (right - left != root->_bf || abs(root->_bf) > 1)//不相等或者平衡因子有误则表示不是AVL树
			return false;
		return _isBalance(root->_left) && _isBalance(root->_right);
	}

	bool isBalance()
	{
		cout << endl;
		return _isBalance(_root);
	}
private:
	Node* _root = nullptr;
};

void test()
{
	srand(time(nullptr));
	cout << "num : ";
	int num;
	cin >> num;
	AVLTreeNode<int> avl;
	for (int i = 0; i < num; ++i)
	{
		avl.insert(rand());
	}
	avl.inorder();
	cout << avl.isBalance() << endl;
}

//void test()
//{
//	AVLTreeNode<int> avl;
//	avl.insert(5);
//	avl.insert(3);
//	avl.insert(1); //右单旋
//	avl.insert(0);
//	avl.insert(2);
//	avl.insert(-1);//右单旋
//	//       1
//	//    0      3
//	// -1      2   5
//	avl.insert(10);
//	avl.insert(15); //左单旋
//	//左单旋前
//	//       1
//	//    0      3
//	// -1      2   5
//	//               10
//	//                  15
//	//左单旋后
//	//       1
//	//    0      3
//	// -1      2    10
//	//             5  15
//	avl.insert(20);//左单旋
//	//左单旋前
//	//       1
//	//    0      3
//	// -1      2    10
//	//            5    15
//	//                   20
//	//左单旋后
//	//       1
//	//    0      10
//	// -1      3    15
//	//       2   5     20
//	avl.inorder();
//}

//void test()
//{
//	AVLTreeNode<int> avl;
//	avl.insert(5);
//	avl.insert(3);
//	//    5
//	// 3
//	avl.insert(1); //右单旋
//	//    3
//	// 1     5 
//	avl.insert(0);
//	avl.insert(2);
//	avl.insert(-1);//右单旋
//	//右旋前
//	//       3
//	//    1      5
//	//  0  2
//	//-1
//	//右旋后
//	//       1
//	//    0      3
//	// -1      2   5
//}

int main()
{
	test();
	return 0;
}