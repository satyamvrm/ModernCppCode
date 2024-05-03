#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H
#include <stdexcept>
#include<cstring>
class customException : public std::exception
{
private:
     char *_msg;

public:
    customException() = delete;
    customException(customException &) = delete;
    customException &operator=(customException &) = delete;
    customException(customException &&) = delete;
    customException &operator=(customException &&) = delete;
    ~customException() { delete[] _msg; }

    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }

    customException(const char* msg){
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
};

#endif // CUSTOMEXCEPTION_H
