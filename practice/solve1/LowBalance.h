#ifndef LOWBALANCE_H
#define LOWBALANCE_H
#include<stdexcept>
#include<cstring>

class LowBalance : public std::exception
{
private:
    char *_msg;

public:
    LowBalance() = delete;
    LowBalance(LowBalance &) = delete;
    LowBalance(LowBalance &&) = delete;
    LowBalance &operator=(LowBalance &) = delete;
    LowBalance &operator=(LowBalance &&) = delete;
    ~LowBalance()
    {
        delete[] _msg;
    }

    LowBalance(const char* msg){
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};

#endif // LOWBALANCE_H
