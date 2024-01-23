#include "Action.h"

PrintActionsLog::PrintActionsLog(){

}

void PrintActionsLog::act(WareHouse& wareHouse){
    for (BaseAction* const base : wareHouse.getActions()){
        std::cout << base << std::endl;
    }
    wareHouse.addAction(this);
    complete();
}

string PrintActionsLog::toString() const{
    std::stringstream disc_stream;
    disc_stream << "log " << getStatusString();
    return disc_stream.str(); 
}