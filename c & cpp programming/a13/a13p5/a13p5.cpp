/*
CH-230-B
a13 p5.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include<iostream>
using namespace std;

class A
{
      int x;
    public:
      A(int i) { x = i; }
      void print() { cout << x; }
};

class B: virtual public A
{
    public:
      B():A(10) {  }
};

class C:  virtual public A
{
    public:
      C():A(10) {  }
};

class D: public B, public C {
public:
    D():A(10){} //The class D does not have any constructor
                //so that when an object is created in class D
                //the default constructor is called, which is combination of
                //default constructors of class B and C
                //However, for default constructors of class B and C
                //constructor of Class A must be declared since the keyword virtual
};

int main()
{
    D d;
    d.print();
    return 0;
}
