#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    int flag = 1;
    for (int i = 2; i * i <= n && flag; ++i)
        if (n % i == 0)flag = 0;
    return flag;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int num = 2;
    for (int i = 2; i < n; ++i)
    {
        if (isPrime(i))
            arr.push_back(i);
    }
    int left = 0;
    int right = arr.size() - 1;
    int res1 = 0;
    int res2 = 0;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == n)
        {
            res1 = left;
            res2 = right;
            --right;
            ++left;
        }
        else if (sum > n)
            --right;
        else
            ++left;
    }
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}
//#define SQR(A) A*A
//void fun(const int& va, const int& vb)
//{
//	cout << va << vb << endl;
//}
//int main()
//{
//	/*int i = 0;
//	fun(++i,i++);*/
//	int x = 6, y = 3, z = 2;
//	x = SQR(y + z) / SQR(y + z);
//	cout << x;
//	return 0;
//}
//struct st_task
//{
//	uint16_t id;
//	uint32_t value;
//	uint64_t time;
//};
//
//int main()
//{
//	//st_task task = {};
//	//uint64_t a = 0x00010001;
//	//memcpy(&task, &a, sizeof(uint64_t));
//	////int arr[2][] = { {1,2},{3,4} };
//	//int arr[2][2] = { {1}, 2, 3 };
//	//for (int i = 0; i < 2; ++i)
//	//{
//	//	for (int j = 0; j < 2; ++j)
//	//	{
//	//		cout << arr[i][j];
//	//	}
//	//}
//	int m = 1024;
//	int n = 19;
//	int j = 2;
//	int i = 6;
//	n = n << 2;
//	cout << m + n << endl;
//}