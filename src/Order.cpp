#include "Order.h"

Order::Order(int id, int customerId, int distance):id(id), customerId(customerId), distance(distance),status(OrderStatus::PENDING),
            collectorId(NO_VOLUNTEER),driverId(NO_VOLUNTEER){

}

int Order::getId() const{
    return id;   
}

int Order::getCustomerId() const{
    return customerId;   
}

int Order::getCollectorId() const{
    return collectorId;   
}

int Order::getDriverId() const{
    return driverId;   
}

int Order::getDistance() const{
    return distance;   
}

OrderStatus Order::getStatus() const{
    return status;   
}

void Order::setStatus(OrderStatus status){
    this->status = status;   
}

void Order::setCollectorId(int collectorId){
    this->collectorId = collectorId;   
}

void Order::setDriverId(int driverId){
    this->driverId = driverId;   
}

string Order::getStatusString() const{
    if (status == OrderStatus::PENDING)
        return "PENDING";
    if (status == OrderStatus::COLLECTING)
        return "COLLECTING";
    if (status == OrderStatus::DELIVERING)
        return "DELIVERING";
    return "COMPLETED";
}

const string Order::toString() const{
    string disc;
    disc += "OrderId: {}\n" + getId();
    disc += "OrderStatus: {}\n" + getStatusString(); 
    disc += "OrderStatus: {}\n" + getStatusString();
    if (getCollectorId() == NO_VOLUNTEER){
        disc+= "Collector: None\n";
    }
    else{
        disc += "Collector: {}\n" + getCollectorId();    
    }

    if (getDriverId() == NO_VOLUNTEER){
        disc += "Driver: None\n";
    }
    else{
        disc += "Driver: {}" + getDriverId();    
    }


    return disc;
}