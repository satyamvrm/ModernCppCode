#ifndef TEST_H
#define TEST_H

#include <stdexcept>
#include <cstring>
class test : public std::exception
{
private:
    char *_msg;

public:
    test() = delete;
    test(test &) = delete;
    test &operator=(test &) = delete;
    test(test &&) = delete;
    test &operator=(test &&) = delete;
    ~test() { delete[] _msg; }
    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
    test(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
};

#endif // TEST_H
