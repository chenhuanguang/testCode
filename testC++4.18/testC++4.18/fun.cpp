#include <iostream>
#include "fun.h"
using namespace std;
template<class T>
T fun(const T& a)
{
	cout << a << endl;
	return a;
}
void test()
{
	fun(10);
}