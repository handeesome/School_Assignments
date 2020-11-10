/*
CH-230-B
a13 p4.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include<iostream>
using namespace std;

class A
{
  int x;
public:
  void setX(int i) {x = i;}
  void print() { cout << x; }
};

class B:  public virtual A
{
public:
  B()  { setX(10); }
};

class C:  public virtual A
{
public:
  C()  { setX(20); }
};

class D: public B, public C {
};

int main()
{
    D d;
    d.print();  //class D is inherited from class B and class C
                //class B and C are both inherited from Class A
                //that makes class D having two print methods from Class A
                //to fix this problem, make the parent class virtual
                //so that the child class only inherit methods once
    return 0;
}
