#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void test()
{
	string str;
	//cin >> str; //换行结束
	//getline(cin, str); //换行结束
	//输入WhirtShirtI
	getline(cin, str, 'S'); //White
	cout << str << endl;//White
}

//void test()
//{
//	//size_t find_first_of (const string& str, size_t pos = 0) const
//	string str = "abccba123abccba";
//	int pos = str.find_first_of("fbfc", 0, 2);//1
//	pos = str.find_last_of("fffb"); //13
//	pos = str.find_first_not_of("abc");//6
//	pos = str.find_last_not_of("abc");//8
//
//	string substr = str.substr(3, 3);//cba
//	//使用find与substr获得网站的域名
//	str = "https://blog.csdn.net/qq_44443986?spm=1011.2124.3001.5113";
//	int pos1 = str.find("://");
//	int pos2 = str.find("net");
//	substr = str.substr(pos1 + 3, pos2 - pos1);//blog.csdn.net
//}

//void test()
//{
//	char* c = new char[20];
//	string str = "abc";
//	strcpy(c, str.c_str()); //c:"abc\0"
//	string str2 = "123abc123abc";
//	int pos = str2.find(str, 1); //3
//	pos = str2.find("bc", 1);//4
//	pos = str2.find("bcd", 1, 3); //-1
//	pos = str2.find("bcd", 1, 2); //4
//	pos = str2.find('c', 0); //5
//
//	pos = str2.rfind(str);//9
//	pos = str2.rfind("bc");//10
//	pos = str2.rfind("bcd", str2.size(), 3); //-1
//	pos = str2.rfind('b'); // 10
//}

//void test()
//{
//	string str = "abc";
//	string str2 = "123";
//	str.replace(0, 1, str2);//123bc
//	str.replace(0, 1, str2, 0, 2);//1223bc
//	str.swap(str2); //str:123  str2:1223bc
//	str.pop_back();//12
//}

//void test()
//{
//	string str = "Hello WhiteShirtI";
//	str.erase(1, 2);//"Hlo WhiteShirtI"
//	str.erase(str.begin());//"lo WhiteShirtI"
//	str.erase(++str.begin(), --str.end());//"II"
//}

int main()
{
	test();

	return 0;
}