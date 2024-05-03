#ifndef CAR_H
#define CAR_H

class Car
{
private:
    int _price;
    int _year;
public:
    //default constructor disabled
    Car()=delete;
    //default copy constructor disabled
    Car(const Car&) = delete;
    // default move constructor disabled 
    Car(const Car&&) = delete;
    // default assignment operator disabled 
    Car &operator=(const Car&) = delete; 
    // default move operator disabled
    Car &operator=(const Car&&) = delete; 
    // default distructor enabled 
    ~Car()=default;

    Car(int p, int y);

    int year() const { return _year; }
    void setYear(int year) { _year = year; }

    int price() const { return _price; }
    void setPrice(int price) { _price = price; }
};

#endif // CAR_H
