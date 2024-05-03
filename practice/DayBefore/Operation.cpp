#include "Operation.h"

std::shared_ptr<Operation> _soloObject{nullptr};

std::shared_ptr<Operation> Operation::getInstance()
{
    if(!_soloObject)
        _soloObject.reset(new Operation());
    return _soloObject;
}

void Operation::createObjects()
{
    _cabDrivers.push_back(Driver("D-101",DriverRating::Star_3));
    _cabDrivers.push_back(Driver("D-102",DriverRating::Star_3));
    _cabDrivers.push_back(Driver("D-103",DriverRating::Star_2));

    _cabRides.push_back(std::make_shared<CabRide>(101,RideType::Local,PaymentMode::Online,800.0f,"London","Munic",_cabDrivers[0]));
    _cabRides.push_back(std::make_shared<CabRide>("102",RideType::Outstation,PaymentMode::Cash,840.0f,"Delhi","Pune",_cabDrivers[1]));
    _cabRides.push_back(std::make_shared<CabRide>(103,RideType::Regular,PaymentMode::Cash,8000.0f,"Kashmir","KanyaKumari",_cabDrivers[2]));
    _cabRides.push_back(std::make_shared<CabRide>("104",RideType::Local,PaymentMode::Online,300.0f,"Hinjewadi","Baner",_cabDrivers.at(0)));
}

PaymentMode Operation::paymentModeById(std::variant<int, std::string> id)
{
    auto itr = std::find_if(
        _cabRides.begin(),
        _cabRides.end(),
        [&](auto& c){
            return c->id() == id;
        }
    );
    return (*itr)->paymentMode();
}

std::array<RideType, 2> Operation::MaximumMinimumRideType()
{
    std::array<RideType,2> result;
    auto max = std::max_element(
        _cabRides.begin(),
        _cabRides.end(),
        [](const std::shared_ptr<CabRide>& c1,const std::shared_ptr<CabRide>& c2){
            return c1->fair()<c2->fair();
        }
    );

    auto min = std::min_element(
        _cabRides.begin(),
        _cabRides.end(),
        [](const std::shared_ptr<CabRide>& c1,const std::shared_ptr<CabRide>& c2){
            return c1->fair()<c2->fair();
        }
    );

    result[0] = (*max)->rideType();
    result[1] = (*min)->rideType();

    return result;
}

std::vector<std::string> Operation::FirstNInstances(std::future<int>& n)
{
    std::vector<std::string> result(_cabRides.size());
    int temp = n.get();
    auto itr = std::copy_if(
        _cabRides.begin(),
        _cabRides.end(),
        result.begin(),
        [&](const std::shared_ptr<CabRide>& c1){
            if(temp>0){
                result.push_back(c1->pickup());
                temp--;
            }
        }
    );
    result.resize(std::distance(result.begin(),itr));
    return result;
}
