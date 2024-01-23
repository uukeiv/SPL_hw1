#include "Action.h"

AddOrder::AddOrder(int id):customerId(id){

}

void AddOrder::act(WareHouse& wareHouse){//this is pretty terribly written rn would be "prettier" to make a dummy customer with id = -1
    //Customer cust =  wareHouse.getCustomer(customerId);
    if (!wareHouse.customerExists(customerId) or !wareHouse.getCustomer(customerId).canMakeOrder()){
        error("”Cannot place this order");
        return;
    }
    wareHouse.addAction(this);
    Order* order = new Order(wareHouse.getNewOrderId(), customerId, wareHouse.getCustomer(customerId).getCustomerDistance());
    wareHouse.addOrder(order);
    complete();
}

string AddOrder::toString() const{
    std::stringstream disc_stream;
    char dividor = ' ';
    disc_stream << "order " << customerId << dividor << getStatusString();
    return disc_stream.str(); 
}
