#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

//int main()
//{
//	int* arr = (int*)malloc(sizeof(int) * 10);
//	arr[0] = 1;
//	int p2 = 0;
//	int p3 = 0;
//	int p5 = 0;
//	for (int i = 1; i < 10; ++i)
//	{
//		arr[i] = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
//		if (arr[i] == 2 * arr[p2])
//			++p2;
//		if (arr[i] == 3 * arr[p3])
//			++p3;
//		if (arr[i] == 5 * arr[p5])
//			++p5;
//	}
//	cout << arr[9] << endl;
//	return 0;
//}

//int numJewelsInStones(char* jewels, char* stones)
//{
//    if (jewels == NULL)
//    {
//        return 0;
//    }
//    if (stones == NULL)
//    {
//        return 0;
//    }
//
//    int res = 0;
//    char* tmp = jewels;
//    while (*stones != '\0')
//    {
//        tmp = jewels;
//        while (*tmp != '\0')
//        {
//            if (*stones == *tmp)
//            {
//                ++res;
//                break;
//            }
//            tmp++;
//        }
//        stones++;
//    }
//
//    return res;
//}
//
//int main()
//{
//    char j[] = "aA";
//    char s[] = "aAAbbb";
//    numJewelsInStones(j, s);
//}

//#define MAXLEN 26
//int g_sum;
//
//void DFS(int* cnt)
//{
//    for (int i = 0; i < MAXLEN; i++) {
//        if (cnt[i] > 0) {
//            cnt[i]--;
//            g_sum++;
//            DFS(cnt);
//            cnt[i]++;
//        }
//    }
//}
//
//int numTilePossibilities(char* tiles)
//{
//    int* cnt = (int*)calloc(MAXLEN, sizeof(int));
//    g_sum = 0;
//    int len = strlen(tiles);
//    for (int i = 0; i < len; i++) {
//        cnt[tiles[i] - 'A']++;
//    }
//    DFS(cnt);
//    return g_sum;
//}
//
//
//int main()
//{
//    char s[] = "AAB";
//    numTilePossibilities(s);
//
//    return 0;
//}

bool halvesAreAlike(char* s)
{
    char a[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' ,'\0'};
    int len = strlen(s);
    int total1 = 0;
    int total2 = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < strlen(a); ++j)
        {
            if (s[i] == a[j] && i < len / 2)
            {
                total1++;
                break;
            }
            else if (s[i] == a[j] && i >= len / 2)
            {
                total2++;
                break;
            }
        }
    }

    return total1 == total2;
}

int main()
{
    char s[] = "testbook";
    halvesAreAlike(s);
    return 0;
}