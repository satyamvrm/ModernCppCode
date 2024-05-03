#ifndef EmptyContainerException_H
#define EmptyContainerException_H

#include<future>

#include<cstring>

class EmptyContainerException : public std::future_error
{
private:
    char* _msg;
public:
    EmptyContainerException(const char* msg, std::future_errc ec) : std::future_error(ec) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    EmptyContainerException() = delete;
    EmptyContainerException(const EmptyContainerException&) = delete;
    EmptyContainerException(EmptyContainerException&&) = default;
    EmptyContainerException& operator = (const EmptyContainerException&) = delete;
    EmptyContainerException&& operator = (EmptyContainerException&&) = delete;
    // ~EmptyContainerException() = default;
    ~EmptyContainerException() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // EmptyContainerException_H
