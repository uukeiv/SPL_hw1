#include "Volunteer.h"


CollectorVolunteer::CollectorVolunteer(int id, const string &name, int coolDown):Volunteer(id,name),coolDown(coolDown),timeLeft(0){

}

int CollectorVolunteer::getCoolDown() const{
    return coolDown;
}

int CollectorVolunteer::getTimeLeft() const{
    return timeLeft;
}

bool CollectorVolunteer::decreaseCoolDown(){
    if (timeLeft == 0)
        return true;
    timeLeft--;
    if (timeLeft == 0)
        return true;
    return false;
}

bool CollectorVolunteer::hasOrdersLeft() const{
    return true;
}

bool CollectorVolunteer::canTakeOrder(const Order& order) const{
    if (timeLeft == 0)
        return true;
    return false;
}

void CollectorVolunteer::acceptOrder(const Order& order){
    if (isBusy())
        return;
    activeOrderId = order.getId();
    timeLeft = coolDown;
}

void CollectorVolunteer::step(){
    
}

string CollectorVolunteer::toString() const{
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
    disc += "OrdersLeft: No Limit";

    return disc;
}

