#include "LowBalance.h"
#include "Item.h"
#include "InvalidEntry.h"
#include <iostream>
void Item::sellItem()
{
    while (_cashInHand > 0)
    {
        try
        {
            std::cout << "Enter your choice ( 1-Burgur / 2-Pizza ) : ";
            std::string c;
            std::cin>>c;
            if(c=="1" || c=="2"){
                if(c=="1"){
                    _costPerItem = 10;
                    _item = Items::BURGUR;
                }else if(c=="2"){
                    _costPerItem = 20;
                    _item = Items::PIZZA;
                }
                std::cout<<"Enter quantity :- ";
                std::cin>>_noOfItem;
                if(_noOfItem<0) throw LowBalance("Low Balance");
                if(_costPerItem*_noOfItem <= _cashInHand && _cashInHand>0){
                    std::cout<<"Your order is placed!!";
                    _cashInHand -= (_noOfItem*_costPerItem);
                    std::cout<<"Remaing Balance : "<<_cashInHand<<'\n'; 
                }else{
                     throw LowBalance("Low Balance");
                }
            }else{
                throw InvalidEntry("Invalid Input");
            }
        }catch(InvalidEntry& e){
            std::cout<<e.what();
        }catch(LowBalance& e){
            std::cout<<e.what();
        }
    }
}