#include <iostream>
#include <string>
using namespace std;

int a = 2;
namespace
{
    int a;
    double b;
}
int main()
{

    a = 2;
    cout << a << b << endl;
    return 0;
}