#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

typedef struct BNode
{
	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}Node;

//创建二叉树
Node* CreatBinaryTree(DataType arr[], int* idx);

//先序遍历
void PreOrder(Node* root);

//中序遍历
void InOrder(Node* root);

//后序遍历
void PostOrder(Node* root);

//求二叉树结点的个数
int BTreeSize(Node* root);

//求二叉树的高度
int BTreeHigh(Node* root);

//叶子结点
int BTreeLeafSize(Node* root);

//第k层的结点
int BTreeKSize(Node* root, int k);

//查找二叉树中的结点
Node* BTreeFind(Node* root, DataType val);

//销毁二叉树
void BTreeDestory(Node** root);