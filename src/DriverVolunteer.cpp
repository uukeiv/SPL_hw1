#include "Volunteer.h"

DriverVolunteer::DriverVolunteer(int id, const string& name, int maxDistance, int distancePerStep):Volunteer(id,name),
                                maxDistance(maxDistance), distancePerStep(distancePerStep),distanceLeft(0){

}

int DriverVolunteer:: getDistanceLeft() const{
    return distanceLeft;
}

int DriverVolunteer:: getMaxDistance() const{
    return maxDistance;
}

int DriverVolunteer:: getDistancePerStep() const{
    return distancePerStep;
}

bool DriverVolunteer:: decreaseDistanceLeft(){
    distanceLeft = distanceLeft - distancePerStep;
    if (distanceLeft <= 0){
        distanceLeft = 0;
        return true;
    }
    return false;
}

bool DriverVolunteer:: hasOrdersLeft() const{
    return true;
}

bool DriverVolunteer:: canTakeOrder(const Order& order) const{
    if (isBusy)
        return false;
    return true;
}

void DriverVolunteer:: acceptOrder(const Order& order){
    if (!canTakeOrder(order))
        return;
    distanceLeft = order.getDistance();
    activeOrderId = order.getId();
}

void DriverVolunteer::step(){

}

string DriverVolunteer::toString() const{
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
    disc += "OrdersLeft: No Limit";

    return disc;
}
