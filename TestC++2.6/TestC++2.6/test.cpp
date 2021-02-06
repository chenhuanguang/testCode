#include <iostream>
using namespace std;

//class A
//{
//public:
//	void setA(int a) 
//	{
//		_a = a;
//		getA();
//	}
//
//	int getA() const 
//	{
//		setA();
//		return _a;
//	}
//
//private:
//	int _a;
//};
//
//class A
//{
//public:
//	//取地址操作符重载
//	A* operator&() 
//	{
//		return this;
//	}
//	//const取地址操作符重载
//	const A* operator&() const
//	{
//		return this;
//	}
//};
//
//int main()
//{
//	A a;
//	A* b = &a;
//	const A* c = &a;
//
//	return 0;
//}

//int main()
//{
//	A a;
//	a.setA(10);
//	a.getA();
//
//	const A b;
//	b.getA();
//	b.setA(20);
//
//	return 0;
//}

void Swap(int* arr, int start, int end)
{
    --end;
    while (start <= end)
    {
        arr[start] = arr[start] ^ arr[end];
        arr[end] = arr[start] ^ arr[end];
        arr[start] = arr[start] ^ arr[end];
        --start;
        --end;
    }
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int cur = digitsSize - 1;
    int idx = 0;
    int carry = 0;

    while (cur >= 0)
    {
        digits[cur] ++;
        if (digits[cur] > 9)
        {
            digits[cur--] = 0;
            res[idx++] = 0;
        }
        else
        {
            res[idx++] = digits[cur--];
            break;
        }
    }

    while (cur >= 0)
    {
        res[idx++] = digits[cur--];
    }

    Swap(res, 0, idx);
    *returnSize = idx;
    return res;
}

int main()
{
    int arr[] = { 1,2,3 };
    int res = 0;
    plusOne(arr, 3, &res);

    return 0;
}