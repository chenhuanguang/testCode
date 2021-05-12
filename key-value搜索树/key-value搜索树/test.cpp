#include <iostream>
#include <time.h>
using namespace std;

template <class K, class V>
struct BNode
{
	typedef BNode<K, V> Node;
	K _key; //
	V _value;
	Node* _left;//左孩子
	Node* _right;//右孩子

	BNode(const K& key, const V& value)
		:_key(key)
		,_value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class K, class V>
class BTree
{
public:
	typedef BNode<K, V> Node;
	BTree()
		:_root(nullptr)
	{}
	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}//平均性能logN
		return cur;
	}
	//不插入重复的值
	bool insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(key, value);
		if (parent->_key > key)
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
			cout << root->_key << "-->" << root->_value <<" ";
			_inorder(root->_right);
		}
	}

	//拷贝二叉搜索树的数据和结构
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newNode = new Node(root->_key, root->_value);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}
	BTree(const BTree<K, V>& btree)
		:_root(copy(btree._root))
	{}

	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			cout << "destory:" << root->_key << "-->" << root->_value << endl;
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

	bool erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{

			if (cur->_key == key)
				break;

			else if (cur->_key > key)
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
			swap(cur->_key, leftRightMost->_key);
			swap(cur->_value, leftRightMost->_value);

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

void test()
{
	BTree<int, int> b;
	b.insert(5, 50);
	b.insert(3, 30);
	b.insert(7, 70);
	b.insert(1, 10);
	b.insert(4, 40);
	b.insert(6, 60);
	b.insert(8, 80);
	b.insert(0, 100);
	b.insert(2, 50);
	b.insert(9, 90);
	b.inorder();
	b.erase(5);
	b.inorder();

}

int main()
{
	test();
	return 0;
}