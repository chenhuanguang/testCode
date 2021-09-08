#include <iostream>
#include <iostream>
using namespace std;

#include <iostream>
#include <string>

#pragma pack(4)
class Parent {
public:
    Parent() = default;
    virtual ~Parent() = default;

    virtual void run() {
        std::cout << "Parent:run" << std::endl;
    }
private:
    char a;
};

class Child : public Parent {
public:
    Child() = default;
    ~Child() = default;

public:
    virtual void run() {
        std::cout << "Child:run" << std::endl;
    }
private:
    int b;
};

int main(int argc, char** argv) {
    Parent* a = new Child;
    Parent* b = new Parent;
    Child* c = new Child;

    cout << sizeof(Child) << sizeof(Parent) << endl;

    a->run();
    b->run();
    c->run();

    delete c;
    delete b;
    delete a;
    return 0;
}

/*
 * ע����������x86������ʹ��g++ ���� cl ��������
 * Q1: ������������ʲô��
* Q2: ָ�����a��b�洢�����a��bָ��ָ��Ķ���洢�����
 * Q3��aָ��Ķ���ռ�ö����ڴ�ռ䣿bָ��Ķ���ռ�ö����ڴ�ռ䣿
* Q4��a������ڴ沼������ô���ģ�b������ڴ沼������ô���ģ�
 * Q5�������Child��run��������Ϊprivate����Ӱ���̬��
 * Q6��Ϊʲôһ��Ҫ�ѻ���������������Ϊ�麯����
 * Q7��������������׳��쳣������ʲô���⣿
 * Q8������Ҳ�ϣ��Child������������ֵ����ʲô��ʽ����������  */