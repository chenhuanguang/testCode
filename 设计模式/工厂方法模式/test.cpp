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
		cout << "Huawei Phone" << endl;
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

//抽象工厂
class AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone() = 0;
};

//华为工厂
class HuaweiFactory : public AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new Huawei();
	}
};

//小米工厂
class XiaomiFactory : public AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new Xiaomi();
	}
};

//苹果工厂
class AppleFactory : public AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new Apple();
	}
};

void test()
{
	//创建一个工厂
	AbstractPhoneFactory* factory = nullptr;
	//创建一个手机
	AbstractPhone* phone = nullptr;

	//指定工厂是华为工厂
	factory = new HuaweiFactory;
	//通过华为工厂创建一个手机
	phone = factory->CreatePhone();
	phone->ShowName();

	delete phone;
	delete factory;

	factory = new XiaomiFactory;
	phone = factory->CreatePhone();
	phone->ShowName();

	delete phone;
	delete factory;

	factory = new AppleFactory;
	phone = factory->CreatePhone();
	phone->ShowName();

	delete phone;
	delete factory;
}

int main()
{
	test();
	return 0;
}