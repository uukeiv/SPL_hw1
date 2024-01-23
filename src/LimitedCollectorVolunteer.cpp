#include "Volunteer.h"

LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, const string& name, int coolDown, int maxOrders):CollectorVolunteer(id,name,coolDown),
                                                    maxOrders(maxOrders),ordersLeft(maxOrders){

}

int LimitedCollectorVolunteer:: getMaxOrders() const{
    return maxOrders;
}

int LimitedCollectorVolunteer:: getNumOrdersLeft() const{
    return ordersLeft;
}

bool LimitedCollectorVolunteer::hasOrdersLeft() const{
    if (ordersLeft != 0)
        return true;
    return false;
}

bool LimitedCollectorVolunteer::canTakeOrder(const Order& order) const{
    if (!isBusy() and hasOrdersLeft())
        return true;
    return false;
}

void LimitedCollectorVolunteer::acceptOrder(const Order& order){
    if (!canTakeOrder(order))
        return;
    CollectorVolunteer::acceptOrder(order);//not sure if this works the way i think it does
    ordersLeft--;
}

string LimitedCollectorVolunteer::toString() const{
    string disc;
    disc +=  "VolunteerID: {}\n" + getId();
    disc += "isBusy: {}\n" + isBusy();
    if (isBusy()){
        disc += "isBusy: {}\n" + getActiveOrderId() ;
        disc += "TimeLeft: {}\n" + getTimeLeft() ;
    }
    else{
        disc +=  "isBusy: None\n" ;
        disc += "TimeLeft: None\n" ;    
    }
    disc += "OrdersLeft: {}" + getNumOrdersLeft();

    return disc;

}