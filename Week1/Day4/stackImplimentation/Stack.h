#ifndef STACK_H
#define STACK_H
#include <list>
#include "StackEmptyException.h"
template <typename T>
class Stack
{
private:
    std::list<T> _data{};

public:
    Stack() = default;
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    Stack(Stack &&) = default;
    Stack &operator=(Stack &&) = default;
    ~Stack() = default;

    // push function accept one item val of type T and returns void
    void Push(T val);
    //push even
    void PushEven(T val, int count);
    // pop function delete one element from the top
    void Pop();
    //peek will give the top element
    T Peek();
    //size will give the size of stack
    size_t Size();
    // isEmpty will check if the stack have elements or not
    bool isEmpty();
};

#endif // STACK_H

template <typename T>
inline void Stack<T>::Push(T val)
{
    _data.push_back(val);
}

template <typename T>
inline void Stack<T>::PushEven(T val, int count)
{
    for(int i=val;i<val+(count*2);i+=2)
        _data.push_back(i);
}

template <typename T>
inline void Stack<T>::Pop()
{
    if (_data.empty())
    {
        throw StackEmptyException("Stack is empty\n");
    }
    _data.pop_front();
}

template <typename T>
inline T Stack<T>::Peek()
{
    if (_data.empty())
    {
        throw StackEmptyException("Stack is Empty\n");
    }
    return _data.back();
}

template <typename T>
inline size_t Stack<T>::Size()
{
    return size_t();
}

template <typename T>
inline bool Stack<T>::isEmpty()
{
    return false;
}
