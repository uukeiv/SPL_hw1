#include "../include/Action.h"

AddCustomer::AddCustomer(const string& customerName, const string& CustomerType, int distance, int maxOrders):customerName(customerName),
                        customerType(customerType),distance(distance),maxOrders(maxOrders){

}

void AddCustomer::act(WareHouse& wareHouse){
    wareHouse.addAction(this);
    wareHouse.addCust(customerName,getTypeString(),distance,maxOrders);
    complete();
}

string AddCustomer::getTypeString() const{
    if (customerType == CustomerType::Civilian)
        return "civilian";
    return "soldier";
}

string AddCustomer::toString() const{
    std::stringstream disc_stream;
    char dividor = ' ';
    disc_stream << "customer " << customerName << dividor << getTypeString() << dividor << distance << dividor << maxOrders 
    << dividor << getStatusString();
    return disc_stream.str(); 
}

