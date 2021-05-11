#include <iostream>
#include <string>
using namespace std;



//bool isBLetter(const char& ch)
//{
//    return ch >= 'A' && ch <= 'Z';
//}
//
//bool isSLetter(const char& ch)
//{
//    return ch >= 'a' && ch <= 'z';
//}
//
//bool isF(const char& ch)
//{
//    if (ch >= 33 && ch <= 47)
//        return true;
//    else if (ch >= 58 && ch <= 64)
//        return true;
//    else if (ch >= 91 && ch <= 96)
//        return true;
//    else if (ch >= 123 && ch <= 126)
//        return true;
//    return false;
//}
//
//int main()
//{
//    string passwd;
//    while (getline(cin, passwd))
//    {
//        int bcNum = 0;
//        int scNum = 0;
//        int dNum = 0;
//        int fNum = 0;
//        int sum = 0;
//        for (int i = 0; i < passwd.size(); ++i)
//        {
//            if (isBLetter(passwd[i]))
//                ++bcNum;
//            else if (isSLetter(passwd[i]))
//                ++scNum;
//            else if (isdigit(passwd[i]))
//                ++dNum;
//            else if (isF(passwd[i]))
//                ++fNum;
//        }
//
//        if (passwd.size() <= 4)
//            sum += 5;
//        else if (passwd.size() > 4 && passwd.size() <= 7)
//            sum += 10;
//        else if (passwd.size() >= 8)
//            sum += 25;
//
//        if ((bcNum >= 1 && scNum == 0) || (bcNum == 0 && scNum >= 1))
//            sum += 10;
//        else if (bcNum >= 1 && scNum >= 1)
//            sum += 20;
//
//        if (dNum == 1)
//            sum += 10;
//        else if (dNum > 1)
//            sum += 20;
//
//        if (fNum == 1)
//            sum += 10;
//        else if (fNum > 1)
//            sum += 25;
//
//        /*if ((bcNum >= 1 ||scNum >=1) && dNum >=1 && fNum == 0)
//            sum+=2;
//        else if (bcNum >= 1 && scNum >=1 && dNum >=1 && fNum >= 1)
//            sum += 5;
//        else if ((bcNum >= 1 ||scNum >=1) && dNum >=1 && fNum >= 1)
//            sum+=3;*/
//        if (bcNum >= 1 && scNum >= 1 && dNum >= 1 && fNum >= 1)
//            sum += 5;
//        else if ((bcNum >= 1 && scNum == 0) || (bcNum == 0 && scNum >= 1)) && dNum >= 1 && fNum >= 1)
//        sum += 3;
//        else if ((bcNum >= 1 && scNum == 0) || (bcNum == 0 && scNum >= 1)) && dNum >= 1 && fNum == 0)
//        sum += 2;
//
//        if (sum >= 90)
//            cout << "VERY_SECURE" << endl;
//        else if (sum >= 80)
//            cout << "SECURE" << endl;
//        else if (sum >= 70)
//            cout << "VERY_STRONG" << endl;
//        else if (sum >= 60)
//            cout << "STRONG" << endl;
//        else if (sum >= 50)
//            cout << "AVERAGE" << endl;
//        else if (sum >= 25)
//            cout << "WEAK" << endl;
//        else
//            cout << "VERT_WEAK" << endl;
//    }
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	printf("%%%%\n");
//	return 0;
//}

//void func(const char** m) {
//	++m;
//	cout << **m << endl;
//}
//int main() {
//	const static char* a[] = { "morning", "afternoon", "evening" };
//	//cout << a[0][0] << endl;
//	//const char* s = "haha";
//	//cout << s << endl;
//	const char** p;
//	p = a;
//	func(p);
//	return 0;
//}