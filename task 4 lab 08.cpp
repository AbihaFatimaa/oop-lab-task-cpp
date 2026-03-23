//bsdsf25m053
# include <iostream>
# include <string>
# include <numeric>
using namespace std;
int abs(int x) {
    return x < 0 ? -x : x;
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class Fraction
{
	private:
		int numerator;
		int denominator;
	public:
		void display();
		void reduce();
		~Fraction();
		Fraction(int = 1, int = 1);
		Fraction operator+(const Fraction &);
		Fraction operator*(const Fraction &);
		Fraction operator/(const Fraction &);
		Fraction operator-(const Fraction &);
		void operator+=(const Fraction &);
		void operator*=(const Fraction &);
		void operator/=(const Fraction &);
		void operator-=(const Fraction &);
		bool operator==(const Fraction &);
		bool operator!=(const Fraction &);
		bool operator<=(const Fraction &);
		bool operator>=(const Fraction &);
		bool operator<(const Fraction &);
		bool operator>(const Fraction &);
		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);
		Fraction operator-();
		 operator double();
};
Fraction::~Fraction(){
}
void Fraction::display(){
	cout<<numerator<<'/'<<denominator<<endl;
}
void Fraction::reduce(){
	if(denominator == 0){
		cout<<"denominator can't be zero.";
		return;
	}
	if(denominator<0){
		numerator = -numerator;
		denominator = -denominator;
	}
	int common = gcd(abs(numerator), denominator);
	numerator/=common;
	denominator/=common;
}
Fraction::Fraction(int a, int b){
	this->numerator = a;
	this->denominator = b;
}
Fraction Fraction::operator+(const Fraction &ref){
	Fraction result;
	result.numerator = (numerator*ref.denominator) + (ref.numerator*denominator);
	result.denominator = denominator*ref.denominator;
	result.reduce();
	return result;
}
Fraction Fraction::operator*(const Fraction& ref){
	Fraction result;
	result.numerator = numerator*ref.numerator;
	result.denominator = denominator*ref.denominator;
	result.reduce();
	return result;
}
Fraction Fraction::operator/(const Fraction& ref){
	Fraction result;
	result.numerator = numerator*ref.denominator;
	result.denominator = denominator*ref.numerator;
	result.reduce();
	return result;
}
Fraction Fraction::operator-(const Fraction& ref){
	Fraction result;
	result.numerator = (numerator*ref.denominator) - (ref.numerator*denominator);
	result.denominator = denominator*ref.denominator;
	result.reduce();
	return result;
}
void Fraction::operator+=(const Fraction& ref){
	this->numerator = (this->numerator*ref.denominator) + (ref.numerator*this->denominator);
	this->denominator = this->denominator*ref.denominator;
	reduce();
}
void Fraction::operator*=(const Fraction& ref){
	this->numerator = this->numerator*ref.numerator;
	this->denominator = this->denominator*ref.denominator;
	reduce();
}
void Fraction::operator/=(const Fraction& ref){
	this->numerator= this->numerator* ref.denominator;
	this->denominator = this->denominator*ref.numerator;
	reduce();
}
void Fraction::operator-=(const Fraction& ref){
	this->numerator = (this->numerator*ref.denominator) - (ref.numerator*this->denominator);
	this->denominator = this->denominator*ref.denominator;
	reduce();
}
bool Fraction::operator==(const Fraction& ref){
	if(this->numerator * ref.denominator == ref.numerator * this->denominator){
	return true;
	}
	return false;
}
bool Fraction::operator!=(const Fraction& ref){
	if(this->numerator!=ref.numerator && this->denominator!=ref.denominator){
		return true;
	}
	return false;
}
bool Fraction::operator<=(const Fraction& ref){
	if(this->numerator==ref.numerator && this->denominator==ref.denominator){
		return true;
	}
	if(this->numerator*ref.denominator<this->denominator*ref.numerator){
		return true;
	}
	return false;
}
bool Fraction::operator>=(const Fraction& ref){
		if(this->numerator==ref.numerator && this->denominator==ref.denominator){
		return true;
	}
	if(this->numerator*ref.denominator>this->denominator*ref.numerator){
		return true;
	}
	return false;
}
bool Fraction::operator<(const Fraction& ref){
		if(this->numerator*ref.denominator<this->denominator*ref.numerator){
		return true;
	}
	return false;
}
bool Fraction::operator>(const Fraction& ref){
		if(this->numerator*ref.denominator>this->denominator*ref.numerator){
		return true;
	}
	return false;
}
Fraction Fraction::operator++(){
	this->numerator = denominator+numerator;
	reduce();	
	return *this;
}
Fraction Fraction::operator++(int){
	Fraction temp = *this;
	this->numerator = denominator+numerator;
	reduce();	
	return temp;
}
Fraction Fraction::operator--(){
	this->numerator= numerator-denominator;
	reduce();
	return *this;
}
Fraction Fraction::operator--(int){
	Fraction temp = *this;
	this->numerator=numerator-denominator;
	reduce();
	return temp;
}
Fraction Fraction::operator-(){
	this->numerator = -numerator;
	reduce();
	return *this;
}
Fraction::operator double(){
	return ((double)numerator/denominator);
}
int main() {
	Fraction a(2,3);
	Fraction b(3,4);
	cout<<"first fraction: ";
	a.display();
	cout<<"second fraction: ";
	b.display();
	Fraction c;
	c = a+b;
	cout<<"sum of two fraction: ";
	c.display();
	Fraction d;
	d = a-b;
	cout<<"subtraction of two fraction: ";
	d.display();
	Fraction e;
	e = a*b;
	cout<<"product of two fractions: ";
	e.display();
	Fraction f;
	f = a/b;
	cout<<"division of two fraction: ";
	f.display();
	cout<<"ading one fraction into other: ";
	c+=d;
	c.display();
	cout<<"subtration one from other: ";
	d-=e;
	d.display();
	cout<<"multiplying onr with other: ";
	e*=f;
	e.display();
	cout<<"dividing one with other: ";
	c/=d;
	c.display();
	cout<<endl;
	cout<<"two fraction used for equality operators are: ";
	e.display();
	f.display();
	cout<<"are fraction equal: "<< (e==f) <<endl;
    cout<<"are fraction not equal: "<< (e!=f) <<endl;
    cout<<"is one greater or equal than other: "<< (e>=f) <<endl;
    cout<<"is one smaller or equal than other: "<< (e<=f) <<endl;
    cout<<"is one smaller than other: "<< (e<f) <<endl;
    cout<<"is one greater than other: "<< (e>f) <<endl;
	Fraction g(2,3);
	cout<<"fraction g: ";
	g.display();
	cout<<"post increment: ";
	Fraction g1 = g++; g1.display();
	cout<<"pre increment: ";
	g1 = ++g;
	g1.display();
	cout<<"post decrement: ";
	g1 = g--;
	g1.display();
	cout<<"pre decrement: ";
	g1 = --g;
	g1.display();
	cout<<"taking negative of g: ";
	Fraction h = -g;
	h.display();
	cout<<"double conversion: ";
	double dg = g;
	cout<<dg;
	return 0;
	   }
