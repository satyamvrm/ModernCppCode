#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <stdexcept>
#include <cstring>
class EmptyContainerException : public std::exception
{
private:
    char *_msg;

public:
    EmptyContainerException() = delete;
    EmptyContainerException(EmptyContainerException &) = delete;
    EmptyContainerException &operator=(EmptyContainerException &) = delete;
    EmptyContainerException(EmptyContainerException &&) = delete;
    EmptyContainerException &operator=(EmptyContainerException &&) = delete;
    ~EmptyContainerException() { delete[] _msg; }
    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
    EmptyContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H
