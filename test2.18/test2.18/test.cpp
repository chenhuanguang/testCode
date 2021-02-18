#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//int main()
//{
//	char s[] = "abcdefgh";
//	char* p = s;
//	p += 3;
//	char* ps = strcpy(p, "ABCD");
//	cout << strlen(ps) << endl;
//
//	return 0;
//}

bool isPalindrome(char* s)
{
    int len = strlen(s);
    int head = 0;
    int tail = len - 1;

    while (head < tail)
    {
        while (head < tail && !isalpha(s[head]) && !isdigit(s[head]))
        {
            head++;
        }
        while (head < tail && !isalpha(s[tail]) && !isdigit(s[tail]))
        {
            tail--;
        }
        if (s[head] == s[tail] || s[head] - 32 == s[tail] || s[head] + 32 == s[tail])
        {
            head++;
            tail--;
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char s[] = "0P";
    isPalindrome(s);

    return 0;
}