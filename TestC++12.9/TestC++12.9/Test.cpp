//#include<iostream>
//using namespace std; //c++库中所有东西是放到stdd命名空间中
//
//int main()
//{
//	cout << "hello world"<<endl; 
//
//	return 0;
//}


//#include<iostream>
////using namespace std; //c++库中所有东西是放到std命名空间中
//
//int main()
//{
//	//自动识别类型
//	std::cout << "hello world"<<std::endl; 
//	int i = 1;
//	double d = 1.11;
//	std::cout << i <<" "<< d << std::endl;
//
//	return 0;
//}


//#include<iostream>
//using namespace std; //c++库中所有东西是放到std命名空间中
//
//int main()
//{
//	//自动识别类型
//	std::cout << "hello world"<<std::endl; 
//	int i = 1;
//	double d = 1.11;
//	cin >> i >> d;//键盘输入
//	std::cout << i <<" "<< d << std::endl;
//
//	return 0;
//}


//#include<iostream>
////using namespace std; //c++库中所有东西是放到std命名空间中
////大工程推荐这样子
//using std::cout;
//using std::endl;
//using std::cin;
//int main()
//{
//	//自动识别类型
//	std::cout << "hello world"<<std::endl; 
//	int i = 1;
//	double d = 1.11;
//	cin >> i >> d;//键盘输入
//	std::cout << i <<" "<< d << std::endl;
//
//	return 0;
//}


#include<iostream>
using namespace std;

////缺省参数 :全缺省+半缺省
////缺省必须是连续的，而且必须要从右往左
//
////void Fun1(int a, int b = 20 , int c )//错误！！！
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////}
//
//void Fun(int a = 5)
//{
//	cout << a << endl;
//}
//
//void Fun1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//void Fun2(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//Fun(10);//10
//	//Fun();//5
//	Fun1(1, 2);//1 2 30
//	Fun1();//10 20 30
//	Fun2(1);//1 20 30
//	Fun2(1, 2, 3);//1 2 3
//
//	return 0;
//}


//函数重载：函数名相同-> 参数不同（参数类型 or 参数个数 or 类型顺序不同）
//返回值不作要求
//只是返回值不同，不算重载，编译报错。
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//void Fun(int a, char c)
//{
//
//}
//void Fun(char c, int a)
//{
//
//}
//int main()
//{
////可以自动识别类型调用相对应的函数
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//
//	return 0;
//}


//1、引用必须在定义的时候初始化
//2、一个变量可以多次引用
//3、引用对象不能被改变
//4、引用类型必须一样
//5、变量之间赋值没有权限缩小和放大的关系，引用才有
int main()
{
	int a = 1;
	int& ra = a;//ra是a的引用，引用也就是别名，a再取了一个名称
	ra = 10;
	int& raa = ra;//raa的类型还是int
	raa = 20;
	int b = 2;
	raa = b;//将b的值赋值给raa

	const int c = 1;
	//int& rc = c; 编译不通过 原因：a只读,b的类型为可读可写 引用类型必须一样
	
	int e = 1;
	int& d = e; 
	const int& f = e; //e是可读可写 f变为只读
	e = 2;//ok
	//f = 3;error
	//总结：引用取别名时，变量访问的权限可以缩小，不能放大

	int i = 1;
	double db = i;//隐式类型装换
	//double& rdb = i; 编译不通过
	const double& rdb = i;//ok 通过临时变量进行引用  临时变量有常性(临时变量只可读)
	return 0;
}