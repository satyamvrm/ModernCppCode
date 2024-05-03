#include "Functionalities.h"

int main()
{
    auto binded = std::bind(fns1, std::placeholders::_1, "A101");
    Container data;
    InvoiceContainer data2;
    createObjects(data, data2);
    displayObjects(data);
    fns1(data, "A101");
    std::cout << "\n\n total sum above 13kk : " << fns2(data) << '\n';
    std::cout << "\n\n total sum above 13kk : " ;
    binded(data);
}