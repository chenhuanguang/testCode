//#include<iostream>
//
////解决命名冲突
//namespace CHG
//{
//	int a = 10;
//	int b = 20;
//	int Add(int num1, int num2)
//	{
//		return num1 + num2;
//	}
//
//	int Sub(int num1, int num2)
//	{
//		return num1 - num2;
//	}
//}
//
////1、指定命名空间
////2、展开命名空间->缺点：整个暴露出来，失去隔离效果 项目部推荐，日常联系推荐使用
////using namespace CHG;
//
////3、指定展开
//using CHG::Sub;
//int main()
//{
//	int res = CHG::Add(1, 1);
//	int res2 = CHG::Sub(2, 1);
//	//int res = Add(1, 1); //指定展开不可用
//	//int res2 = Sub(2, 1);可用
//	printf("%d \n", res);
//	printf("%d \n", res2);
//
//	return 0;
//}

#include<iostream> //IO流头文件
using namespace std;//std是C++库的namespace

int main()
{
	cout << "hello world!!!" << endl;

	int a = 1;
	double d = 1.11;
	printf("%d,%0.2f\n", a, d);
	//不需要指定类型格式，自动识别格式，而且更加形象
	cout << a << "," << d << endl;
	
	return 0;
}