#include <iostream>
using namespace std;

template <class K, class V, int M = 4>
struct BTreeNode
{
	pari<K, V> _kvs[M - 1];
	BTreeNode<K, V, M>* _children[M];
	BTreeNode<K, V, M>* _parent;
};

template <class K, class V, int M = 4>
class BTree
{
private:
	BTreeNode<K, V, M>* _root;
};
