#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// add your code below
class Object3D{
    private:
        string name;
    public:

};
int main(int argc, char ∗argv[]) {
Object3D *arr[5];
arr[0] = new Sphere("sphere", 1.3);
arr[1] = new RectPrism("rectprism", 2.0, 3.0, 4.0);
arr[2] = new Cylinder("cylinder", 2.0, 1.3);
arr[3] = new Cube("cube", 2.0);
arr[4] = new RectPrism("rectprism2", 1.0, 2.0, 3.5);
int i;
for(i=0; i<5; i++)
cout << arr[i]->volume() << endl;
for(i=0; i<5; i++)
delete arr[i];
return 0;
}
