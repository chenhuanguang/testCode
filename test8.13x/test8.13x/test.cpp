#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr(3, 1);
	int* a = new int(2);
	cout << a << endl;
	cout << &arr[0] << endl;
	int b = 0;
	cout << &b << endl;

	return 0;
}