#include "Functionalities.h"
#include<future>

int main()
{
    Container data;
    createObjests(data);
    std::cout << "All Data in list :- \n";
    displayObjects(data);

    try
    {
        std::cout << "\n\nThe First and Last objects are : \n ";
        std::future<void> t2 = std::async(&firstAndLastObjectServicingCost,std::ref(data));
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\n\nTotal Tax Exemption : \n ";
        std::future<float> t1 = std::async(&totalTaxExemptionAmount,std::ref(data));
        std::cout << t1.get()<<'\n';
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::string str;
        std::cout << "\n\nEnter the registration number : \n ";
        std::cin >> str;
        std::future<void> t4 = std::async(&displayPriceAndBrand,std::ref(data), std::ref(str));
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (InvalidRegistrationNumber &e)
    {
        std::cout << e.what();
    }
}