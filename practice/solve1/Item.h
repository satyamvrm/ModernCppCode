#ifndef ITEM_H
#define ITEM_H
#include "ItemEnum.h"

class Item
{
private:
    Items _item{Items::BURGUR};
    int _noOfItem{0};
    int _cashInHand{100};
    int _costPerItem{10};
public:
    Item() = default;
    Item(Item& obj) = delete;
    Item(Item&& obj) = delete;
    Item & operator=(Item& obj) = delete;
    Item & operator=(Item&& obj) = delete;
    ~Item() = default;
    
    void sellItem();
};

#endif // ITEM_H
