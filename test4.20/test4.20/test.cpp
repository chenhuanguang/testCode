#include<iostream>
#include <string>
using namespace std;

void Reverce(string& str, string* ret, int* idx)
{

    int sz = str.size();

    for (int i = 0; i < sz; ++i)
    {
        while (i < sz && str[i] != ' ')
        {
            ret[*idx] += str[i];
            ++i;
        }
        (*idx)++;
    }
}

int main()
{
    string str;
    getline(cin, str);
    string ret[50];
    int idx = 0;
    Reverce(str, ret, &idx);
    string result;
    for (int i = idx - 1; i >= 0; --i)
    {
        result += ret[i];
        result += ' ';
    }
    cout << result << endl;
    return 0;
}
//string* Reverce(string& str)
//{
//    string ret[50];
//    int sz = str.size();
//
//    for (int i = 0; i < sz; ++i)
//    {
//        while (i < sz && str[i] != ' ')
//        {
//            ret[idx] += str[i];
//            ++i;
//        }
//        ++idx;
//    }
//    return ret;
//}

//int main()
//{
//    string str;
//    getline(cin, str);
//    string ret[50];
//    int sz = str.size();
//
//    for (int i = 0; i < sz; ++i)
//    {
//        while (i < sz && str[i] != ' ')
//        {
//            ret[idx] += str[i];
//            ++i;
//        }
//        ++idx;
//    }
//    string result;
//    for (int i = idx - 1; i >= 0; --i)
//    {
//        result += ret[i];
//        result += ' ';
//    }
//    cout << result << endl;
//    return 0;
//}