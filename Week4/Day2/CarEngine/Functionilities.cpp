#include "Functionilities.h"
#include<algorithm>
#include<numeric>

void CreateObjects(Container &data)
{
    data.emplace("c101",
        std::make_shared<Car>(
            "c101",
            750000.0f,
            "Honda City",
            std::make_shared<Engine>(
                400,
                180),
            CarType::SEDAN
        )
    );
    data.emplace(
        "c102",
        std::make_shared<Car>(
            "c102",
            780000.0f,
            "Honda Amaze",
            std::make_shared<Engine>(
                400,
                190
            ),
            CarType::SEDAN
        )
    );
}

int totalHorsePower(const Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty\n", std::future_errc::no_state);
    return std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float answer_upto_current_point,const std::pair<std::string,CarPointer>& row){
            return answer_upto_current_point+row.second->engine()->horsePower();
        }
    );
}

bool isAllCarAbove700K(const Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty\n", std::future_errc::no_state);
    return std::all_of(
        data.begin(),
        data.end(),
        [](const std::pair<std::string,CarPointer>& row){ 
            return row.second->price()>700000;
        }
    );
}

Engine *enginePointerToMinPrice(const Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty\n", std::future_errc::no_state);
    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<std::string,CarPointer>& row1,const std::pair<std::string,CarPointer>& row2){
            return row1.second->price()<row2.second->price();
        }
    );
    return (*itr).second->engine().get();
}

float avgEngineTorque(const Container &data)
{

    if (data.empty())
        throw EmptyContainerException("Data is Empty\n", std::future_errc::no_state);
    std::size_t count{0};
    float ans = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float answer_upto_current_point,const std::pair<std::string,CarPointer>& row){
            if(row.second->engine()){
                count++;
                return answer_upto_current_point+row.second->engine()->torque();
            }
            return answer_upto_current_point;
        }
    );
    return ans/static_cast<float>(count);
    
}

std::string findCarModelByID(const Container &data, const std::string carID)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty\n", std::future_errc::no_state);
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string,CarPointer>& row){
            return row.first==carID;
        }
    );
    if(itr==data.end()){
        throw std::runtime_error("ID not found");
    }
    else{
        return (*itr).second->model();
    }
}
