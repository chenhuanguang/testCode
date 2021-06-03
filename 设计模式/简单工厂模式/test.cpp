#include <iostream>
#include <string>
using namespace std;

//抽象手机
class AbstractPhone
{
public:
	virtual void ShowName() = 0;
};

//华为
class Huawei : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "Huawe Phone" << endl;
	}
};

//小米
class Xiaomi : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "Xiaomi Phone" << endl;
	}
};

//苹果
class Apple : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "Apple Phone" << endl;
	}
};

//手机工厂
class PhoneFactory
{
public:
	static AbstractPhone* CreatePhone(string name)
	{
		if (name == "huawei")
			return new Huawei;
		else if (name == "xiaomi")
			return new Xiaomi;
		else if (name == "apple")
			return new Apple;
		else
			return nullptr;
	}
};

void test()
{
	//创建工厂
	PhoneFactory* factor = new PhoneFactory;
	//创建手机
	AbstractPhone* phone;
	//指定工厂需要创建的手机
	phone = factor->CreatePhone("huawei");
	phone->ShowName();
	delete phone;

	phone = factor->CreatePhone("xiaomi");
	phone->ShowName();
	delete phone;

	phone = factor->CreatePhone("apple");
	phone->ShowName();
	delete phone;

	delete factor;
}

int main()
{
	test();
	return 0;
}