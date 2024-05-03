#ifndef INVALIDREGISTRATIONNUMBER_H
#define INVALIDREGISTRATIONNUMBER_H

#include <stdexcept>
#include<cstring>
class InvalidRegistrationNumber : public std::exception
{
private:
     char *_msg;
public:
    InvalidRegistrationNumber() = delete;
    InvalidRegistrationNumber(InvalidRegistrationNumber &) = delete;
    InvalidRegistrationNumber &operator=(InvalidRegistrationNumber &) = delete;
    InvalidRegistrationNumber(InvalidRegistrationNumber &&) = delete;
    InvalidRegistrationNumber &operator=(InvalidRegistrationNumber &&) = delete;
    ~InvalidRegistrationNumber() { delete[] _msg; }
    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
    InvalidRegistrationNumber(const char* msg){
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
};

#endif // INVALIDREGISTRATIONNUMBER_H
