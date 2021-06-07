#include<iostream>
#include <string>
using namespace std;

int numRoot(int n)
{
    int sum = 0;//用于保存树根结果
    while (n)
    {
        sum += n % 10;
        n /= 10;
        //计算出树根，但树根不为1位数，则继续计算
        if (n == 0 && sum >= 10)
        {
            n = sum;
            sum = 0;
        }
    }
    return sum;
}
int main()
{
    string str;//用于接收输入的数据
    while (cin >> str)
    {
        int n = 0;
        //直接进行第一次树根运算，也就是每位都进行相加
        for (int i = 0; i < str.size(); ++i)
        {
            n += str[i] - '0';
        }
        cout << numRoot(n) << endl;
    }
    return 0;
}

//int main()
//{
//	int a = 1;
//	printf("%1.4d\n", a);
//	return 0;
//}

//int main()
//{
//
//	vector<int> arr = { 0, 1, 2 };
//	arr.resize(10000);
//	for (int i = 3; i <= arr.size(); ++i)
//	{
//		arr[i] = arr[i - 1] + arr[i - 2];
//		arr[i] %= 10000;
//	}
//
//	int n;
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			int num;
//			cin >> num;
//			printf("%04d", arr[num]);
//		}
//		cout << endl;
//	}
//	return 0;
//}
//int Add(int num1, int num2)
//{
//    if (num1 == 0 || num2 == 0)
//        return num1 == 0 ? num2 : num1;
//    while (num2)
//    {
//        num1 = num1 ^ num2;
//        num2 = (num1 & num2) << 1;
//    }
//    return num1;
//}
//
//int main()
//{
//    cout << Add(1, 3) << endl;
//    return 0;
//}