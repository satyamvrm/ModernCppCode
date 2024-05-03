#include "Functionalities.h"

int main()
{
    Container data;
    createObjects(data);
    displayObjects(data);
    try
    {
        std::cout << "\nAverage :- " << AverageDuration(data);
        std::cout << "\nMinimum Charges :- " << displayPermitType(minimumRenualCharge(data));
        Container newData;
        newData = (nInstance(data, 2));
        std::cout << "\n\nNew Container";
        displayObjects(newData);
    }
    catch (EmptyData &e)
    {
        std::cerr << e.what() << '\n';
    }
}