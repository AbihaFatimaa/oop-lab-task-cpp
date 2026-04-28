#include "iostream"
# include <string>
using namespace std;

class FeetInches
{
private:
    int feet;          // To hold a number of feet
    int inches;        // To hold a number of inches

    // Private member function to simplify the values in feet and inches
    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12);
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1);
            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Copy constructor
    FeetInches(const FeetInches& right)
    {
        feet = right.feet;
        inches = right.inches;
        simplify();
    }

    // Mutator function to set feet
    void setFeet(int f)
    {
        feet = f;
    }

    // Mutator function to set inches
    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    // Accessor function to get feet
    int getFeet() const
    {
        return feet;
    }

    // Accessor function to get inches
    int getInches() const
    {
        return inches;
    }

    // Overloaded + operator
    FeetInches operator + (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches + right.inches;
        temp.feet = feet + right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded - operator
    FeetInches operator - (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches - right.inches;
        temp.feet = feet - right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded * operator
    FeetInches operator * (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches * right.inches;
        temp.feet = feet * right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded prefix ++ operator
    FeetInches operator ++ ()
    {
        ++inches;
        simplify();

        return *this;
    }

    // Overloaded postfix ++ operator
    FeetInches operator ++ (int)
    {
        FeetInches temp(feet, inches);

        inches++;
        simplify();

        return temp;
    }

    // Overloaded prefix -- operator
    FeetInches operator -- ()
    {
        --inches;
        simplify();

        return *this;
    }

    // Overloaded postfix -- operator
    FeetInches operator -- (int)
    {
        FeetInches temp(feet, inches);

        inches--;
        simplify();

        return temp;
    }

    // Overloaded > operator
    bool operator > (const FeetInches& right) const
    {
        bool status;

        if (feet > right.feet)
            status = true;
        else if (feet == right.feet && inches > right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded < operator
    bool operator < (const FeetInches& right) const
    {
        return !(*this > right);
    }

    // Overloaded >= operator
    bool operator >= (const FeetInches& right) const
    {
        bool status;

        if (feet >= right.feet)
            status = true;
        else if (feet == right.feet && inches >= right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded <= operator
    bool operator <= (const FeetInches& right) const
    {
        return !(*this >= right);
    }

    // Overloaded == operator
    bool operator == (const FeetInches& right) const
    {
        bool status;

        if (feet == right.feet && inches == right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded != operator
    bool operator != (const FeetInches& right) const
    {
        return !(*this == right);
    }

    // Friend function to overload << operator for output
    friend ostream& operator << (ostream&, const FeetInches&);

    // Friend function to overload >> operator for input
    friend istream& operator >> (istream&, FeetInches&);
};

// Overloaded << operator
ostream& operator << (ostream& out, const FeetInches& obj)
{
    out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

    return out;
}

// Overloaded >> operator
istream& operator >> (istream& in, FeetInches& obj)
{
    cout << "Enter Feet:\t";
    in >> obj.feet;

    cout << "Enter Inches:\t";
    in >> obj.inches;

    return in;
}
class roomdimension{
	private:
		FeetInches len;
		FeetInches wid;
	public:
		roomdimension(int l, int i, int w, int f):len(l,i), wid(w,f){
		};
		void setlen(int l, int i){
			len.setFeet(l);
			len.setInches(i);
		};
		void setwid(int w, int i){
			wid.setFeet(w);
			wid.setInches(i);
		};
		void getlen(){
		cout<<"len: "<<	len.getFeet();
			cout<<"wid: "<<len.getInches();
		}
		void getwid(){
		cout<<"len: "<<	wid.getFeet();
			cout<<"wid: "<<wid.getInches();
		}
		int getarea(){
			int area = len.getFeet()*wid.getFeet();
			return area;
		}
		void display(){
			cout<<len;
			cout<<wid;
		}
};
class roomcarpet{
	private:
	roomdimension roomsize;
	float costpersquarefoot;
	public:
		roomcarpet(int i, int w, int l, int f, float g):roomsize(i,w,l,f), costpersqquarefoot(g){
		};
		void setdimension(int f, int i, int w, int l){
			roomsize.setlen(f,i);
			roomsize.setwid(w,l);
		}
		void setcost(float c){
			costpersquarefoot = c;
		}
		void getdimension(){
			roomsize.display();
		}
		float getcost(){
			return costpersquarefoot;
		}
		float totalcost(){
			float a;
			a=roomsize.getarea()*costpersquarefoot;
			return a;
		}
		void displayroom(){
			roomsize.display();
			cout<<costpersquareinch<<endl;
		}
};
int main(){
	int l,i,w,f;
	float c;
	cout<<"enter length in feet and inches: "<<endl;
	cin>>l,i;
	cout<<"enter width in feet and inches: "<<endl;
	cin>>w,f;
	cout<<"enter cost of per square foot: "<<endl;
	cin>>c;