#include "Functionalities.h"

#define line std::cout << "\n--------------------------------------------\n";

int main()
{
    BrandContainer data;
    CarContainer cars;

    line;

    createObjects(data, cars);
    DisplayObjects(data);

    line;

    std::vector<Car *> result = CarsAboveThreshold(data, 50);
    for (auto c : result)
        std::cout << *c << '\n';

    line;

    ChassisType r2 = ChassisTypeOfCheapestCar(data);
    std::cout << "Chassis : " << displayEnum(r2) << '\n';

    line;

    std::cout << "Allabove4seat :: " << std::boolalpha << allHave4seats(data);

    line;
}
