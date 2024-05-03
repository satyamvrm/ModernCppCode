#ifndef OPERATION_H
#define OPERATION_H

#include "CabRide.h"
#include <optional>
#include <future>
#include <memory>
#include <vector>
#include <array>

using CabPointer = std::shared_ptr<CabRide>;
using CabDrivers = std::vector<Driver>;
using CabRides = std::vector<CabPointer>;

class Operation
{
private:
    CabRides _cabRides;
    CabDrivers _cabDrivers;
    static std::shared_ptr<Operation> _soloObject;
    Operation(CabRides rides, CabDrivers drivers) : _cabRides{rides}, _cabDrivers{drivers} {}
    // default constructor enabled
    Operation() = default;

public:
    // default copy constructor disabled
    Operation(const Operation &) = delete;
    // default move constructor disabled
    Operation(const Operation &&) = delete;
    // default assignment operator disabled
    Operation &operator=(const Operation &) = delete;
    // default move operator disabled
    Operation &operator=(const Operation &&) = delete;
    // default distructor enabled
    ~Operation() = default;

    static std::shared_ptr<Operation> getInstance();

    void createObjects();
    PaymentMode paymentModeById(std::variant<int, std::string> id);
    std::array<RideType, 2> MaximumMinimumRideType();
    std::vector<std::string> FirstNInstances(std::future<int>& n);
    std::vector<std::reference_wrapper<Driver>> NDriverInstances();
};

#endif // OPERATION_H
