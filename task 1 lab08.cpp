//bsdsf25m053
# include <iostream>
# include <string>
using namespace std;
class ComplexNumber{
	private:
		double real;
		double imaginary;
	public:
		ComplexNumber(double = 0.0, double = 0.0);
		void display();
		ComplexNumber operator+(const ComplexNumber & ref);
		ComplexNumber operator-(const ComplexNumber & ref);
		ComplexNumber operator*(const ComplexNumber & ref);
		ComplexNumber operator/(const ComplexNumber & ref);
};
ComplexNumber::ComplexNumber(double a, double b){
	this->real = a;
	this->imaginary = b; 
}
void ComplexNumber::display(){
	char sign = '+';
	cout<<real;
	if(imaginary<0){
	cout<<imaginary<<'i'<<endl;
	}
	else{
	cout<<sign<<imaginary<<'i'<<endl;
}
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& ref){
	ComplexNumber c;
	c.real = real+ref.real;
	c.imaginary = imaginary+ ref.imaginary;
	return c;
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& ref){
	ComplexNumber c;
	c.real= real-ref.real;
	c.imaginary = imaginary-ref.imaginary;
	return c;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& ref){
	ComplexNumber mul;      //(a + bi)(c + di) = ac + bci + adi + bd i 2 = (ac-bd) + (bc+ad)i
	mul.real = (real*ref.real)-(imaginary*ref.imaginary);
	mul.imaginary = (imaginary*ref.real)+(real*ref.imaginary);
	return mul;
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& ref){
	ComplexNumber div;
	div.real = ((real*ref.real)+(imaginary*ref.imaginary))/(ref.real*ref.real+ref.imaginary*ref.imaginary);
	div.imaginary = ((imaginary*ref.real)-(real*ref.imaginary))/(ref.real*ref.real+ref.imaginary*ref.imaginary);
	return div;
}
int main() {
	ComplexNumber a(2,3);
	ComplexNumber b(4,5);
	cout<<"first complex number: ";
	a.display();
	cout<<"second complex number: ";
	b.display();
	ComplexNumber add = a+b;
	cout<<"result of addition: ";
	add.display();
	ComplexNumber sub = a-b;
	cout<<"result of subtraction: ";
	sub.display();
	ComplexNumber mul = a*b;
	cout<<"result of multipplication: ";
	mul.display();
	ComplexNumber div = a/b;
	cout<<"result of division: ";
	div.display();
	return 0;
	   }
