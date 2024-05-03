#include "Funcationalities.h"
#include<vector>

int main(){
    std::vector<Car*> data;
    CreateObject(data);
    DisplayObjects(data);
    DeleteObject(data);
}