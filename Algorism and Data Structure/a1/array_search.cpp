#include <iostream>
using namespace std;
template <class T>
int array_search(T arr[], int num, T element){
   for (int i=0; i<num; i++){
        if (arr[i]==element)
            return i;                       //if the element is found return index
        if (i==num-1 && arr[i]!=element)
            return -1;                      //if not found return -1
   }
}
class Complex{
    private:
        int re;
        int im;
    public:
        Complex();
        Complex(int r, int i):re(r), im(i){}
        bool operator==(const Complex& a){          //operator overloading ==
            if( a.im== this->im && a.re==this->re)
                return true;
            else
                return false;
        }
        bool operator!=(const Complex& a){          //operator overloading !=
            if (a.im!=this->im || a.re!=this->re)
                return true;
            else
                return false;
        }
};

int main(){

    int intarray[] = {0, 1, 2 ,3, 4, 5, 6, 7, 8, 9};
    double doublearray[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    char chararray[] = {'a', 'e', 'i', 'o', 'u'};
    Complex complexarray[] = {Complex(1, 2), Complex(3, 4), Complex(5, 6), Complex(7, 8)};

    cout << array_search(intarray, 10, 4) << endl;              //should be 4
    cout << array_search(doublearray, 9, 1.2) << endl;          //should be -1
    cout << array_search(chararray, 5, 'u') << endl;            //should be 4
    cout << array_search(complexarray,4, Complex(1, 2)) << endl;//should be 0

    return 0;
}
