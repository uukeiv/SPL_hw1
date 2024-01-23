#include "Customer.h"

Customer::Customer(int id, const string& name, int locationDistance, int maxOrders):id(id), name(name), locationDistance(locationDistance),
                    maxOrders(maxOrders){

}

const string& Customer::getName() const{
    return name;
}

int Customer::getId() const{
    return id;
}

int Customer::getCustomerDistance() const{
    return locationDistance;
}

int Customer::getMaxOrders() const{
    return maxOrders;
}

int Customer::getNumOrders() const{
    return ordersId.size();
}

int Customer::getNumOrdersLeft() const{
    return getMaxOrders() - getNumOrders();
}

bool Customer::canMakeOrder() const{
    return (getNumOrders() < getMaxOrders());
}

const vector<int>& Customer::getOrdersIds() const{
    return ordersId;
}

int Customer::addOrder(int orderId){
    if (canMakeOrder()){
        ordersId.push_back(orderId);
        return 1;
    }
    return -1;
}

string Customer::toString() const{
    string disc;
    for (int order : ordersId){
        //maybe add print order by id in warehouse then send them one by one here
    }
    int left = getMaxOrders() - getNumOrders();
    disc += "numOrdersLeft: " + left;

    return disc;
}