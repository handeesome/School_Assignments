#include <iostream>
#include <deque>
using namespace std;

class WindGauge {
public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);// add new to history
    int highest() const;            //returns highest
    int lowest() const;             //returns lowest
    int average() const;            //returns average
    void print() const;             //dumps above attributes
private:
    int period;
    deque<int>history;
};

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




}
