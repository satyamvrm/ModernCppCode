#ifndef ENGINE_H
#define ENGINE_H
#include <ostream>

class Engine
{
private:
    int hp;
    int cc;

public:
    // default constructor disabled
    Engine() = delete;
    // default copy constructor disabled
    Engine(const Engine &) = delete;
    // default move constructor disabled
    Engine(const Engine &&) = delete;
    // default assignment operator disabled
    Engine &operator=(const Engine &) = delete;
    // default move operator disabled
    Engine &operator=(const Engine &&) = delete;
    // default distructor enabled
    ~Engine() = default;

    Engine(int h, int c)
    {
        hp = h;
        cc = c;
    }

    int getCc() const { return cc; }
    void setCc(int cc_) { cc = cc_; }

    int getHp() const { return hp; }
    void setHp(int hp_) { hp = hp_; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
