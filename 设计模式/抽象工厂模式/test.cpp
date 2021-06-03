#include <iostream>
using namespace std;

//抽象手机
class AbstractPhone
{
public:
	virtual void ShowName() = 0;
};
//华为手机
class HuaweiPhone : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "华为手机" << endl;
	}
};
//小米手机
class XiaomiPhone : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "小米手机" << endl;
	}
};
//苹果手机
class ApplePhone : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "苹果手机" << endl;
	}
};
//抽象耳机
class AbstractHeadset
{
public:
	virtual void ShowName() = 0;
};

//华为耳机
class HuaweiHeadset : public AbstractHeadset
{
public:
	virtual void ShowName()
	{
		cout << "华为耳机" << endl;
	}
};

//小米耳机
class XiaomiHeadset : public AbstractHeadset
{
public:
	virtual void ShowName()
	{
		cout << "小米耳机" << endl;
	}
};

//苹果耳机
class AppleHeadset : public AbstractHeadset
{
public:
	virtual void ShowName()
	{
		cout << "小苹果耳机" << endl;
	}
};

//抽象电脑
class AbstractComputer
{
public:
	virtual void ShowName() = 0;
};

//华为电脑
class HuaweiComputer : public AbstractComputer
{
public:
	virtual void ShowName()
	{
		cout << "华为电脑" << endl;
	}
};

//小米电脑
class XiaomiComputer : public AbstractComputer
{
public:
	virtual void ShowName()
	{
		cout << "小米电脑" << endl;
	}
};

//苹果电脑
class AppleComputer : public AbstractComputer
{
public:
	virtual void ShowName()
	{
		cout << "苹果电脑" << endl;
	}
};

//抽象工厂 针对产品族
class AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone() = 0;
	virtual AbstractHeadset* CreateHeadset() = 0;
	virtual AbstractComputer* CreateComputer() = 0;

};
//华为工厂
class HuaweiFactory : public AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new HuaweiPhone();
	}
	virtual AbstractHeadset* CreateHeadset()
	{
		return new HuaweiHeadset();
	}
	virtual AbstractComputer* CreateComputer()
	{
		return new HuaweiComputer();
	}
};

//小米工厂
class XiaomiFactory : public AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new XiaomiPhone();
	}
	virtual AbstractHeadset* CreateHeadset()
	{
		return new XiaomiHeadset();
	}
	virtual AbstractComputer* CreateComputer()
	{
		return new XiaomiComputer();
	}
};

//苹果工厂
class AppleFactory : public AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new ApplePhone();
	}
	virtual AbstractHeadset* CreateHeadset()
	{
		return new AppleHeadset();
	}
	virtual AbstractComputer* CreateComputer()
	{
		return new AppleComputer();
	}
};

void test()
{
	//创建一个工厂
	AbstrackFactory* factory = nullptr;
	//创建产品
	AbstractPhone* phone = nullptr;
	AbstractHeadset* headset = nullptr;
	AbstractComputer* computer = nullptr;

	//指定该工厂是华为工厂
	factory = new HuaweiFactory();
	//通过华为工厂创建的产品
	phone = factory->CreatePhone();
	headset = factory->CreateHeadset();
	computer = factory->CreateComputer();
	
	phone->ShowName();
	headset->ShowName();
	computer->ShowName();

	delete phone;
	delete headset;
	delete computer;
	delete factory;
}

int main()
{
	test();
	return 0;
}