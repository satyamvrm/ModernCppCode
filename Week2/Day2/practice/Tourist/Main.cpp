#include "Functionalities.h"

int main()
{
    Container data;
    createObjects(data);
    displayObjects(data);
    try
    {
        std::cout<<"\n\n-------------------------firstNInstanceOfTouristWithCondition----------------------\n";
        Container newData;
        newData = (firstNInstanceOfTouristWithCondition(data, 2));
        displayObjects(newData);

        std::cout<<"\navgBookingCharges :- "<<avgBookingCharges(data,VehicleType::BIKE);

        std::cout<<"\nmaxBookingCharges :- "<<maxBookingCharges(data);
        
        std::cout<<"\n\n----------------------------firstNInstance----------------------------------------\n";
        Container newData2;
        newData2 = (firstNInstance(data, 2));
        displayObjects(newData2);
    }
    catch (EmptyData &e)
    {
        std::cerr << e.what() << '\n';
    }

}