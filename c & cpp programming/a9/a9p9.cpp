/*
CH-230-B
a9 8.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
using namespace std;
//find out the max element in the array
//and delete it from the array
void subtract_max(int *a, int n){
    int max = a[0];
    int pos;

    for (int i=1; i<n; i++){
        if(a[i]>max){
            max = a[i];
            pos = i;
        }
    }
    cout << "The max value is " << max << endl;
    for (int i=pos; i<n-1; i++){
        a[i] = a[i+1];
    }
}
//deallocation
void deallocate(int *a){
    delete []a;
}
int main(){
    int n;
    cin >> n;
    int *a = new int(n);
//enter from keyboard n values
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
//delete the max value and print the new array
    subtract_max(a, n);
    cout << "The array after: " << endl;
    for (int i=0; i<n-1; i++){
        cout << a[i] << " " ;
    }
    deallocate(a);

    return 0;
}
