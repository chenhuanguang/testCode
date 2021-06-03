#include <iostream>
using namespace std;

//电视类
class Television
{
public:
	void On()
	{
		cout << "电视打开" << endl;
	}
	void Off()
	{
		cout << "电视关闭" << endl;
	}
};

//灯类
class Light
{
public:
	void On()
	{
		cout << "灯打开" << endl;
	}
	void Off()
	{
		cout << "灯关闭" << endl;
	}
};

//音响类
class Audio
{
public:
	void On()
	{
		cout << "音响打开" << endl;
	}
	void Off()
	{
		cout << "音响关闭" << endl;
	}
};

//麦克风类
class Microphone
{
public:
	void On()
	{
		cout << "麦克风打开" << endl;
	}
	void Off()
	{
		cout << "麦克风关闭" << endl;
	}
};

//dvd类
class DvdPlayer
{
public:
	void On()
	{
		cout << "DVD打开" << endl;
	}
	void Off()
	{
		cout << "DVD关闭" << endl;
	}
};



class KTVMode
{
public:
	KTVMode()
	{
		pTv = new Television;
		pLight = new Light;
		pAudio = new Audio;
		pMicrophone = new Microphone;
		pDvd = new DvdPlayer;
	}
	~KTVMode()
	{
		delete pTv;
		delete pLight;
		delete pAudio;
		delete pMicrophone;
		delete pDvd;
	}

	//打开ktv
	void OnKty()
	{
		pTv->On();
		pLight->Off();
		pAudio->On();
		pMicrophone->On();
		pDvd->On();
	}
	//关闭ktv
	void OffKty()
	{
		pTv->Off();
		pLight->On();
		pAudio->Off();
		pMicrophone->Off();
		pDvd->Off();
	}

private:
	Television* pTv;
	Light* pLight;
	Audio* pAudio;
	Microphone* pMicrophone;
	DvdPlayer* pDvd;
};

void test()
{
	KTVMode* ktv = new KTVMode();

	cout << "打开KTV模式" << endl;
	ktv->OnKty();
	cout << endl;
	cout << "关闭KTV模式" << endl;
	ktv->OffKty();
	
	delete ktv;
}

int main()
{
	test();
	return 0;
}