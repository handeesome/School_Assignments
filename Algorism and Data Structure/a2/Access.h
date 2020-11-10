#include <iostream>
#include <set>
using namespace std;
class Access {
    public:
        void activate(unsigned int code);       //insert a int into set
        void deactivate(unsigned int code);     //erase a int in set
        bool isactive(unsigned int code) const; //check whether a int is in set
    private:
        set<int> passcode;
};
