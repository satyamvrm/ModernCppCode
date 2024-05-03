#ifndef TypeNotFound_H
#define TypeNotFound_H

#include<stdexcept>
#include<cstring>

class TypeNotFound : public std::exception
{
private:
    char* _msg;
public:
    TypeNotFound(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    TypeNotFound() = delete;
    TypeNotFound(const TypeNotFound&) = delete;
    TypeNotFound(TypeNotFound&&) = default;
    TypeNotFound& operator = (const TypeNotFound&) = delete;
    TypeNotFound&& operator = (TypeNotFound&&) = delete;
    // ~TypeNotFound() = default;
    ~TypeNotFound() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // TypeNotFound_H
