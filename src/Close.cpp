#include "Action.h"

Close::Close(){

}

void Close::act(WareHouse& wareHouse){
    wareHouse.addAction(this);
    wareHouse.close();
    complete();
}

string Close::toString() const{
    std::stringstream disc_stream;
    disc_stream << "close " << getStatusString();
    return disc_stream.str(); 
}