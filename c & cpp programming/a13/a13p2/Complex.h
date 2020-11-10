// simple class for complex numbers

class Complex {

private:  // internal implementation is hidden
	float real;  // real part
	float imag;  // imaginary part

public:
	Complex();                 // empty constructor
	Complex(float, float = 0); // constructor taking values for real and
							   // imaginary parts. Imaginary defaults to 0
    Complex(const Complex&);    //copy constructor
    ~Complex();                 //destructor

    void setReal(float);        //setters
    void setImag(float);
    float getReal();            //getters
    float getImag();

    Complex conjugation();      //returns the conjugation

    Complex add(Complex);          //returns the sum
    Complex subtract(Complex);      //returns the difference
    Complex multiply(Complex);      //returns the product

	void print();              // prints it to the screen

	Complex operator+(const Complex &);
	Complex operator-(const Complex &);
	Complex operator*(const Complex &);
	Complex& operator=(const Complex &);
	friend std::ostream& operator<<(std::ostream& out, Complex&);
	friend std::istream& operator>>(std::istream& in, Complex&);

};



