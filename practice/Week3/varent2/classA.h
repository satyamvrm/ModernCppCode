#ifndef CLASSA_H
#define CLASSA_H

class classA
{
private:
    /* data */
    int a;
    int common;
public:
    classA(/* args */) {}
    ~classA() {}

    int getA() const { return a; }
    void setA(int a_) { a = a_; }

    int getCommon() const { return common; }
    void setCommon(int common_) { common = common_; }

    classA(int x,int y):a{x},common{y}{}
};

#endif // CLASSA_H
