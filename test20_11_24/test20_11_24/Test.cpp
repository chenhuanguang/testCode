#include<iostream>
using namespace std;

int main()
{
	const int a = 10;
	int b = 0;
	int *p = (int *)&a;
	*p = 100;
	b = a;

	cout << "a = " << a << " b = " << b << " *p = " << *p << endl;

	return 0;
}