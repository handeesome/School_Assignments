
#include <iostream>

using namespace std;
//Creature is the base class which has distance as the property
class Creature {
	public:
		Creature();
		void run() const;
		void setDis(int);

	protected:
		int distance;
};

Creature::Creature(): distance(10)
{cout << "Creature constructor being called and set distance to 10\n";}

void Creature::run() const
{
    cout << "running " << distance << " metres!\n";
}

void Creature::setDis(int a){
    distance = a;
    cout << "Creature setDis method being called! Distance set to " << a << endl;
}

//Wizard is a inheritance class of Creature which has two constructors and a new property
class Wizard : public Creature {
	public:
		Wizard();
		Wizard(int);
		~Wizard();
		void hover() const;

	private:
		int distFactor;
};

Wizard::Wizard() : distFactor(3){
    cout << "Wizard empty constructor being called and distance factor set to 3" << endl;
}

Wizard::Wizard(int DF):distFactor(DF){
    cout << "Wizard parametric constructor being called! Distance factor set to "<< DF << endl;
}

Wizard::~Wizard(){
    cout << "Wizard destructor being called!" << endl;
}

void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " metres!\n";
}

//A inheritance class of Creature, has two constructors and a new property
class Flee : public Creature{
    private:
        int distFactor;
    public:
        Flee();
        Flee(int);
        ~Flee();
        void setDF(int);
        int getDF() const;
        void jump() const;
};

Flee::Flee() : distFactor(4){cout << "Flee empty constructor called, set distance factor to 4\n";}

Flee::Flee(int DF):distFactor(DF){
    cout << "Flee parametric constructor being called! Distance factor set to "<< DF << endl;
}

Flee::~Flee(){cout << "Flee destructor being called!\n";}

void Flee::setDF(int a){
    distFactor = a;
    cout << "Flee setDF method being called! Distance factor set to "<< a << endl;
}

int Flee::getDF() const{
    cout << "Flee getDF method being called!" << endl;
    return distFactor;
}

void Flee::jump() const{
    cout << "jumping " << (distFactor*distance) << " metres!\n";
}

//A inheritance class of Creature, has two constructors and a new property
class Crocodile:public Creature{
    private:
        int distFactor;
    public:
        Crocodile();
        Crocodile(int);
        ~Crocodile();
        void setDF(int);
        int getDF() const;
        void swim() const;
};

Crocodile::Crocodile():distFactor(5){cout << "Crocodile constructor called, set distance factor to 5\n";}

Crocodile::Crocodile(int DF):distFactor(DF){
    cout << "Crocodile parametric constructor being called! Distance factor set to "<< DF << endl;
}

Crocodile::~Crocodile(){cout << "Crocodile destructor being called!\n";}

void Crocodile::setDF(int a){
    distFactor = a;
    cout << "Crocodile setDF method being called! Distance factor set to "<< a << endl;
}

int Crocodile::getDF() const{
    cout << "Crocodile getDF method being called!" << endl;
    return distFactor;
}

void Crocodile::swim() const{
    cout << "swimming " << (distFactor*distance) << " metres!\n";
}

int main()
{
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    Wizard wi(100);
    wi.run();
    wi.hover();

    cout << "\nCreating a Flee.\n";
    Flee f;
    f.run();
    f.setDis(20);
    f.jump();

    Flee fl(250);
    fl.run();
    fl.jump();

    cout << "\nCreating a Crocodile.\n";
    Crocodile cr;
    cr.run();
    cr.swim();

    Crocodile cro(1314);
    cro.run();
    cro.swim();

    return 0;
}
