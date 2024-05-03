#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Bill.h"
#include<list>
#include<memory>
#include<vector>



using Container = std::list<std::shared_ptr<Bill>>;
using InvoiceContainer = std::vector<std::shared_ptr<Invoice>>;

void createObjects(Container& data, InvoiceContainer& data2);
void displayObjects(Container& data);

extern std::function<void(Container&, std::string)> fns1; 
extern std::function<int(Container&)> fns2;


#endif // FUNCTIONALITIES_H
