#ifndef IdNotFoundException_H
#define IdNotFoundException_H

#include <stdexcept>
#include <cstring>

class IdNotFoundException : public std::exception
{
private:
    /* data */
    char *_msg;

public:
    IdNotFoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    ~IdNotFoundException()
    {
        delete _msg;
    }
    virtual const char * what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }

    IdNotFoundException(/* args */) = delete;
    IdNotFoundException(IdNotFoundException &&) = default;
    IdNotFoundException &operator=(const IdNotFoundException &) = delete;
    IdNotFoundException &&operator=(IdNotFoundException &&) = delete;
};

#endif // IdNotFoundException_H
