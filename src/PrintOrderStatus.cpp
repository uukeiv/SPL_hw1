#include "Action.h"

PrintOrderStatus::PrintOrderStatus(int id):orderId(id){

}

void PrintOrderStatus::act(WareHouse& wareHouse){
    if (!wareHouse.orderExists(orderId))
    {
        error("Order doesn't exist");
        return;
    }
    std::cout << wareHouse.getOrder(orderId).toString() << std::endl;
    complete(); 
}

string PrintOrderStatus::toString() const{
    std::stringstream disc_stream;
    char dividor = ' ';
    disc_stream << "orderStatus " << orderId << dividor << getStatusString();
    return disc_stream.str(); 
}