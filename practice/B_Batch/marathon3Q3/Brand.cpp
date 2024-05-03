#include "Brand.h"
std::ostream &operator<<(std::ostream &os, const Brand &rhs)
{
    os << "_brandType: " << displayEnum(rhs._brandType)
       << "\n_tradeMark: " << rhs._tradeMark
       << "\n_cars:\n";
    displayCars(rhs._cars);
    os << '\n';
    return os;
}

std::string displayEnum(BrandType t)
{
    if (t == BrandType::TRANSPORT)
        return "TRANSPORT";
    else if (t == BrandType::SPECIAL)
        return "SPECIAL";
    else
        return "CONSUMER";
}

void displayCars(std::array<std::reference_wrapper<Car>, 3> arr)
{
    for (auto &c : arr)
    {
        std::cout << c.get() << '\n';
    }
}

Brand::Brand(BrandType t, std::string name, std::array<std::reference_wrapper<Car>, 3> cars)
    : _brandType{t},
      _tradeMark{name},
      _cars{cars}
{
}