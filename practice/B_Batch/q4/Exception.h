#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <cstring>

class Exception : std::exception
{
private:
    /* data */
    char *_msg;

public:
    Exception(/* args */) = delete;
    ~Exception() { delete[] _msg; }
    Exception(const Exception &) = delete;
    Exception &operator=(const Exception &) = delete;
    Exception(Exception &&) = delete;
    Exception &operator=(Exception &&) = delete;

    Exception(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return _msg; }
};

#endif // EXCEPTION_H
