#include <iostream>
#include "cstring.h"
#include <string>
using namespace std;
class DessertShoppe
{
	private:
	static const double taxRate;
	static const string storeName;
	static const int maxItemNameSize;
	static const int costWidth;
	public:
	static string cents2dollarsAndCents(int cents)
	{
	string s = "";
	if (cents < 0)
	{
	s += "-";
	cents *= -1;
	}
	int dollars = cents / 100;
	cents = cents % 100;
	if (dollars > 0)
	s += dollars;
	s += ".";
	if (cents < 10)
	s += "0";
	s += cents;
	return s;}
	static int getMaxItemNameSize()
	{
	return maxItemNameSize;
	}
	static double getTaxRate(){return taxRate;
	}
	static string getstoreName(){return storeName;
	}
	//getter for rest of the static members
	};
	const double DessertShoppe::taxRate = 6.5; //6.5%
	const string DessertShoppe::storeName = "M & M Dessert Shoppe";
	const int DessertShoppe::maxItemNameSize = 25;
	const int DessertShoppe::costWidth = 6;
class DessertItem
{
	private:
		CString name;
	public:
		DessertItem()
		{}
		DessertItem(CString name){
			if (name.getLength() <= DessertShoppe::getMaxItemNameSize())
			this->name = name;
			else
			this->name = name.substr(0, DessertShoppe::getMaxItemNameSize());		
		}
		
