#ifndef INVALIDENTRY_H
#define INVALIDENTRY_H
#include<stdexcept>
#include<cstring>

class InvalidEntry : public std::exception
{
private:
    char *_msg;

public:
    InvalidEntry() = delete;
    InvalidEntry(InvalidEntry &) = delete;
    InvalidEntry(InvalidEntry &&) = delete;
    InvalidEntry &operator=(InvalidEntry &) = delete;
    InvalidEntry &operator=(InvalidEntry &&) = delete;
    ~InvalidEntry()
    {
        delete []_msg;
    }

    InvalidEntry(const char* msg){
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};

#endif // INVALIDENTRY_H
