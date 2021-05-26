//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char ccString1[] = "Is Page Fault??";
//	char ccString2[] = "No Page Fault??";
//	strcpy(ccString1, "No");
//	if (strcmp(ccString1, ccString2) == 0)
//		cout << ccString2;
//	else
//		cout << ccString1;
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getLuckPacket(vector<int>& x, int n, int pos, int sum, int multi)
{
    int count = 0;
    for (int i = pos; i < n; ++i)
    {
        sum += x[i];
        multi *= x[i];
        //判断是否幸运
        if (sum > multi)
        {
            //幸运+1
            count += 1 + getLuckPacket(x, n, i + 1, sum, multi);
        }
        else if (x[i] == 1)
            count += getLuckPacket(x, n, i + 1, sum, multi);
        else
            break;
        //回溯
        sum -= x[i];
        multi /= x[i];

        //去重
        while (i < n - 1 && x[i] == x[i + 1])
            ++i;
    }
    return count;
}

int main()
{
    int n = 3;
    
    vector<int> vec = {1, 1, 1};
    sort(vec.begin(), vec.end());
    cout << getLuckPacket(vec, n, 0, 0, 1) << endl;
    
    return 0;
}
