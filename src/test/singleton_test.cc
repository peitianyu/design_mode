#include"core/tt_test.h" 

class TestSingleton
{
public:
    static TestSingleton &GetInstance()
    {
        static TestSingleton instance;
        return instance;
    }

    TestSingleton(const TestSingleton &) = delete;
    TestSingleton &operator=(const TestSingleton &) = delete;

    void Print()
    {
        std::cout << "TestSingleton::Print()" << std::endl;
    }
private:
    TestSingleton() = default;
    ~TestSingleton() = default;
};

// 单例模式一般在全局都需要使用的情况下, 比如日志, 配置文件, 数据可视化等
JUST_RUN_TEST(singleton, test)
TEST(singleton, test)
{
    TestSingleton::GetInstance().Print();
}
