#include "Access.h"

void Access::activate(unsigned int code, unsigned int level){
    passcode.insert(pair<int, int>(code, level));
}

void Access::deactivate(unsigned int code){
    passcode.erase(code);
}

bool Access::isactive(unsigned int code, unsigned int level) const{
    if(passcode.count(code)==1){
        if(passcode.at(code)<level){
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}
