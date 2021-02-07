#include <iostream>
using namespace std;

class A
{
public:
	//void setId(const A* const this)
	//指向内容都不能变
	void setId(int id) const
	{
		_id = id;
	}
	//int getId(A* const this)
	//指向不能变
	int getId()
	{
		return _id;
	}
private:
	int _id;
};

int main()
{


	return 0;
}