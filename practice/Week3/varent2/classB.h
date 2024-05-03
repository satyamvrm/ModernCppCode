#ifndef CLASSB_H
#define CLASSB_H

class classB
{
private:
    /* data */
    int b;
    int common;
public:
    classB(/* args */) {}
    ~classB() {}

    int getCommon() const { return common; }
    void setCommon(int common_) { common = common_; }

    int getB() const { return b; }
    void setB(int b_) { b = b_; }

    classB(int x, int y) : b{x},common{y}{}

};

#endif // CLASSB_H
