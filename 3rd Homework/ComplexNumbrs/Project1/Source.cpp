#include<iostream>
#include<cmath>

struct Complex {
	double re;
	double im;
	//todo: define the default and parametrized constructor
	//todo: define a destructor
	 // Default constructor
	Complex() : re(0.0), im(0.0) {}

	// Parameterized constructor
	Complex(double real, double imaginary) : re(real), im(imaginary) {}

	// Destructor 
	~Complex() {}
};


void Print(Complex z) {
	std::cout << z.re << (z.im >= 0 ? " + " : " - ") << std::abs(z.im) << "i" << std::endl;

}
void Arg(Complex z) {	//argument of a complex number
	double argument = std::atan2(z.im, z.re);
	std::cout << "Argument: " << argument << std::endl;

}
void Abs(Complex z) { //absolute value of a complex number
	double absoluteValue = std::sqrt(z.re * z.re + z.im * z.im);
	std::cout << "Absolute value: " << absoluteValue << std::endl;

}
void Sum(Complex z1, Complex z2, Complex& res)
{
	res.re = z1.re + z2.re;
	res.im = z1.im + z2.im;
}
void Difference(Complex z1, Complex z2, Complex& res) {
	res.re = z1.re - z2.re;
	res.im = z1.im - z2.im;
}
void Product(double d, Complex z, Complex& res) {
	res.re = d * z.re;
	res.im = d * z.im;
}
void Product(Complex z1, Complex z2, Complex& res) {
	res.re = z1.re * z2.re - z1.im * z2.im;
	res.im = z1.re * z2.im + z1.im * z2.re;
}
void Div(Complex z1, Complex z2, Complex& res) {
	double denominator = z2.re * z2.re + z2.im * z2.im;
	res.re = (z1.re * z2.re + z1.im * z2.im) / denominator;
	res.im = (z1.im * z2.re - z1.re * z2.im) / denominator;
}

int main(int argc, char* argv[])
{
	/*
	Complex z1(3, -4);
	Complex z2(-5, 2);
	todo: evaluate (2 * z1 + 3 * z2 - z1 * z2) / (z1 * z2)
*/
	Complex z1(3, -4);
	Complex z2(-5, 2);
	Complex result;

	Complex temp1, temp2;
	Product(2, z1, temp1);
	Product(3, z2, temp2);
	Difference(temp1, temp2, result);
	Product(z1, z2, temp1);
	Div(result, temp1, result);




	Print(result);
	return EXIT_SUCCESS;
}