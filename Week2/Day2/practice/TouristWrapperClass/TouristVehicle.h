#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include "Permit.h"
#include "VehicleType.h"
#include <memory>
#include <ostream>
#include <functional>
using Pointer = std::shared_ptr<Permit>;

class TouristVehicle
{
private:
    std::string _vehicleNumber;
    VehicleType _type;
    int _noOfSeats;
    float _perHourBookingCharges;
    std::reference_wrapper<Permit> _permit;

public:
    // default constructor disabled
    TouristVehicle() = default;
    // default copy constructor disabled
    TouristVehicle(const TouristVehicle &) = delete;
    // default move constructor disabled
    TouristVehicle(const TouristVehicle &&) = delete;
    // default assignment operator disabled
    TouristVehicle &operator=(const TouristVehicle &) = delete;
    // default move operator disabled
    TouristVehicle &operator=(const TouristVehicle &&) = delete;
    // default distructor enabled
    ~TouristVehicle() = default;

    TouristVehicle(std::string num, VehicleType type, int seat, float charges,std::reference_wrapper<Permit> pr);

    std::string vehicleNumber() const { return _vehicleNumber; }
    void setVehicleNumber(const std::string &vehicleNumber) { _vehicleNumber = vehicleNumber; }

    VehicleType type() const { return _type; }
    void setType(const VehicleType &type) { _type = type; }

    int noOfSeats() const { return _noOfSeats; }
    void setNoOfSeats(int noOfSeats) { _noOfSeats = noOfSeats; }

    float perHourBookingCharges() const { return _perHourBookingCharges; }
    void setPerHourBookingCharges(float perHourBookingCharges) { _perHourBookingCharges = perHourBookingCharges; }

    std::reference_wrapper<Permit> permit() const { return _permit; }
    void setPermit(const std::reference_wrapper<Permit> &permit) { _permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
