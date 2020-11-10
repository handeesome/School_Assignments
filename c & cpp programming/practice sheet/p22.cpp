#include <iostream>
using namespace std;
class Person {

public:string name;
    int age;
    ~Person(){
    cout << "Person destructor" << endl;
    }
};
class Student : public virtual Person {

    public:long int matr_nr;
    ~Student(){
    cout << "Student destructor" << endl;
    }
};
class Faculty : public virtual Person {


    public:int employ_nr;
    ~Faculty(){
    cout << "Faculty destructor" << endl;
    }
};
class TA : public Student, public Faculty {

    public:string course_nr;
    TA() {
    course_nr = "CH_230_A";
    }
    TA(const TA &obj) {
    this->name = obj.name;
    this->age = obj.age;
    this->matr_nr = obj.matr_nr;
    this->employ_nr = obj.employ_nr;
    this -> course_nr = obj.course_nr;
    }
    ~TA(){
    cout << "TA destructor" << endl;
    }
    friend void print(const TA a);
};
void print(const TA a) {
    cout << a.course_nr << endl;
}
int main() {
    TA ta1;
 //   cout << ta1.age <<endl;
 //   cout << " 1" <<endl;
    TA ta2(ta1);
 //   cout << "1" <<endl;
    print(ta2);
    return 0;
}

