#include "core/tt_test.h"
#include "common/chain_of_responsibility.h"
#include <iostream>

class Responsibility1 : public design_patterns::ChainOfResponsibility
{
public:
    void SetNext(ChainOfResponsibility* next) override { next_ = next;}

    void HandleRequest() override {
        if(next_) {
            std::cout << "----handle request1!----" << std::endl;
            next_->HandleRequest();
        } else {
            std::cout << "----error!----" << std::endl;
        }
    }
private:
    ChainOfResponsibility* next_;
};

class Responsibility2 : public design_patterns::ChainOfResponsibility
{
public:
    void SetNext(ChainOfResponsibility* next) override { next_ = next;}

    void HandleRequest() override {
        if(next_) {
            std::cout << "----handle request2!----" << std::endl;
            next_->HandleRequest();
        } else {
            std::cout << "----error!----" << std::endl;
        }
    }
private:
    ChainOfResponsibility* next_;
};

class Responsibility3 : public design_patterns::ChainOfResponsibility
{
public:
    void SetNext(ChainOfResponsibility* next) override { next_ = next;}

    void HandleRequest() override {
        if(next_) {
            next_->HandleRequest();
        } else {
            std::cout << "----handle request3!----" << std::endl;
            std::cout << "chain_of_responsibility is end!" << std::endl;
        }
    }
private:
    ChainOfResponsibility* next_;
};


// 责任链模式, 该模式中每个类都有一个指向下一个类的指针, 从而形成一个链表, 从而实现了类似于递归的效果
// 这里实际上是需要加入一个观察者的角色用于实时观测所在状态
// JUST_RUN_TEST(chain_of_responsibility, test)
TEST(chain_of_responsibility, test)
{
    Responsibility1* r1 = new Responsibility1();
    Responsibility2* r2 = new Responsibility2();
    Responsibility3* r3 = new Responsibility3();

    r1->SetNext(r2);
    r2->SetNext(r3);

    r1->HandleRequest();

    delete r1;
    delete r2;
    delete r3;
}