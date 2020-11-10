/*
CH-230-B
a11 p7.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "Vector.h"
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
