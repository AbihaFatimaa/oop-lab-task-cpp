//bsdsf25m053
# include <iostream>
# include <string>
using namespace std;
class SaleItem{
	private:
		int id;
		char name[41];
		int quantity;
		double price;
	public:
		void setId(int i){
			id = i;
		}
		void setName(char n[41]){
		strcpy(name,n);
		}
		void setQuantity(int q){
			quantity = q;
		}
		void setprice(double p){
			price = p;
		}
		int getId()const{
			return id;
		}
		const char getName()const{
			return name[41];
		}
		int getQuantity()const{
			return quantity;
		}
		double getprice()const{
			return price;
		}
		void incrementQuantity(int q){
			quantity+=q;
		}
		void decrementQuantity(int d){
			quantity -= d;
		}
		void displayInformation(){
			cout<<"ID: "<<id<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Quantity: "<<quantity<<endl;
			cout<<"Price: "<<price<<"rs"<<endl;
			cout<<"total price is: "<<price*quantity<<"rs"<<endl;
		}
};
int main(){
	SaleItem item;
	int id, quantity,i,d;
	char name[41];
	double price;
	cout<<"enter the id of item: ";
	cin>>id;
	cout<<"enter the name of item: ";
	cin>>name;
	cout<<"enter the quantity of item: ";
	cin>>quantity;
	cout<<"enter the price of item: ";
	cin>>price;
	cout<<"enter the quantity to increment: ";
	cin>>i;
	cout<<"enter the quantity to decrement: ";
	cin>>d;
	cout<<endl;
	item.setId(id);
	item.setName(name);
	item.setprice(price);
	item.setQuantity(quantity);
	item.incrementQuantity(i);
	item.decrementQuantity(d);
    cout<<"new quantity is: "<<item.getQuantity();
	item.displayInformation();
	cout<<endl;
	return 0;
}

