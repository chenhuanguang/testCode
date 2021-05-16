#include <iostream>
#include <time.h>
using namespace std;

template <class T>
struct BNode
{
	typedef BNode<T> Node;
	T _data; //数据
	Node* _left;//左孩子
	Node* _right;//右孩子

	BNode(const T& data)
		:_data(data)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template <class T>
class BTree
{
public:
	typedef BNode<T> Node;
	BTree()
		:_root(nullptr)
	{}
	Node* find(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data == val)
				return cur;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}//平均性能logN
	}
	//不插入重复的值
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
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
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
			cout << root->_data << " ";
			_inorder(root->_right);
		}
	}

	//拷贝二叉搜索树的数据和结构
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newNode = new Node(root->_data);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}
	BTree(const BTree<T>& btree)
		:_root(copy(btree._root))
	{}

	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
	}
	~BTree()
	{
		if (_root)
		{
			destroy(_root);
			_root = nullptr;
		}
	}

	bool erase(const T& data)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			
			if (cur->_data == data)
				break;
			
			else if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;
			}			
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
		//判断是否找到了需要删除的结点
		if (cur == nullptr)
			return false;//未找到数据
		//删除结点
		//1、删除的结点为叶子结点
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			//特殊情况是否根节点
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				//需要判断当前节点的位置
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			//删除结点
			delete cur;
		}
		//2.存在一个孩子
		else if (cur->_left == nullptr)//左孩子为空，右孩子非空
		{

			//特殊情况是否根节点
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				if (parent->_left == cur)//删除的是父节点的左边
					parent->_left = cur->_right;//就让父节点连接删除的结点的右孩子（左孩子为空，右孩子非空）
				else
					parent->_right = cur->_right;//同理，无论删除的是那边，都连接的是右孩子
			}
			//删除结点
			delete cur;
		}
		else if (cur->_right == nullptr)
		{
			//特殊情况是否根节点
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				if (parent->_left == cur)//删除的是父节点的左边
					parent->_left = cur->_left;//就让父节点连接删除的结点的左孩子（左孩子非空，右孩子为空）
				else
					parent->_right = cur->_left;//同理，无论删除的是那边，都连接的是左孩子
			}
			//删除结点
			delete cur;
		}
		else
		{
			//第一种情况-找左子树的最右节点
			Node* leftRightMost = cur->_left;
			parent = cur;//此时下面用到的parent都为leftRightMost的父节点

			while (leftRightMost->_right)//查找最右节点
			{
				parent = leftRightMost;
				leftRightMost = leftRightMost->_right;
			}

			//交换
			swap(cur->_data, leftRightMost->_data);

			//删除最右节点
			if (parent->_left == leftRightMost)
				parent->_left = leftRightMost->_left;//最右节点肯定没有右孩子
			else
				parent->_right = leftRightMost->_left;

			delete leftRightMost;
		}
		return true;
	}
private:
	Node* _root;//根
};

//void test()
//{
//	BTree<int> b;
//	srand(time(nullptr));
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; ++i)
//	{
//		b.insert(rand());
//	}
//	b.inorder();
//	cout << endl;
//	BTree<int> b1 = b;
//	b1.inorder();
//}
//
//int main()
//{
//	test();
//	return 0;
//}

int main()
{
	BTree<int> b;
	b.insert(5);
	b.insert(8);
	b.insert(3);
	b.insert(4);
	b.insert(7);
	b.insert(9);
	b.insert(1);
	b.inorder();
	b.erase(4);//删除叶子结点
	b.inorder();
	b.erase(3);//删除只有左或者右结点
	b.inorder();
	b.erase(5);//既有左孩子也有右孩子的结点
	b.inorder();
	return 0;
}