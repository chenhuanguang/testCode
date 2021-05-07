#include<iostream>
using namespace std;

//抽象产生--手机
class Phone
{
public:
	//产品业务--听音乐
	virtual void listenMusic() = 0;
};
//抽象产品--电脑
class Computer
{
public:
	//产品业务--打游戏
	virtual void playGame() = 0;
};

//抽象工厂
class Factory
{
public:
	//生成抽象产品--生成手机
	virtual Phone* createPhone() = 0;
	//生成抽象产品--生成电脑
	virtual Computer* createComputer() = 0;
};

//具体产品--华为手机
class HuaweiPhone : public Phone
{
public:
	//重写抽象产品中的业务方法
	virtual void listenMusic()
	{
		cout << "拿着华为手机听音乐" << endl;
	}
};
//具体产品--华为电脑
class HuaweiComputer : public Computer
{	
public:
	//重写抽象产品中的业务方法
	virtual void playGame()
	{
		cout << "拿着华为电脑打游戏" << endl;
	}
};
//具体产品--苹果手机
class ApplePhone : public Phone
{
public:
	//重写抽象产品中的业务方法
	virtual void listenMusic()
	{
		cout << "拿着苹果手机听音乐" << endl;
	}
};
//具体产品--苹果电脑
class AppleComputer : public Computer
{
public:
	//重写抽象产品中的业务方法
	virtual void playGame()
	{
		cout << "拿着华为电脑打游戏" << endl;
	}
};
//具体工厂--华为工厂
class HuaweiFactory : public Factory
{
public:
	//重写抽象工厂中的生产手机
	virtual Phone* createPhone()
	{
		return new HuaweiPhone();
	}
	//重写抽象工厂中的生产电脑
	virtual Computer* createComputer()
	{
		return new HuaweiComputer();
	}
};
//具体工厂--苹果工厂
class AppleFactory : public Factory
{
public:
	//重写抽象工厂中的生产手机
	virtual Phone* createPhone()
	{
		return new ApplePhone();
	}
	//重写抽象工厂中的生产电脑
	virtual Computer* createComputer()
	{
		return new AppleComputer();
	}
};

int main()
{
	//创建华为工厂
	Factory* huaweiFactory = new HuaweiFactory();
	//华为工厂生产手机
	Phone* huaweiPhone = huaweiFactory->createPhone();
	//华为的手机听音乐
	huaweiPhone->listenMusic();
	//华为工厂生产电脑
	Computer* huaweiComputer = huaweiFactory->createComputer();
	//华为的电脑打游戏
	huaweiComputer->playGame();

	//创建苹果工厂
	Factory* appleFactory = new AppleFactory();
	//苹果工厂生产手机
	Phone* applePhone = appleFactory->createPhone();
	//苹果的手机听音乐
	applePhone->listenMusic();
	//苹果工厂生产电脑
	Computer* appleComputer = appleFactory->createComputer();
	//苹果的电脑打游戏
	appleComputer->playGame();
	return 0;
}
////连接抽象类 
//class Connection
//{
//public:
//	virtual void connection() = 0;
//};
//
////语句抽象类 
//class Statement
//{
//public:
//	virtual void statement() = 0;
//};
//
////抽象工厂
//class DBFactory
//{
//public:
//	virtual Connection* createConnection() = 0;
//	virtual Statement* createStatement() = 0;
//};
//
////oracle的连接 
//class OracleConnection : public Connection
//{
//public:
//	virtual void connection()
//	{
//		cout << "Oracle数据库的连接" << endl;
//	}
//};
//
////oracle的语句 
//class OracleStatement : public Statement
//{
//public:
//	virtual void statement()
//	{
//		cout << "Oracle数据库的语句" << endl;
//	}
//};
//
////mysql的连接 
//class MySQLConnection : public Connection
//{
//public:
//	virtual void connection()
//	{
//		cout << "MySQL数据库的连接" << endl;
//	}
//};
//
////mysql的语句 
//class MySQLStatement : public Statement
//{
//public:
//	virtual void statement()
//	{
//		cout << "MySQL数据库的语句" << endl;
//	}
//};
//
////oracle工厂 
//class OracleFactory : public DBFactory
//{
//	virtual Connection* createConnection()
//	{
//		return new OracleConnection();
//	}
//	virtual Statement* createStatement()
//	{
//		return new OracleStatement();
//	}
//};
//
////mysql工厂 
//class MySQLFactory : public DBFactory
//{
//	virtual Connection* createConnection()
//	{
//		return new MySQLConnection();
//	}
//	virtual Statement* createStatement()
//	{
//		return new MySQLStatement();
//	}
//};
//
//int main()
//{
//
//	DBFactory* oracleFactory = new OracleFactory();
//	Connection* oracleConnection = oracleFactory->createConnection();
//	oracleConnection->connection();
//	Statement* oracleStatement = oracleFactory->createStatement();
//	oracleStatement->statement();
//	delete oracleConnection;
//	delete oracleStatement;
//	delete oracleFactory;
//
//	DBFactory* mySQLFactory = new MySQLFactory();
//	Connection* mySQLConnection = mySQLFactory->createConnection();
//	mySQLConnection->connection();
//	Statement* mySQLStatement = mySQLFactory->createStatement();
//	mySQLStatement->statement();
//	delete mySQLStatement;
//	delete mySQLConnection;
//	delete mySQLFactory;
//	return 0;
//}
