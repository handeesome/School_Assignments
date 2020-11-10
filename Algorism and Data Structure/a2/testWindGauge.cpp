#include "WindGauge.h"

int main(){
    WindGauge object;

    object.currentWindSpeed(15);
    object.currentWindSpeed(16);
    object.currentWindSpeed(12);
    object.currentWindSpeed(15);
    object.currentWindSpeed(15);    //the history looks like
                                    //  15 16 12 15 15
    object.print();

    object.currentWindSpeed(16);
    object.currentWindSpeed(17);
    object.currentWindSpeed(16);
    object.currentWindSpeed(16);
    object.currentWindSpeed(20);
    object.currentWindSpeed(17);
    object.currentWindSpeed(16);
    object.currentWindSpeed(15);
    object.currentWindSpeed(16);
    object.currentWindSpeed(20);// the history looks like
                                // 15 15 16 17 16 16
                                // 20 17 16 15 16 20
    object.print();

    return 0;
}
