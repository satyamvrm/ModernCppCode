#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H


//Just an example to see how unique ptr works and works only 2/10 times 
template <typename T>
class uniquePtr
{
private:
    T* _mptr;

public:
    uniquePtr(T* ptr) : _mptr{ptr} {
        ptr = nullptr;
    }
    
    uniquePtr(const T*&) = delete;
    uniquePtr& operator=(const T*&) = delete;

    
    uniquePtr(const T*&) = default;
    uniquePtr& operator=(const T*&) = default;

    void release(){delete _mptr; _mptr=nullptr;}
    
    ~uniquePtr(){ delete _mptr; _mptr=nullptr;}

};


#endif // UNIQUEPTR_H
