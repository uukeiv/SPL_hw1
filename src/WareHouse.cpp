#include <iostream>
#include "../include/WareHouse.h"
#include <fstream>

using namespace std;

vector<string> spliter(const string &command){ //splits the command into arguments sperated by ' ' 
    string div = " ";
    size_t end = command.find( div);
    size_t start = 0;
    vector<string>  arr;
    while (end != string::npos){
        arr.push_back(command.substr(start,end - start));
        start = end + 1;
        end = command.find( div, start);
    }

    arr.push_back(command.substr(start, std::min( end, command.size() ) - start + 1 ));
    return arr;
}

WareHouse:: WareHouse(const string &configFilePath):isOpen(true),customerCounter(0),volunteerCounter(0){
    string line;
    ifstream  file(configFilePath);
    if (file.is_open()){
        while(getline(file, line)) {
            checker(line);
        }
        file.close();
    }

}

void WareHouse::checker(string &command){
    vector<string> arguments = spliter(command);
    if ( arguments.size() == 0)
        return;
    string action = arguments[0];
    if ( action.compare("customer"))
    {          
        addCust(arguments[1], arguments[2], stoi(arguments[3]), stoi(arguments[4]));
        AddCustomer act(arguments[1], arguments[2], stoi(arguments[3]), stoi(arguments[4]));
        return;
    }
    if (action.compare("volunteer")){
        addVol(arguments);
    }
}

void WareHouse::addOrder(Order* order){
    orderCounter++;
    pendingOrders.push_back(order);
}

void WareHouse::addAction(BaseAction* action){
    actionsLog.push_back(action);
}

Order& WareHouse::getOrder(int orderId) const{ //if not found, returns a dummy order that needs to be realsed by the calling function
    for (Order* order : pendingOrders){
        if (order->getId() == orderId)
            return *order;
    }

    for (Order* order : inProcessOrders){
        if (order->getId() == orderId)
            return *order;
    }

    for (Order* order : completedOrders){
        if (order->getId() == orderId)
            return *order;
    }

    Order* order = new Order(-1, -1,-1);
    return *order;//who ever called this need to release the memory
}

const vector<BaseAction*>& WareHouse::getActions() const{
    return actionsLog;
}

void WareHouse::open(){
    isOpen = true;
}

int WareHouse::getNewOrderId(){//no need to raise the counter by one since that will happen in addOrder
    return orderCounter;
}

bool WareHouse::orderExists(int orderId) const{
    for (Order* order : pendingOrders){
        if (order->getId() == orderId)
            return true;
    }

    for (Order* order : inProcessOrders){
        if (order->getId() == orderId)
            return true;
    }

    for (Order* order : completedOrders){
        if (order->getId() == orderId)
            return true;
    }

    return false;
}

void WareHouse::addCust(const string &name,const string &type, int dist, int maxOrder){
    if (type.compare("civilian")){
        CivilianCustomer* cust = new CivilianCustomer(customerCounter,name,dist,maxOrder);
        customers.push_back(cust);
        customerCounter++;
        return;
    }
    if (type.compare("soldier")){
        CivilianCustomer* cust = new CivilianCustomer(customerCounter,name,dist,maxOrder);
        customers.push_back(cust);
        customerCounter++;
        return;
    }
}

void WareHouse::addVol(const vector<string>& arguments){
    string type = arguments[2];
    if (type.compare("collector")){
        CollectorVolunteer* vol = new CollectorVolunteer(volunteerCounter,arguments[1],stoi(arguments[2]));
        volunteers.push_back(vol);
        volunteerCounter++;
        return;
    }
    
    if (type.compare("driver")){
        DriverVolunteer* vol = new DriverVolunteer(volunteerCounter,arguments[1],stoi(arguments[2]), stoi(arguments[3]));
        volunteers.push_back(vol);
        volunteerCounter++;
        return;
    }

    if (type.compare("limited_collector")){
        LimitedCollectorVolunteer* vol = new LimitedCollectorVolunteer(volunteerCounter,arguments[1],stoi(arguments[2]), stoi(arguments[3]));
        volunteers.push_back(vol);
        volunteerCounter++;
        return;
    }

    if (type.compare("limited_driver")){
        LimitedDriverVolunteer* vol = new LimitedDriverVolunteer(volunteerCounter,arguments[1],stoi(arguments[2]), stoi(arguments[3])
                                                                 , stoi(arguments[4]));
        volunteers.push_back(vol);
        volunteerCounter++;
        return;
    }
}


    


