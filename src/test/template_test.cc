#include "core/tt_test.h"

class Base
{
public:
    virtual ~Base() = default;
    
    void func() {
        std::cout << "Base::func()" << std::endl;
    }

    virtual void func2() {
        std::cout << "Base::func2()" << std::endl;
    }
};

class Derived1 : public Base
{
public:
    void func2() override {
        std::cout << "Derived1::func2()" << std::endl;
    }
};

class Derived2 : public Base
{
public:
    void func2() override {
        std::cout << "Derived2::func2()" << std::endl;
    }
};

// 该模式中根据自己需要设计不同的func2()函数, 实际上再加上一个函数就变成了修饰器模式
// JUST_RUN_TEST(template, test)
TEST(template, test)
{
    Base* b = new Derived1();
    b->func();
    b->func2();

    b = new Derived2();
    b->func();
    b->func2();

    delete b;
}