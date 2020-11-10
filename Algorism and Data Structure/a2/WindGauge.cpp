#include "WindGauge.h"

WindGauge::WindGauge(int p){
    period = p;
}

void WindGauge::currentWindSpeed(int s){
    if(history.size()!=period)
        history.push_front(s);
    else{
        history.pop_back();
        history.push_front(s);
    }
}

int WindGauge::highest()const{
    int max = history[0];
    for(int i=1; i<history.size(); i++){
        if(history[i]>max)
            max = history[i];
    }
    return max;
}

int WindGauge::lowest()const{
    int min = history[0];
    for(int i=1; i<history.size(); i++){
        if(history[i]<min)
            min = history[i];
    }
    return min;
}

int WindGauge::average()const{
    int sum = 0;
    for (int i=0; i<history.size();i++){
        sum +=history[i];
    }
    return sum /= history.size();
}

void WindGauge::print()const{
    cout << "The highest wind speed is " << highest() << endl;
    cout << "The lowest wind speed is " << lowest() << endl;
    cout << "The average wind speed is " << average() << endl;
}
