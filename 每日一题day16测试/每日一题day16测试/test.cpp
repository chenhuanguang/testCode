//#include <iostream>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//void get_div_num(int v, vector<int>& vec)
//{
//    for (int i = 2; i <= sqrt(v); ++i)
//    {
//        if (v % i == 0)
//        {
//            vec.push_back(i);
//            int v1 = v / i;
//            if (v1 != i)
//                vec.push_back(v1);
//        }
//    }
//}
//
//int count(int n)
//{
//    int count = 0;
//    for (int i = 2; i <= n; ++i)
//    {
//        vector<int> vec;
//        get_div_num(i, vec);
//        int sum = 0;
//        for (int j = 0; j < vec.size(); ++j)
//        {
//            sum += vec[j];
//        }
//        sum += 1;
//        if (sum == i)
//            count++;
//    }
//    return count;
//}
//
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        cout << count(n) << endl;
//    }
//    return 0;
//}

#include <iostream>
//#include <string>
//using namespace std;
//
//string compare(string& str)
//{
//    string prev = "";
//    string post = "";
//    int flag = true;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] == '-')
//        {
//            flag = !flag;
//            continue;
//        }
//        if (str[i] == ' ')
//            continue;
//        if (flag)
//            prev += str[i];
//        else
//            post += str[i];
//    }
//
//    if (prev.size() == 11)
//        return prev;
//    if (post.size() == 11)
//        return post;
//    if (prev.size() == 1 || post.size() == 1)
//    {
//        if (prev[0] == '2')
//            prev[0] = 15 + '\0';
//        if (prev[0] == 'A')
//            prev = '14' + '\0';
//        if (post[0] == '2')
//            post[0] = '15' + '\0';
//        if (post[0] == 'A')
//            post = '14' + '\0';
//        return prev[0] > post[0] ? prev : post;
//    }
//
//    if (prev.size() == 2)
//    {
//        if (prev[0] == '2')
//            prev[0] = 15 + '\0';
//        if (prev[0] == 'A')
//            prev = '14' + '\0';
//        if (post[0] == '2')
//            post[0] = '15' + '\0';
//        if (post[0] == 'A')
//            post = '14' + '\0';
//        return prev[0] > post[0] ? prev : post;
//    }
//
//    if (prev.size() == 3)
//    {
//        if (prev[0] == '2')
//            prev[0] = 15 + '\0';
//        if (prev[0] == 'A')
//            prev = '14' + '\0';
//        if (post[0] == '2')
//            post[0] = '15' + '\0';
//        if (post[0] == 'A')
//            post = '14' + '\0';
//        return prev[0] > post[0] ? prev : post;
//    }
//    if (prev.size() == 4)
//    {
//        if (prev[0] == '2')
//            prev[0] = 15 + '\0';
//        if (prev[0] == 'A')
//            prev = '14' + '\0';
//        if (post[0] == '2')
//            post[0] = '15' + '\0';
//        if (post[0] == 'A')
//            post = '14' + '\0';
//        return prev[0] > post[0] ? prev : post;
//    }
//    if (prev.size() == 5 && (prev[0] == 'j' || prev[0] == 'J'))
//    {
//        return prev[0] < post[0] ? prev : post;
//    }
//    else if (prev.size() == 5)
//    {
//        return prev[3] > post[3] ? prev : post;
//    }
//
//}
//
//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        cout << compare(str) << endl;
//    }
//    return 0;
//}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string tb = "345678910JQKA2jokerJOKER";
    string s;
    while (getline(cin, s))
    {
        int idx = s.find('-');
        string t1 = s.substr(0, idx);
        string t2 = s.substr(idx + 1);
        int c1 = count(t1.begin(), t1.end(), ' ');
        int c2 = count(t2.begin(), t2.end(), ' ');
        if (c1 != c2) {
            if (t1 == "joker JOKER" || t2 == "joker JOKER") {
                cout << "joker JOKER" << endl;
            }
            else if (c1 == 3) {
                cout << t1 << endl;
            }
            else if (c2 == 3) {
                cout << t2 << endl;
            }
            else {
                cout << "ERROR" << endl;
            }
        }
        else {
            string s1 = t1 + ' ', s2 = t2 + ' ';
            s1 = s1.substr(0, s1.find(' '));
            s2 = s2.substr(0, s2.find(' '));
            int i1 = tb.find(s1);
            int i2 = tb.find(s2);
            if (i1 > i2) {
                cout << t1 << endl;
            }
            else {
                cout << t2 << endl;
            }
        }
    }
    return 0;
}
