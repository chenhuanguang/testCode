#include "btree.h"
#include "queue.h"

//数组名，数组索引（为指针的目的是让函数在调用递归时索引的改变起全局作用）
Node* CreatBinaryTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;	//空结点
	}
	//当前树的根节点
	Node* root = (Node*)malloc(sizeof(Node));
	if (root != NULL)
	{
		root->_data = arr[*idx];
	}
	else
		return NULL;
	(*idx)++;

	root->_left = CreatBinaryTree(arr, idx);
	root->_right = CreatBinaryTree(arr, idx);

	return root;
}

void PreOrder(Node* root)
{
	if (root != NULL)
	{
		//根
		printf("%c ", root->_data);
		//左子树
		PreOrder(root->_left);
		//右子树
		PreOrder(root->_right);
	}
}

void InOrder(Node* root)
{
	if (root != NULL)
	{
		//左子树
		InOrder(root->_left);
		//根
		printf("%c ", root->_data);
		//右子树
		InOrder(root->_right);
	}
}

void PostOrder(Node* root)
{
	if (root != NULL)
	{
		//左子树
		PostOrder(root->_left);
		//右子树
		PostOrder(root->_right);
		//根
		printf("%c ", root->_data);
	}
}

int BTreeSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BTreeSize(root->_left)  //左子树结点数 + 右子树结点数+ 当前节点
		+ BTreeSize(root->_right) + 1;
}

int BTreeHigh(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = BTreeHigh(root->_left);
	int right = BTreeHigh(root->_right);

	//返回该结点的左右孩子的度的最大值
	return left > right ? left + 1 : right + 1;
}

int BTreeLeafSize(Node* root)
{
	//空树
	if (root == NULL)
	{
		return 0;
	}
	//叶子结点
	if (root->_left == NULL
		&& root->_right == NULL)
	{
		return 1;
	}
	//非叶子结点
	return BTreeLeafSize(root->_left)
		+ BTreeLeafSize(root->_right);
}

int BTreeKSize(Node* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return BTreeKSize(root->_left, k - 1)
		+ BTreeKSize(root->_right, k - 1);
}

Node* BTreeFind(Node* root, DataType val)
{
	if (root != NULL)
	{
		if (root->_data == val)
		{
			return root;
		}
		Node* node = BTreeFind(root->_left, val);
		if (node)
		{
			return node;
		}
		else
			return BTreeFind(root->_right, val);
	}
	else
	{
		return NULL;
	}
}

void BTreeDestory(Node** root)
{
	if (*root == NULL)
	{
		return;
	}
	else
	{
		BTreeDestory(&((*root)->_left));
		BTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}

void BinaryTreeLevelOrder(Node* root)
{
	//队列
	Queue q;
	QueueInit(&q);

	//将根节点先入队
	if (root)
		QueuePush(&q, root);
	//只要队列不为空就继续循环
	while (!QueueEmpty(&q))
	{
		//获取队头元素
		Node* front = QueueFront(&q);
		//出队
		QueuePop(&q);
		printf("%c ", front->_data);
		//左孩子非空，入队
		if (front->_left)
			QueuePush(&q, front->_left);
		//右孩子非空，入队
		if (front->_right)
			QueuePush(&q, front->_right);
	}
}

int BinaryTreeComplete(Node* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		Node* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{ //遇到空结点，结束第一个循环，进入第二个循环去判断后面是否全为空结点
			break;
		}
	}

	while (!QueueEmpty(&q))
	{
		Node* front = QueueFront(&q);
		QueuePop(&q);
		//有结点不为空，不是完全二叉树
		if (front)
			return 0;
	}

	return 1;
}

void Test()
{
	char str[] = "ABD##EG##H##CF###";
	int idx = 0;
	Node* root = CreatBinaryTree(str, &idx);
	BinaryTreeLevelOrder(root);
	int res = BinaryTreeComplete(root);
	printf("\n");
	//printf("%d\n", res);
}

int main()
{
	Test();

	return 0;
}