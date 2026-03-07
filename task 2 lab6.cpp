# include <iostream>
# include <string>
using namespace std;
class Set{
	private:
		int* data;
		int noOfElements;
		int capacity;
	public:
		Set(int cap=5){
			if(cap<=0){
				capacity =5;
			}
			else{
				capacity = cap;
			}
			noOfElements = 0;
			data = new int [capacity];
		}
		Set(const Set& ref){
			capacity = ref.capacity;
			noOfElements = ref.noOfElements;
			data = new int[capacity];
			for(int i=0; i<noOfElements; i++){
				data[i] = ref.data[i];
			}
		}
		~Set(){
			delete[] data;
		}
		void insert(int element){
			data[noOfElements] = element;
			noOfElements++;
		}
		bool contain(int n){
			for(int i=0; i<noOfElements; i++){
				if(data[i] == n){
					return true;
				}
				return false;
			}
		}
		void remove(int element){
			for(int i=0; i<noOfElements; i++){
				if(data[i] == element){
					for(int j=i; j<noOfElements; j++){
						data[j] = data[j+1];
					}
					noOfElements--;
					return;
				}
			}
		}
		int getCardinality() const{
			return noOfElements;
		}
		Set calcUnion(Set& s2){
			int k=0;
			Set result(capacity+s2.capacity);
			for(int i=0; i<noOfElements; i++){
				result.data[k++] = data[i];
			}
			for(int j=0; j<s2.noOfElements; j++){
				if(!s2.contain(data[j])){
					result.data[k++] = s2.data[j];
				}
			}
			result.noOfElements=k;
			return result;
		}
		Set calcIntersection(Set& s2){
			Set result(capacity);
			int k=0;
			for(int i=0; i<noOfElements; i++){
				if(s2.contain(data[i])){
					result.data[k++] = data[i];
				}
			}
			result.noOfElements = k;
		return result;
		}
		Set calcSymmetricDifference(Set& s2){
			Set result(capacity);
			int k=0;
			for(int i=0; i<noOfElements; i++){
				if(!contain(s2.data[i])){
					result.data[k++] = data[i];
				}
			}
			for(int j=0; j<s2.noOfElements; j++){
				if(!s2.contain(data[j])){
					result.data[k++] = s2.data[j];
				}
			}
			result.noOfElements=k;
			return result;
		}
		void display(){
			cout<<"{";
			for(int i=0; i<noOfElements; i++){
				cout<<data[i];
				if(i < noOfElements-1){
					cout<<",";
				}
			}
			cout<<"}"<<endl;
			
		}
		
};
int main() {
	int size;
	cout<<"enter size: ";
	cin>>size;
	Set s1(size);
	cout<<"enter elements for set s1: ";
	for(int i=0; i<size; i++){
		int n;
		cin>>n;
		s1.insert(n);
	}
	Set s2 = s1;
	Set s3(5);
	s3.insert(2);
	s3.insert(8);
	s3.insert(6);
	
	cout<<"Cardinality of s1: "<<s1.getCardinality()<<endl;
	Set sunion = s1.calcUnion(s3);
	cout<<"union of s1 and s3: "<<endl;
	sunion.display();
	cout<<"intersection of s1 and s3: "<<endl;
	Set intersection = s1.calcIntersection(s3);
	intersection.display();
	cout<<"symmetric diffence: "<<endl;
	Set symmetric = s1.calcSymmetricDifference(s3);
	symmetric.display();
	int n;
	cout<<"enter element to remove from s1";
	cin>>n;
	s1.remove(n);
	s1.display();
	return 0;
	   }
