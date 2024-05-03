#include "Functionalities.h"

int main()
{
    Container data;
    createObjects(data);
    displayObjects(data);

    std::cout << std::boolalpha << allSavingsDebit(data) << '\n';

   std::cout << MaxAccoutBalance(data) << '\n';

    std::cout << *CardInfo(data,"C-103").get()<<'\n';
}