#include "Action.h"
extern WareHouse* backup;

BackupWareHouse::BackupWareHouse(){

}

void BackupWareHouse::act(WareHouse& wareHouse){
    
}

string BackupWareHouse::toString() const{
    std::stringstream disc_stream;
    disc_stream << "backup " << getStatusString();
    return disc_stream.str(); 
}