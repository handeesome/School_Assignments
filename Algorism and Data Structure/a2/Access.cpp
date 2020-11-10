#include "Access.h"

void Access::activate(unsigned int code){
    passcode.insert(code);
}

void Access::deactivate(unsigned int code){
    passcode.erase(code);
}

bool Access::isactive(unsigned int code)const{
    if (passcode.count(code)==0){
        return false;
    }
    else
        return true;
}
