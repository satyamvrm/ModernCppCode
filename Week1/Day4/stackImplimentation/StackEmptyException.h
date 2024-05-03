#ifndef STACKEMPTYEXCEPTION_H
#define STACKEMPTYEXCEPTION_H

#include <stdexcept>
#include <cstring>
class StackEmptyException : public std::exception
{
private:
    char *_msg;

public:
    StackEmptyException() = delete;
    StackEmptyException(const StackEmptyException &) = delete;
    StackEmptyException &operator=(const StackEmptyException &) = delete;
    StackEmptyException(const StackEmptyException &&) = delete;
    StackEmptyException &operator=(const StackEmptyException &&) = delete;
    ~StackEmptyException()
    {
        delete[] _msg;
    }

    explicit StackEmptyException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
};

#endif // STACKEMPTYEXCEPTION_H


/*
    pop 
    throw StackEmptyException("Data is Empty")
    [This calls constructor of custom exception class]
    |
    |
    obj of type custom exception
    {stored in catch table}
    [<objectname>.what() will return _msg]
*/