//bsdsf25m053
# include <iostream>
# include <string>
using namespace std;
class Date{
	private:
		int day;
		int month;
		int year;
	public:
		void setDay(int d){
			day = d;
		}
		void setMonth(int m){
			month = m;
		}
		void setYear(int y){
			year = y;
		}
		int getDay()const{
			return day;
		}
		int getMonth()const{
			return month;
		}
		int getYear()const{
			return year;
		}
		void displayDate(){
			cout<<day<<'/'<<month<<'/'<<year<<endl;
		}
};
int main(){
	Date d;
	int day,month,year;
	cout<<"enter the day";
	cin>>day;
	cout<<"enter the month:";
	cin>>month;
	cout<<"enter the year: ";
	cin>>year;
	d.setDay(day);
	d.setMonth(month);
	d.setYear(year);
	cout<<"date is: "<<endl;
	d.displayDate();
	return 0;
	
}