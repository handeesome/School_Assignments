/*
CH-230-B
a11 p7.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <cmath>
using namespace std;

class Vector{
    private:
        int size;
        double* components;
    public:
        Vector();
        Vector(int size, double *components);
        Vector(Vector&);
        ~Vector();
        void setSize(int size);
        void setCompo(double* components);
        int getSize()const;
        double* getCompo()const;
        void print()const;
        double norm()const;
        Vector sum(const Vector a)const;
        Vector difference(const Vector a)const;
        double ScalarProduct(const Vector a)const;
};

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
int main(){
    double a[] = {1, 2};
    double b[] = {2, 3};
    Vector v1;
    v1.setSize(2);
    v1.setCompo(a);

    Vector v2(v1);

    Vector v3(2, b);

    cout << "The norm of first vector is: " << v1.norm() << endl;
    cout << "The scalar product of first and third vectors: " << v1.ScalarProduct(v3) << endl;
    cout << "The sum of first and third vectors:\n";
    (v1.sum(v3)).print();
    cout << "The difference of first and third vectors:\n";
    (v1.difference(v3)).print();
}
