#include "Volunteer.h"

LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string& name, int maxDistance, int distancePerStep, int maxOrders):
                                                DriverVolunteer(id, name, maxDistance, distancePerStep), maxOrders(maxOrders),
                                                ordersLeft(maxOrders){

}

int LimitedDriverVolunteer:: getNumOrdersLeft() const{
    return ordersLeft;
}

int LimitedDriverVolunteer:: getMaxOrders() const{
    return maxOrders;
}

bool LimitedDriverVolunteer:: hasOrdersLeft() const{
    if (ordersLeft != 0)
        return true;
    return false;
}

bool LimitedDriverVolunteer:: canTakeOrder(const Order& order) const{
    if (isBusy or !hasOrdersLeft())
        return false;
    return true;
}

void LimitedDriverVolunteer:: acceptOrder(const Order& order){
    if (!canTakeOrder(order))
        return;
    DriverVolunteer::acceptOrder(order);
    ordersLeft--;

}

string LimitedDriverVolunteer::toString() const{
    string disc;
    disc +=  "VolunteerID: {}\n" + getId();
    disc += "isBusy: {}\n" + isBusy();
    if (isBusy()){
        disc += "isBusy: {}\n" + getActiveOrderId() ;
        disc += "TimeLeft: {}\n" + getDistanceLeft() ;
    }
    else{
        disc +=  "isBusy: None\n" ;
        disc += "TimeLeft: None\n" ;    
    }
    disc += "OrdersLeft: {}" + getNumOrdersLeft();

    return disc;
}