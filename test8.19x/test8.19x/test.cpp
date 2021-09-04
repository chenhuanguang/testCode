#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

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
			_lrulist.erase(pos);
			_lrulist.push_front(kv);
			ret->second = _lrulist.begin();

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
			_lrulist.erase(pos);
			_lrulist.push_front(make_pair<key, value>);
			ret->second = _lrulist.begin();
		}
		else
		{
			if (_lrulist.size() == _capacity)
			{
				pair<int, int> back = _lrulist.back();
				_hashmap.erase(back.first);
				_lrulist.pop_back();
			}
			
			_lrulist.push_front(make_pair<key, value>);
			_hashmap.insert(make_pair<int, _lrulist.begin()>);
		}

		return;
	}

private:
	int _capacity;
	list<pair<int, int>> _lrulist;
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
};