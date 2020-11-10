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
int main(){

}
