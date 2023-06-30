#include "core/tt_test.h"

enum TYPE
{
    ONE,
    TWO,
    THREE
};

class Base
{
public:
    virtual ~Base() = default;

    virtual TYPE GetType() const = 0;

    virtual void Print() { std::cout << "Base" << std::endl; }
};

class One : public Base
{
public:
    TYPE GetType() const override { return ONE; }

    void Print() override { std::cout << "One" << std::endl; }
};

class Two : public Base
{
public:
    TYPE GetType() const override { return TWO; }

    void Print() override { std::cout << "Two" << std::endl; }
};

class Three : public Base
{
public:
    TYPE GetType() const override { return THREE; }

    void Print() override { std::cout << "Three" << std::endl; }
};

#include<map>

// 根据同一个基类的不同子类, 根据不同的类型, 执行不同的操作, 这里的GetType()用于获取当前所在的子类
// 使用map来存储不同的子类, 根据不同的类型来执行不同的操作
// JUST_RUN_TEST(strategy, test)
TEST(strategy, test)
{
    std::map<TYPE, Base*> m;
    m[ONE] = new One();
    m[TWO] = new Two();
    m[THREE] = new Three();

    m[ONE]->Print();
    m[TWO]->Print();
    m[THREE]->Print();

    delete m[ONE];
    delete m[TWO];
    delete m[THREE];
}