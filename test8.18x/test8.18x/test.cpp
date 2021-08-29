#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};

void postOrder(Node* root)
{
	stack<Node*> st;
	Node* prev = nullptr;
	while (root || !st.empty())
	{
		while (root)
		{
			st.push(root);
			root = root->left;
		}
		Node* top = st.top();
		if (top->right == nullptr || top->right == prev)
		{
			st.pop();
			cout << top->val << " ";
			prev = top;
		}
		else
			root = top->right;
	}
}