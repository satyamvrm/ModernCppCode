#include "Functionalities.h"
#include<thread>

int main()
{
    Conatainer data;
    createObject(data);
    displayObjects(data);

    std::cout << "Count of UPI Transaction type : " << countTransactionOfGivenType(data, TransactionType::UPI)<<'\n';
    std::cout << "Count of Card Transaction type : " << countTransactionOfGivenType(data, TransactionType::CARD)<<'\n';
    std::cout << "Count of Cash Transaction type : " << countTransactionOfGivenType(data, TransactionType::CASH)<<'\n';

    std::cout<<"\nTotal of all Accounts : "<<totalTransctionAmunt(data)<<'\n';
    std::cout<<"\n\nMax Account Balance : "<<findMaxAccountBalanceID(data)<<'\n'<<'\n';

    Conatainer result = AccountAboveThreshold(data,360);
    displayObjects(result);

    std::cout<<"\n\n";

    std::cout<<"nth TransactionId : "<<nthTransectionID(data,2,"A-103")<<'\n';

    std::cout<<"Average Transection amount of A-104 : "<<averageTransactionAmount(data,"A-104")<<'\n';

    std::thread t(&balanceInterestAmount,std::ref(data));

    isValidAccount(data);

    t.join();
}