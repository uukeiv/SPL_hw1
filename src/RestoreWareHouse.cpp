#include "Action.h"
extern WareHouse* backup;

RestoreWareHouse::RestoreWareHouse(){

}

void RestoreWareHouse::act(WareHouse& wareHouse){

}

string RestoreWareHouse::toString() const{
    std::stringstream disc_stream;
    disc_stream << "restore " << getStatusString();
    return disc_stream.str(); 
}