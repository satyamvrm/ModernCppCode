#ifndef BatteryCapacityExceed_H
#define BatteryCapacityExceed_H

#include<stdexcept>
#include<cstring>

class BatteryCapacityExceed : public std::exception
{
private:
    char* _msg;
public:
    BatteryCapacityExceed(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    BatteryCapacityExceed() = delete;
    BatteryCapacityExceed(const BatteryCapacityExceed&) = delete;
    BatteryCapacityExceed(BatteryCapacityExceed&&) = default;
    BatteryCapacityExceed& operator = (const BatteryCapacityExceed&) = delete;
    BatteryCapacityExceed&& operator = (BatteryCapacityExceed&&) = delete;
    // ~BatteryCapacityExceed() = default;
    ~BatteryCapacityExceed() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // BatteryCapacityExceed_H
