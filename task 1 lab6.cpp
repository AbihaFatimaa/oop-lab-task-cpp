# include <iostream>
# include <cstring>
# include <string>
using namespace std;
const int NAME_SIZE = 50;
const int DEPT_SIZE = 50;
class Employee{
	private:
		int id;
	    char name [NAME_SIZE];
		char dept_name [DEPT_SIZE];
	public:
		Employee():name("null"), dept_name("null"){
			id=0; 
			
		}
		Employee(int i, char nam[], char dept[]){
			id=i;
			strcpy(nam,name);
			strcpy(dept, dept_name);
		}
		Employee(int i, char nam[]):dept_name("null"){
			id=i;
			strcpy(nam, name);
		
		}
		void setId(int i){
			id=i;
		}
		void setname(char n[]){
			strcpy(name, n);
		}
		void setdept (char n[]){
			strcpy(dept_name, n);
		}
		int getId()const{
			return id;
		}
		const char* getname()const{
			return name;
		}
		const char* getdept()const{
			return dept_name;
		}
		void display(){
			cout<<"Employee ID: "<<getId()<<endl;
			cout<<"Employee name: "<<getname()<<endl;
			cout<<"Employee department: "<<getdept()<<endl;
			cout<<endl;
		}
};
int main() {
	int size;
	cout<<"enter the size of array: ";
	cin>>size;
	Employee *emp= new Employee[size];
	for(int i=0; i<size; i++){
		int id;
		char name[NAME_SIZE] ;
		char dept[DEPT_SIZE] ;
		cout<<"enter id: ";
		cin>>id;
		emp[i].setId(id);
		cout<<"enter name: ";
		cin>>name;
		emp[i].setname(name);
		cout<<"enter dept: ";
		cin>>dept;
		emp[i].setdept(dept);
	}
	for (int i=0; i<size; i++){
		cout<<"Details of employee "<<i+1<<": "<<endl;
		emp[i].display();
	}	
	delete[] emp;
	return 0;
}
