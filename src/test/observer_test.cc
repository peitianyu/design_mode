#include "core/tt_test.h"

#include <iostream>
#include <vector>
#include <algorithm>

// 观察者接口
class Observer {
public:
    virtual void update() = 0; // 观测主要通过这部分实现
};

// 具体观察者类
class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "Received notification from subject." << std::endl;
        // 执行相应操作
    }
};

// 主题类
class Subject {
private:
    std::vector<Observer*> observers; // 观察者列表

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // 从观察者列表中移除观察者
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() {
        // 通知所有观察者
        for (auto observer : observers) {
            observer->update();
        }
    }
};

// 主题类包含了观察者列表, 通过attach和detach来添加和移除观察者, 通过notify来通知所有观察者
// 观察者与被观察者之间是松耦合的, 通过接口来实现, 从而实现了观察者模式
JUST_RUN_TEST(observer, test)
TEST(observer, test)
{
    Subject subject;
    ConcreteObserver observer;
    subject.attach(&observer);
    subject.notify();
    subject.detach(&observer);
}