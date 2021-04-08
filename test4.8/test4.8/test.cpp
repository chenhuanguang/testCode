#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	char c = (*(char*)&i);
	if (c)
		cout << "小端" << endl;
	else
		cout << "大端" << endl;
	return 0;
}

//int main()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	if (un.c)
//		cout << "小端" << endl;
//	else
//		cout << "大端" << endl;
//	return 0;
//}