		CString getName() const{
			return name;
		}
		virtual int getCost() = 0;
		//virtual ~DessertItem();
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Candy: public DessertItem{
	private:
		double weight;
		int pricePerPound;
	public:
		Candy(CString c, double d=0.0, int p=0):DessertItem(c){
			weight = d;
			this->pricePerPound = p;
		}
		int getCost(){
			return weight*pricePerPound+0.5;
		}
		double getWeight() { return weight; }
int getPricePerPound() { return pricePerPound; }
};
class Cookie:public DessertItem{
	private:
		int no;
		int pricePerDozen;
	public:
		Cookie(CString c, int n=0, int p=0):DessertItem(c){
			no = n;
			pricePerDozen =p;
		}
		int getCost(){
		return ((no * pricePerDozen / 12.0) + 0.5);
		}
		int getNumber() { return no; }
int getPricePerDozen() { return pricePerDozen; }
};
class IceCream:public DessertItem{
	private:
		int cost;
	public:
		IceCream(CString c, int d =0):DessertItem(c){
			cost = d;
		}
		int getCost(){
			return cost;
		}
};
class Sundae:public IceCream{
	private:
		int topping;
		string tname;
	public:
		Sundae(CString c, int d, string t="", int tc=0):IceCream(c,d){
			topping = tc;
			tname = t;
		}
		int getCost(){
			return IceCream::getCost()+topping;
		}
		string getToppingName(){return tname;
		}
		int getToppingCost() { return topping; }
};
class Checkout{
	private:
		DessertItem** item;
		int count;
		int capacity;
	public:
		Checkout(){
			count = 0;
			capacity = 10;
			item = new DessertItem*[capacity];
		}
		void resize() {
	        capacity *= 2;
	        DessertItem** temp = new DessertItem*[capacity];
	        for(int i = 0; i < count; i++)
	            temp[i] = item[i];
	
	        delete[] item;
	        item = temp;
    }
		void clear(){
			for(int i=0; i<count; i++){
				delete item[i];
			}
			count = 0;
			
		}
		void enterItem(DessertItem* i){
			if(capacity == count){
				resize();
			}
			item[count++] = i;
		}
		 int numberOfItems() {
        return count;
    }
    	int totalCost() {
	        int total = 0;
	        for(int i = 0; i < count; i++)
	            total += item[i]->getCost();
	        return total;
    }
      int totalTax() {
        return (totalCost() * DessertShoppe::getTaxRate() / 100 + 0.5);
    }
	~Checkout(){
		clear();
		delete []item;
	}
	CString toString()
{
    CString receipt;

    receipt.concatEqual((char*)DessertShoppe::getstoreName().c_str());
    receipt.concatEqual("\n-------------------------\n");

    for(int i = 0; i < count; i++)
    {
        DessertItem* itemPtr = item[i];

        // ================= CANDY =================
        Candy* c = dynamic_cast<Candy*>(itemPtr);
        if(c)
        {
            CString line;

            line.concatEqual("Candy ");
            line.concatEqual(c->getName());
            line.concatEqual(" ");

            string cost = DessertShoppe::cents2dollarsAndCents(c->getCost());
            line.concatEqual((char*)cost.c_str());

            receipt.concatEqual(line.getStr());
            receipt.concatEqual("\n");

            continue;
        }

        // ================= COOKIE =================
        Cookie* ck = dynamic_cast<Cookie*>(itemPtr);
        if(ck)
        {
            CString line;

            line.concatEqual("Cookie ");
            line.concatEqual(ck->getName());
            line.concatEqual(" ");

            string cost = DessertShoppe::cents2dollarsAndCents(ck->getCost());
            line.concatEqual((char*)cost.c_str());

            receipt.concatEqual(line.getStr());
            receipt.concatEqual("\n");

            continue;
        }

        // ================= SUNDAE =================
        Sundae* s = dynamic_cast<Sundae*>(itemPtr);
        if(s)
        {
            CString line;

            line.concatEqual((char*)s->getToppingName().c_str());
            line.concatEqual(" Sundae with ");
            line.concatEqual(s->getName());
            line.concatEqual(" ");

            string cost = DessertShoppe::cents2dollarsAndCents(s->getCost());
            line.concatEqual((char*)cost.c_str());

            receipt.concatEqual(line.getStr());
            receipt.concatEqual("\n");

            continue;
        }

        // ================= ICE CREAM =================
        IceCream* ic = dynamic_cast<IceCream*>(itemPtr);
        if(ic)
        {
            CString line;

            line.concatEqual("IceCream ");
            line.concatEqual(ic->getName());
            line.concatEqual(" ");

            string cost = DessertShoppe::cents2dollarsAndCents(ic->getCost());
            line.concatEqual((char*)cost.c_str());

            receipt.concatEqual(line.getStr());
            receipt.concatEqual("\n");
        }
    }

    // ================= TAX =================
    receipt.concatEqual("Tax ");
    string tax = DessertShoppe::cents2dollarsAndCents(totalTax());
    receipt.concatEqual((char*)tax.c_str());
    receipt.concatEqual("\n");

    // ================= TOTAL =================
    receipt.concatEqual("Total Cost ");
    string total = DessertShoppe::cents2dollarsAndCents(totalCost() + totalTax());
    receipt.concatEqual((char*)total.c_str());

    return receipt;
}
	friend ostream& operator<<(ostream& out, Checkout& c);
};
ostream& operator<<(ostream& out, Checkout& c) {
    CString s = c.toString();

    for(int i = 0; i < s.getLength(); i++){
        out << s.at(i);
    }

    return out;
}

int main(int argc, char** argv) {
	Checkout checkout;
checkout.enterItem(new Candy("Peanut Butter Fudge", 2.25, 399));
checkout.enterItem(new IceCream("Vanilla Ice Cream", 105));
checkout.enterItem(new Sundae("Choc. Chip Ice Cream", 145, "Hot Fudge", 50));
checkout.enterItem(new Cookie("Oatmeal Raisin Cookies", 4, 399));
cout << "\nNumber of items: " << checkout.numberOfItems() << "\n";
cout << "\nTotal cost: " << checkout.totalCost() << "\n";
cout << "\nTotal tax: " << checkout.totalTax() << "\n";
cout << "\nCost + Tax: " << (checkout.totalCost() + checkout.totalTax()) <<
"\n"; 
cout << checkout;
checkout.clear();
checkout.enterItem(new IceCream("Strawberry Ice Cream", 145));
checkout.enterItem(new Sundae("Vanilla Ice Cream", 105, "Caramel", 50));
checkout.enterItem(new Candy("Gummy Worms", 1.33, 89));
checkout.enterItem(new Cookie("Chocolate Chip Cookies", 4, 399));
checkout.enterItem(new Candy("Salt Water Taffy", 1.5, 209));
checkout.enterItem(new Candy("Candy Corn", 3.0, 109));
cout << "\nNumber of items: " << checkout.numberOfItems() << "\n";
cout << "\nTotal cost: " << checkout.totalCost() <<"\n";
cout << "\nTotal tax: " << checkout.totalTax() << "\n";
cout << "\nCost + Tax: " << checkout.totalCost() << checkout.totalTax() <<
"\n"; cout << checkout;
	return 0;
}