#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <unordered_map>
using namespace std;

class Node
{
public:
	int val;
	Node* left;
	Node* right;
};

vector<int> fun(Node* root)
{
	vector<int> res;
	if (root == nullptr)
	{
		return res;
	}

	queue<Node*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int len = queue.size();
		for (int i = 0; i < len; ++i)
		{
			root = queue.front();
			if (i == len - 1)
				res.push_back(root->val);
			queue.pop();
			if (root->left)
				queue.push(root->left);
			if (root->right)
				queue.push(root->right);
		}
	}

	return res;
}

class LRU
{
public:

	int get(int key)
	{
		auto ret = _hashmap.find(key);
		if (ret != _hashmap.end())
		{
			list<pair<int, int>>::iterator pos = ret->second;
			pair<int, int> kv = *pos;
			_lruList.erase(pos);
			_lruList.push_front(kv);
			ret->second = _lruList.begin();

			return kv.second;
		}

		return -1;
	}

	void set(int key, int value)
	{
		auto ret = _hashmap.find(key);
		if (ret != _hashmap.end())
		{
			list<pair<int, int>>::iterator pos = ret->second;
			_lruList.erase(pos);
			_lruList.push_front(make_pair<key, value>);
			ret->second = _lruList.begin();
		}
		else
		{
			if (_lruList.size() == _capacity)
			{
				pair<int, int> back = _lruList.back();
				_hashmap.erase(back.second);
				_lruList.pop_back();
			}
			_lruList.push_front(make_pair<key, value>);
			_hashmap.insert(make_pair<key, _lruList.begin()>);
		}
		return;
	}

private:
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
	list<pair<int, int>> _lruList;
	int _capacity;
};
