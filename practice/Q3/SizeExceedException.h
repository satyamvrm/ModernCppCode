#ifndef SizeExceedException_H
#define SizeExceedException_H

#include<stdexcept>
#include<cstring>

class SizeExceedException : public std::exception
{
private:
    char* _msg;
public:
    SizeExceedException(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    SizeExceedException() = delete;
    SizeExceedException(const SizeExceedException&) = delete;
    SizeExceedException(SizeExceedException&&) = default;
    SizeExceedException& operator = (const SizeExceedException&) = delete;
    SizeExceedException&& operator = (SizeExceedException&&) = delete;
    // ~SizeExceedException() = default;
    ~SizeExceedException() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // SizeExceedException_H
