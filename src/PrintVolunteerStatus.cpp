#include "Action.h"

PrintVolunteerStatus::PrintVolunteerStatus(int id):volunteerId(id){

}

void PrintVolunteerStatus::act(WareHouse& wareHouse){
    if (!wareHouse.volExists(volunteerId)){
        error("Volunteer doesn't exist");
        return;
    }
    std::cout << wareHouse.getVolunteer(volunteerId).toString() << std::endl;
    complete();
}

string PrintVolunteerStatus::toString() const{
    std::stringstream disc_stream;
    char dividor = ' ';
    disc_stream << "volunteerStatus " << volunteerId << dividor << getStatusString();
    return disc_stream.str(); 
}