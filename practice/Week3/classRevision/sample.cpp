#include <iostream>
#include <memory>
#include <functional>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <variant>
#include <vector>
#include <optional>

std::mutex mt;

class A
{
private:
    int _a;
    std::string _name;

public:
    A() = delete;
    ~A() = default;

    A(int a, std::string name) : _a{a}, _name{name} {}
    int a() const { return _a; }

    std::string name() const { return _name; }

    friend std::ostream &operator<<(std::ostream &os, const A &rhs)
    {
        os << "_a: " << rhs._a
           << " _name: " << rhs._name;
        return os;
    }
};

class B
{
private:
    int _b;
    std::string _name;

public:
    B() = delete;
    ~B() = default;

    B(int a, std::string name) : _b{a}, _name{name} {}
    int b() const { return _b; }

    std::string name() const { return _name; }

    friend std::ostream &operator<<(std::ostream &os, const B &rhs)
    {
        os << "_b: " << rhs._b
           << " _name: " << rhs._name;
        return os;
    }
};

class MainData
{
private:
    std::variant<std::shared_ptr<A>, std::shared_ptr<B>> _data;

public:
    MainData() = delete;
    ~MainData() = default;
    MainData(std::variant<std::shared_ptr<A>, std::shared_ptr<B>> data) : _data{std::move(data)} {}

    std::variant<std::shared_ptr<A>, std::shared_ptr<B>> data() const { return _data; }

    friend std::ostream &operator<<(std::ostream &os, const MainData &rhs)
    {
        std::visit([&](auto &&args)
                   { os << *args << '\n'; },
                   rhs._data);
        return os;
    }
};

auto createObjects = [](std::vector<std::shared_ptr<MainData>> &data)
{
    data.push_back(std::make_shared<MainData>(std::make_shared<A>(10, "A")));
    data.push_back(std::make_shared<MainData>(std::make_shared<B>(11, "B")));
    data.push_back(std::make_shared<MainData>(std::make_shared<A>(12, "A")));
    data.push_back(std::make_shared<MainData>(std::make_shared<B>(13, "B")));
};

auto displayObjects = [](std::vector<std::shared_ptr<MainData>> &data)
{
    for (auto m : data)
    {
        std::cout << *m.get();
    }
};

auto CountUncommon = [](std::vector<std::shared_ptr<MainData>> &data)
{
    int countA{0}, countB{0};
    std::cout << "\n\nUsing CountUncommonFunction \n\n";
    for (auto m : data)
    {
        if (std::holds_alternative<std::shared_ptr<A>>(m->data()))
        {
            std::lock_guard<std::mutex> lg(mt);
            std::shared_ptr<A> temp = std::get<0>(m->data());
            std::cout << *temp << '\n';
            countA++;
        }
        else
        {
            std::lock_guard<std::mutex> lg(mt);
            std::shared_ptr<B> temp = std::get<1>(m->data());
            std::cout << *temp << '\n';
            countB++;
        }
    }
    std::cout << "Count of A :- " << countA << " Count of B :- " << countB << '\n';
};

std::optional<std::vector<std::string>> findName(std::vector<std::shared_ptr<MainData>> &data,std::string n)
{
    std::vector<std::string> names;
    std::cout << "\n\nUsing findName \n";
    for (auto m : data)
    {
        std::visit(
            [&](auto &&val)
            {
                if (val->name() == n)
                    names.push_back(val->name());
            },
            m->data());
    }
    if(names.empty()) {return std::nullopt;}
    return names;
};

int main()
{
    std::vector<std::shared_ptr<MainData>> data;
    std::thread createObjectThread(createObjects, std::ref(data));
    if (createObjectThread.joinable())
        createObjectThread.join();

    std::thread t1(displayObjects, std::ref(data));
    std::thread t2(CountUncommon, std::ref(data));

    t1.join();
    t2.join();

    


    std::optional<std::vector<std::string>> ans = findName(data,"A");
    if(ans.has_value()){
        for(auto a : ans.value()){
            std::cout<<a<<" ";
        }
    }else{
        std::cerr<<"Empyt Data\n";
    }
}