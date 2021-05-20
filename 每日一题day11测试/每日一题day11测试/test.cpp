#include <iostream>
using namespace std;

int main()
{
    int n;
    int res = 0;
    while (cin >> n)
    {
        for (int i = 0; i < 32; ++i)
        {
            int count = 0;
            while ((n >> i)&1 == 1)
            {
                ++count;
                ++i;
            }
            if (count > res)
                res = count;
        }
        cout << res << endl;
    }

    return 0;
}
//
//class A
//
//{public:
//	A()
//	{
//		cout << "1" << endl;
//	}
//};
//
//int fun(int n)
//{
//	if (n < 2)
//		return n;
//	else
//		return 2 * fun(n - 1) + fun(n - 2);
//}
//
//int main()
//{
//	A (*a)[3];
//	A b;
//	//cout << fun(5) << endl;
//	return 0;
//}

//int getLCA(int a, int b) {
//    if (a > b)
//    {
//        int tmp = a;
//        a = b;
//        b = tmp;
//    }
//    while (b > a)
//    {
//        b /= 2;
//    }
//    if (b == a)
//        return a;
//    else
//    {
//        while (a != b)
//        {
//            a /= 2;
//            if (a == b)
//                break;
//            else if (b > 1)
//                b /= 2;
//        }
//    }
//    return a;
//}
//
//int main()
//{
//    getLCA(2, 3);
//    return 0;
//}