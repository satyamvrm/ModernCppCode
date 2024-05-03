#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <cstring>
#include <future>

class Exception : std::exception
{
private:
    /* data */
    char *_msg;

public:
    Exception() = delete;
    Exception(const Exception &) = delete;
    Exception(Exception &&) = delete;
    Exception &operator=(const Exception &) = delete;
    Exception &operator=(Exception &&) = delete;
    ~Exception() { delete[] _msg; }

    Exception(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    virtual const char *
    what() const noexcept { return _msg; };
};

#endif // EXCEPTION_H
