#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "OnlinePayment.h"
#include "CashPayment.h"
#include "EmptyData.h"
#include <list>
#include<memory>

using Pointer = std::shared_ptr<CabBooking>;
using Container = std::list<Pointer>;

void createObjects(Container& data);
void displayObjects(Container& data);
Pointer findBookingById(Container& data);
bool allAbove1000(Container& data);
Container nInstance(Container& data, int n);

#endif // FUNCTIONALITIES_H
