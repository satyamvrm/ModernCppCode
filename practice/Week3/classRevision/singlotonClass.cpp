/* #include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <array>
#include <functional>

class singlotonClass
{
private:
    int data;
    std::mutex mt;
    static singlotonClass *obj;
    singlotonClass(int val) : data{val} {}

public:
    singlotonClass() = delete;
    singlotonClass(singlotonClass &) = delete;
    singlotonClass(singlotonClass &&) = delete;
    singlotonClass &operator=(singlotonClass &) = delete;
    singlotonClass &operator=(singlotonClass &&) = delete;
    ~singlotonClass() = default;

    void add(int val)
    {
        std::lock_guard<std::mutex> lg{mt};
        data += val;
    }

    void subract(int val)
    {
        std::lock_guard<std::mutex> lg{mt};
        data -= val;
    }

    int getData() const { return data; }

    static singlotonClass *createObject(int val)
    {
        if (obj)
            return obj;
        else
        {
            obj = new singlotonClass(val);
            return obj;
        }
    }
};

singlotonClass *singlotonClass::obj{nullptr};

int main()
{
    singlotonClass *obj = singlotonClass::createObject(100);
    std::cout << obj->getData() << '\n';
    std::array<std::thread, 2> arrThread = {
        std::thread(&singlotonClass::add, obj, 5),
        std::thread(&singlotonClass::subract, obj, 15)};
    for (std::thread &t : arrThread)
        t.join();
    std::cout << obj->getData() << '\n';
} */

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <array>
#include <functional>

class singlotonClass
{
private:
    int data;
    std::mutex mt;
    static std::shared_ptr<singlotonClass> obj;
    singlotonClass(int val) : data{val} {}

public:
    singlotonClass() = delete;
    singlotonClass(const singlotonClass &) = delete;
    singlotonClass(singlotonClass &&) = delete;
    singlotonClass &operator=(const singlotonClass &) = delete;
    singlotonClass &operator=(singlotonClass &&) = delete;
    ~singlotonClass() = default;

    void add(int val)
    {
        std::lock_guard<std::mutex> lg{mt};
        data += val;
    }

    void subract(int val)
    {
        std::lock_guard<std::mutex> lg{mt};
        data -= val;
    }

    int getData() const { return data; }

    static std::shared_ptr<singlotonClass>& createObject(int val)
    {
        if (!obj)
            obj.reset(new singlotonClass(val));
        return obj;
    }
};

std::shared_ptr<singlotonClass> singlotonClass::obj{nullptr};

int main()
{
    std::shared_ptr<singlotonClass> obj = singlotonClass::createObject(100);
    std::cout << obj->getData() << '\n';
    std::array<std::thread, 2> arrThread = {
        std::thread(&singlotonClass::add, obj.get(), 5),
        std::thread(&singlotonClass::subract, obj.get(), 15)};
    for (std::thread &t : arrThread)
        t.join();
    std::cout << obj->getData() << '\n';
}
