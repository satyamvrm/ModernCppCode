#ifndef EMPTYDATACONTAINEREXCEPTION_H
#define EMPTYDATACONTAINEREXCEPTION_H

#include <iostream>
#include <cstring>

class EmptyDataContainerException : std::exception
{
private:
    /* data */
    char *_msg;

public:
    EmptyDataContainerException() = delete;
    EmptyDataContainerException(const EmptyDataContainerException &) = delete;
    EmptyDataContainerException(EmptyDataContainerException &&) = delete;
    EmptyDataContainerException &operator=(const EmptyDataContainerException &) = delete;
    EmptyDataContainerException &operator=(EmptyDataContainerException &&) = delete;
    ~EmptyDataContainerException() { delete[] _msg; }

    EmptyDataContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
};

#endif // EMPTYDATACONTAINEREXCEPTION_H
