//#include <iostream>
//using namespace std;
//void main() {
//	int n[][3] = { 10,20,30,40,50,60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[4] << endl;
//	return;
//}

#include <iostream>
#include <vector>
using namespace std;

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
	int size;
	cin >> size;
	vector<int> v(size);
	for (int i = 0; i < size; ++i)
	{
		cin >> v[i];
	}

	int sum = v[0];
	int res = v[0];
	for (int i = 1; i < size; ++i)
	{
		sum = getMax(sum + v[i], v[i]);
		res = getMax(sum, res);
	}
	cout << res << endl;
	return 0;
}

//int getMax(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> v[i];
//    }
//    int res = v[0];
//    int sum = v[0];
//    for (int i = 1; i < n; ++i)
//    {
//        sum = getMax(sum + v[i], v[i]);
//        res = getMax(res, sum);
//    }
//    cout << res << endl;
//    return 0;
//}