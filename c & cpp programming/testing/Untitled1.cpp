#include <iostream>
class Num{
    private:
        int num;
    public:
        void sum(Num n);
};

void Num::sum(Num n){
    this->num = this->num + n.num;
}
int main(){

}
