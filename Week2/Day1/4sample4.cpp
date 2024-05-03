#include<iostream>

class LambdaImplementation{
    private:
        // int _number;  //to be discussed
    public:
        LambdaImplementation() = default;
        ~LambdaImplementation() = default;

        //function call () operator{paren paren}
        void operator()(int num){
            std::cout<<"Square of : " << num << " -> " << num*num <<'\n';
        }
};

int main(){
    LambdaImplementation l1;
    l1(3);
    return 0;
}