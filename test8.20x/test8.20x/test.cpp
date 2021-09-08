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
 * 注：本程序在x86机器上使用g++ 或者 cl 编译运行
 * Q1: 本程序的输出是什么？
* Q2: 指针变量a、b存储在哪里？a、b指针指向的对象存储在哪里？
 * Q3：a指向的对象，占用多少内存空间？b指向的对象占用多少内存空间？
* Q4：a对象的内存布局是怎么样的？b对象的内存布局是怎么样的？
 * Q5：如果把Child的run函数设置为private，会影响多态吗？
 * Q6：为什么一般要把基类析构函数定义为虚函数？
 * Q7：如果析构函数抛出异常，会有什么问题？
 * Q8：如果我不希望Child被拷贝、被赋值，有什么方式可以做到？  */