#include <Action.h>

SimulateStep::SimulateStep(int numOfSteps):numOfSteps(numOfSteps){

}

void SimulateStep::act(WareHouse& WareHouse){

}

std::string SimulateStep::toString() const{
    std::stringstream disc_stream;
    char dividor = ' ';
    disc_stream << "step " << numOfSteps << dividor << getStatusString();
    return disc_stream.str();
}

