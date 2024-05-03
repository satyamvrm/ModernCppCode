#include<iostream>
class Dummy{
    private:
    public:
    Dummy() noexcept {
    }
    void Display() noexcept {

        std::cout<<"Hello\n";
        // std::cout<<10/0;
        return 0;
    }
};
int main(){
    Dummy obj;
    obj.Display();
}