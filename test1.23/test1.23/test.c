#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//#define N 2
//#define M N+1
//#define NUM (M+1)*M/2
//
//int main()
//{
//	qsort()
//	printf("%d\n", NUM);
//	return 0;
//}

bool isLongPressedName(char* name, char* typed)
{
    int len1 = strlen(name);
    int len2 = strlen(typed);
    if (len1 >= len2)
        return false;
    char* pn = name;
    char* pt = typed;

    while (*pn != '\0' && *pt != '\0')
    {
        int len = 0;
        while (*pn == *(pn + 1))
        {
            len++;
            pn++;
        }
        if (*pn == *pt)
        {
            while (*pt == *pn)
            {
                pt++;
                len--;
            }
            if (len >= 0)
                return false;
        }
        else
        {
            return false;
        }
        pn++;
    }
    char tmp = *pt;
    while (*pt)
    {
        if (*pt != tmp)
            return false;
        pt++;
    }
    return true;
}

int main()
{
    char name[] ="alex" ;
    char typed[] = "aaleexa";

    isLongPressedName(name, typed);
    return 0;
}