#include "Functionalities.h"
#include "Sensor.h"
#include "SensorType.h"
#include "EmptyData.h"
#include<list>

int main(){
    Container data;
    CreateObjects(data);
    try{
        showReadings(data);
        std::cout<<"\n\nThe total no. of sensors are : "<<showCount(data);
        std::cout<<"\n\nThe count of Temprature : "<<NumberOfType(data,SensorTypes::TEMPERATURE)<<'\n';
    }catch(EmptyData& e){
        std::cerr<<e.what();
    }
}
