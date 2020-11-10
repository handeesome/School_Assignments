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
