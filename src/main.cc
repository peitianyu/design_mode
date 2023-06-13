#include<iostream>
#include<memory>
#include<map>
#include<functional>

class Factory
{
public:
    static Factory &getInstance(){
        static Factory instance;
        return instance;
    }

    void registerObject(const std::string &name, std::function<void *(std::string, size_t)> constructor){
        m_map[name] = constructor;
    }

    void *createObject(const std::string &name, const std::string &topic, size_t max_size)
    {
        auto it = m_map.find(name);
        if (it != m_map.end())
            return it->second(topic, max_size);
        return nullptr;
    }

private:
    Factory() {}
    Factory(const Factory &) = delete;
    Factory &operator=(const Factory &) = delete;

    std::map<std::string, std::function<void *(std::string, size_t)>> m_map;
};

class Register
{
public:
    Register(const std::string &name, std::function<void *(std::string, size_t)> constructor)
    {
        Factory::getInstance().registerObject(name, constructor);
    }
};

template<typename T>
class Helper
{
public:
    Helper(const std::string &name)
    {
        m_register = std::make_unique<Register>(name, createObject);
    }

    static void *createObject(std::string topic, size_t max_size)
    {
        return new T(topic, max_size);
    }

private:
    std::unique_ptr<Register> m_register;
};

#define REGISTER(T, name) \
    Helper<T> g_helper_##T(name);


class Publisher
{
public:
    Publisher(std::string topic, size_t max_size)
    {
        std::cout << "A" << std::endl;
    }
};

class Subscriber
{
public:
    Subscriber(std::string topic, size_t max_size)
    {
        std::cout << "B" << std::endl;
    }
};

REGISTER(Publisher, "Publisher")
REGISTER(Subscriber, "Subscriber")

int main()
{
    Factory::getInstance().createObject("Publisher", "topic", 10);
    Factory::getInstance().createObject("Subscriber", "topic", 10);
    return 0;
}
