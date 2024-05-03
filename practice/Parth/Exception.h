#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <future>
#include <iostream>
#include <cstring>

class Exception : std::future_error
{
private:
    /* data */
    char *_msg;

public:
    Exception() = delete;
    Exception(Exception &) = delete;
    Exception(Exception &&) = delete;
    Exception &operator=(Exception &) = delete;
    Exception &operato(Exception &&) = delete;
    ~Exception() { delete[] _msg; }

    Exception(const char *msg, std::future_errc e) : std::future_error(e)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    virtual const char *
    what() const noexcept { return _msg; }

    const std::error_code &
    ErrorCode() const noexcept { return code(); }
};

#endif // EXCEPTION_H
