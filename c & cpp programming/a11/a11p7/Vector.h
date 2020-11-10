#include <iostream>
#include <cmath>
using namespace std;
class Vector{
    private:
        int size;//size of the vector
        double* components;//array of doubles containing components of the vector
    public:
        Vector();//default constructor
        Vector(int size, double *components);//parametric constructor
        Vector(Vector&);//copy constructor
        ~Vector();//destructor
        void setSize(int size);//setters
        void setCompo(double* components);

        int getSize()const;//getters
        double* getCompo()const;

        void print()const;//print out the vector
        double norm()const;//calculate the norm of a vector
        Vector sum(const Vector a)const;//calculate the sum of two vectors and return it
        Vector difference(const Vector a)const;//calculate the difference of two vectors and return it
        double ScalarProduct(const Vector a)const;//calculate the scalar product of two vectors
};
