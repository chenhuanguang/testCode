#include <iostream>
using namespace std;

//int main()
//{
//	short i = 65537;
//	int j = i + 1;
//	cout << i << " " << j << endl;
//
//	return 0;
//}

int main()
{
	int a[] = { 2, 4, 6, 8, 10 }, * p, ** k;
	p = a;
	k = &p;
	printf(" % d", *(p++));
	printf(" % d\n", **k);
	return 0;
}