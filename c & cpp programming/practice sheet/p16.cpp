#include <iostream>
using namespace std;
class Car{
    private:
        string brand;
        string model;
        double price;
    public:
        Car(string brand, string model, double price)
        :brand(brand), model(model), price(price){}
        ~Car(){}
        void setBrand(string name);

};
inline void Car::setBrand(string name){brand = name;}

class Taxi : public Car{
    private:
        int capacity;
    public:
        Taxi(string brand, string model, double price, int capacity)
        :Car(brand, model, price), capacity(capacity){}
        void print(){cout << "..." << endl;}
};
int main(){

}
