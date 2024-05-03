#ifndef EMPTYDATA_H
#define EMPTYDATA_H

#include <stdexcept>
#include<cstring>
class EmptyData : public std::exception
{
private:
     char *_msg;
public:
    EmptyData() = delete;
    EmptyData(EmptyData &) = delete;
    EmptyData &operator=(EmptyData &) = delete;
    EmptyData(EmptyData &&) = delete;
    EmptyData &operator=(EmptyData &&) = delete;
    ~EmptyData() { delete[] _msg; }
    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
    EmptyData(const char* msg){
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
};

#endif // EMPTYDATA_H
