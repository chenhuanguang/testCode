#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}

void fun2(vector<int>& vec, int num)
{
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            vec.push_back(i);
            vec.push_back(num / i);
            break;
        }
    }
}

void fun(int n)
{
    if (isPrime(n))
    {
        cout << n << " = " << 1 << " * " << n << endl;
        return;
    }
    vector<int> vec;
    fun2(vec, n);
    cout << n << " = " << vec[0];
    int tmp = vec[1];
    while (!isPrime(tmp))
    {
        vec.clear();
        fun2(vec, tmp);
        tmp = vec[1];
        cout << " * " << vec[0];
    }
    cout << " * " << tmp << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        fun(n);
    }
    return 0;
}