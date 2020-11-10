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

// inheritance class of Creature, has two constructors and a new property
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
