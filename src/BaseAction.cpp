#include "Action.h"

BaseAction::BaseAction(){}

ActionStatus BaseAction::getStatus() const{
    return status;
}

void BaseAction::complete(){
    status = ActionStatus::COMPLETED;
}

void BaseAction::error(string errorMsg){
    this->errorMsg = errorMsg;
    std::cout << errorMsg << std::endl;
    status = ActionStatus::ERROR;
}

string BaseAction::getStatusString() const{
    if (status == ActionStatus::COMPLETED)
        return "COMPLETED";
    return "ERROR";
}

string BaseAction::getErrorMsg() const{
    return errorMsg;
}

