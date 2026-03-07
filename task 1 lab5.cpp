//bsdsf25m053
# include <iostream>
# include <string>
using namespace std;
class Circle{
	private:
		double radius;
		double pi;
	public:
		Circle(){
			radius = 0;
		}
		Circle(double r){
			radius = r;
			pi = 3.14159;
		}
		void setRadius(double r){
			radius = r;
		}
		double getRadius(){
			return radius;
		}
		double getArea(){
			double area = pi*radius*radius;
			return area;
		}
		double getDiameter(){
			return radius*2;
		}
		double getCircumference(){
			double c = 2*pi*radius;
			return c;
		}
		~Circle(){};
};
int main(){
	Circle d;
	double r;
	cout<<"enter the radius:";
	cin>>r;
	Circle c(r);
	cout<<"radius of circle is: "<<c.getRadius()<<endl;
	cout<<"diameter of circle is: "<<c.getDiameter()<<endl;
	cout<<"circumference of circle is: "<<c.getCircumference()<<endl;
	cout<<"area of circle is: "<<c.getArea()<<endl;
	return 0;
}