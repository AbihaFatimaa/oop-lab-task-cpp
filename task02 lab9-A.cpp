# include <iostream>
# include <string>
using namespace std;
class feulgauge{
	private:
		int curr;
	public:
		feulgauge(int c=0){
			curr=c;
		}
		void setFeul(int c){
			curr=c;
		}
		int getfeul(){
			return curr;
		}
		void increment(){
			if(curr<15){
				curr++;
			}
		}
		void decrement(){
			if(curr>0){
				curr--;
			}
		}
};
class odometer{
	private:
		int mileage;
	public:
		odometer(int m=0){
			mileage = m;
		}
		void setmileage(int m){
			mileage = m;
		}
		int getmileage(){
			return mileage;
		}
		void increment(feulgauge& f){
				if(f.getfeul()>0){
				mileage++;}
			
			if(mileage>999999){
				mileage =0;
			}
			if(mileage%24==0){
				f.decrement();
			}
		}
};
int main() {
	odometer o;
	feulgauge f;
	for(int i=0; i<15; i++){
		f.increment();
	}
	while(f.getfeul()>0){
		o.increment(f);
		cout<<"feul: "<<f.getfeul()<<endl<<"mileage: "<<o.getmileage()<<endl;
	}
	
	return 0;
	   }
