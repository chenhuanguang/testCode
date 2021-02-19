#include <iostream>
using namespace std;

int compress(char* chars, int charsSize)
{
    int left = 0;
    int right = 1;
    int res = 0;
    if (charsSize == 1)
    {
        return ++res;
    }
    while (left < charsSize)
    {
        int count = 1;
        while (right < charsSize && chars[left] == chars[right])
        {
            ++count;
            ++right;
        }

        if (count > 1 && count < 10)
        {
            chars[++res] = count + '0';
            left = right;
        }
        else if (count > 9 && count < 100)
        {
            chars[++res] = count / 10 + '0';
            chars[++res] = count % 10 + '0';
            left = right;
        }
        else if (count > 99 && count < 1000)
        {
            chars[++res] = count / 100 + '0';
            chars[++res] = count % 100 / 10 + '0';
            chars[++res] = count % 100 % 10 + '0';
            left = right;
        }
        else if (count >= 1000)
        {
            chars[++res] = 1 + '0';
            chars[++res] = 0 + '0';
            chars[++res] = 0 + '0';
            chars[++res] = 0 + '0';
            left = right;
        }
        else
        {
            ++left;
        }
        ++res;
        if (right < charsSize)
            chars[res] = chars[right++];
    }
    return res;
}
int main()
{
    char str[] = { 'a' ,  'b' , 'c' , 'g', 'g', 'g','g','g','g','g','g','g','g','g','g','a', 'b', 'c'};
    compress(str, 18);
	/*int num = 234;
	cout << num  % 100 % 10 << endl;*/

	return 0;
}