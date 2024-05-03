#include "Functionalities.h"

int main()
{
    ContainerV data1;
    ContainerP data2;
    createObjects(data1,data2);
    displayObjects(data1,data2);
    try
    {
        std::cout<<"\n\n-------------------------firstNInstanceOfTouristWithCondition----------------------\n";
        ContainerV newData;
        newData = (firstNInstanceOfTouristWithCondition(data1, 2));
        displayObjects(newData,data2);

        std::cout<<"\navgBookingCharges :- "<<avgBookingCharges(data1,VehicleType::BIKE);

        // std::cout<<"\nmaxBookingCharges :- "<<maxBookingCharges(data1);
        
        std::cout<<"\n\n----------------------------firstNInstance----------------------------------------\n";
        ContainerV newData2;
        newData2 = (firstNInstance(data1, 2));
        displayObjects(newData2,data2);

        std::cout<<"-------------Trying to delete--------------\n";
        deleteVehicle(data1,2);
        displayObjects(data1,data2);
    }
    catch (EmptyData &e)
    {
        std::cerr << e.what() << '\n';
    }

}