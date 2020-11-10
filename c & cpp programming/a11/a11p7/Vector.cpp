#include "Vector.h"
Vector::Vector() : size(0){
    components = new double[1];
    components[0] = 0;
}

Vector::Vector(int Size, double* c){
    size = Size;
    components = new double [size];
    for (int i=0; i<size; i++){
        components[i] = c[i];
    }
}

Vector::Vector(Vector &a){
    size = a.getSize();
    double* temp = a.getCompo();
    components = new double [size];
    for (int i=0; i<size; i++){
        components[i] = temp[i];
    }
}

Vector::~Vector(){
    delete []components;
}

void Vector::setSize(int s){
    size = s;
}

void Vector::setCompo(double* c){
    components = new double [size];
    for (int i=0; i<size; i++){
        components[i] = c[i];
    }
}

int Vector::getSize()const{
    return size;
}

double* Vector::getCompo()const{
    return components;
}

void Vector::print()const{
    for(int i=0; i<size; i++){
        cout << components[i] << " ";
    }
    cout << endl;
}

double Vector::norm()const{
    double sum=0;
    for (int i=0; i<size; i++){
        sum = sum + components[i]*components[i];
    }
    double norm = sqrt(sum);

    return norm;
}

Vector Vector::sum(const Vector a)const{

    double* temp = new double [size];
    for(int i=0; i<size; i++){
        temp[i] = components[i]+ a.getCompo()[i];
    }
    Vector newv(size, temp);
    return newv;
}

Vector Vector::difference(const Vector a)const{
    double* temp = new double [size];
    for(int i=0; i<size; i++){
        temp[i] = components[i]- a.getCompo()[i];
    }
    Vector newv(size, temp);
    return newv;
}

double Vector::ScalarProduct(const Vector a)const{
    double sum = 0;
    for (int i=0; i<size; i++){
        sum += components[i]*a.getCompo()[i];
    }
    return sum;
}
