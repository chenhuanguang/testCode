#include <iostream>
using namespace std;

//int fun(int x, int y)
//{
//	if (x == y)
//		return (x);
//	else
//		return ((x + y) / 2);
//}

void reserve(char* str)
{
    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left;
        --right;
    }
}

char* addBinary(char* a, char* b)
{
    reserve(a);
    reserve(b);
    int len = (strlen(a) > strlen(b)) ? strlen(a) + 2 : strlen(b) + 2;
    int carry = 0;
    int idx = 0;
    char* res = (char*)malloc(sizeof(char) * len);
    for (int i = 0; i < len - 2; ++i)
    {
        carry += i < strlen(a) ? (a[i] == '1') : 0;
        carry += i < strlen(b) ? (a[i] == '1') : 0;
        res[idx++] = carry % 2 + '0';
        carry /= 2;
    }

    if (carry) {
        res[idx++] = '1';
    }
    res[idx] = '\0';
    reserve(res);

    return res;

}
int main()
{
	/*int a = 4, b = 5, c = 6;
	printf("%d\n", fun(2 * a, fun(b, c)));*/

    char a[] = "1010";
    char b[] = "1011";
    addBinary(a, b);
	return 0;
}