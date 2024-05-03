#include "patient.h"

patient::patient(int id, char* name, int temp[])
{
    this->pNo = id;
    this->pName = name;
    for(int i=0;i<3;i++)
    this->temp[i] = temp[i];
}

float patient::calulateAvgtemp()
{
    return 0.0f;
}


std::ostream &operator<<(std::ostream &os, const patient &rhs) {
  os << "pNo: " << rhs.pNo
     << " pName: " << rhs.pName
     << " temp: " << *rhs.temp;
  return os;
}
