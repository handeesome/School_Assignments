#include <iostream>
#include <vector>
using namespace std;

bool test(string one, string two){
    if(one==two){
        cout << "ok";
        return true;
    }
}
int main(){
    string one = "app";
    string two = "app";
    test(one, two);
}
