# include <iostream>
# include <string>
# include <cstring>
using namespace std;
class teacher{
	private:
		char name [40] ;
		int extNo;
	public:
		teacher(const char n[] = "", int i=0){
			strcpy(name, n);
			extNo = i;
		}
		void display(){
			cout<<" name :"<<name;
			cout<<endl<<"extension no: "<<extNo<<endl;
		}
		teacher(const teacher& t){
			strcpy(name, t.name);
			extNo = t.extNo;
		}
		teacher& operator=(const teacher& t){
			strcpy(name ,t.name);
			extNo = t.extNo;
			return* this;
		}
};
class classroom{
	private:
	int roomNo;
	int capacity;
	public:
		classroom(int r=0, int c=0){
			roomNo = r;
			capacity = c;
		}
		void display(){
			cout<<"room no: "<<roomNo<<endl<<"capacity: "<<capacity<<endl;
		}
		classroom(const classroom& c){
			roomNo = c.roomNo;
			capacity = c.capacity;
		}
		classroom& operator=(const classroom& c){
			roomNo = c.roomNo;
			capacity = c.capacity;
			return* this;
		}
};
class course{
	private:
		char courset [20];
		teacher t;
		classroom c;
	public:
		course(char n[], int i, int r, int j, char a[]):t(n,i), c(r,j){
			strcpy(courset, a);
		}
		void display(){
			cout<<"course title: "<<courset<<endl;
			t.display();
			c.display();
		}
		course(const course& co):t(co.t), c(co.c){
			strcpy(courset, co.courset);
		}
		course& operator=(const course& e){
			t=(e.t);
			c=(e.c);
			strcpy(courset, e.courset);
			return * this;
		}
		course(const teacher& a, const classroom& b, char co[]):t(a), c(b){
			strcpy(courset, co);
		}
};
int main() {
	course a1("abdullah", 23, 25,50, "oop" );
	course b1("arifa", 12, 26, 45, "physics");
	int a,b,c,d;
	char ac[40];
	char ab[20];
	cout<<"enter details of course: "<<endl;
	cin.getline(ac,40);
	cin>>a>>b>>c;
	cin.ignore();
	cin.getline(ab,20);
	cout<<ac<< ab;
	course c1(ac,a,b,c,ab);
	course* d1 = new course(ac,a,b,c,ab);
	a1.display();
	b1.display();
	c1.display();
	d1->display();
	teacher t ("ab", 1);
	classroom e(12,13);
	course e1(t,e,ab);
	e1.display();
	delete d1;
	return 0;
	   }
