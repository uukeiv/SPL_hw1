#include "Action.h"

PrintCustomerStatus::PrintCustomerStatus(int customerId):customerId(customerId){

}

void PrintCustomerStatus::act(WareHouse& wareHouse){
    if (!wareHouse.customerExists(customerId))
    {
        error("Customer doesn’t exist");
        return;
    }

    std::cout << "CustomerID: " << customerId << std::endl;
    for (int id : wareHouse.getCustomer(customerId).getOrdersIds()){
        std::cout << wareHouse.getOrder(id).toString() << std::endl;
    }
    std::cout << "numOrdersLeft: " << wareHouse.getCustomer(customerId).getNumOrdersLeft() << std::endl;
    complete();
}

string PrintCustomerStatus::toString() const{
    std::stringstream disc_stream;
    char dividor = ' ';
    disc_stream << "customerStatus " << customerId << dividor << getStatusString();
    return disc_stream.str(); 
}