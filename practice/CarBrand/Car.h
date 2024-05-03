#ifndef CAR_H
#define CAR_H
#include <ostream>

class Car
{
private:
    int _price;
    int _launchYear;

public:
    Car() = delete;
    Car(const Car &) = delete;
    Car(Car &&) = delete;
    Car &operator=(Car &&) = delete;
    Car &operator=(Car &) = delete;
    ~Car() {}
    Car(int p, int y);

    int price() const { return _price; }
    void setPrice(int price) { _price = price; }

    int launchYear() const { return _launchYear; }
    void setLaunchYear(int launchYear) { _launchYear = launchYear; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    
};

#endif // CAR_H
