#include "LinkedList.h"
using namespace std;

int main(){
    List<int> a;

    //test for adding elements
    a.addatfront(1);
    a.addatend(2);
    a.addatend(3);
    a.addatfront(4); //now the list is (4,1,2,3) from front to end

   // cout << a.head->value << a.head->next->value << a.tail->previous->value << a.tail->value;

    //test for remove first
    cout << a.removefirst() << endl; //should be 4

    //test for remove last
    cout << a.removelast() << endl; //should be 3

    //test for return first
    cout << a.returnfirst() << endl; //should be 1

    //test for return last
    cout << a.returnlast() << endl; //should be 2

    //test for counting node numbers
    cout << a.nodenum() << endl; //should be 2


    return 0;
}
