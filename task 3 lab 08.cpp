//bsdsf25m053
# include <iostream>
# include <string>
using namespace std;
class CString{
	private:
		char* str;
		int size;
	public:
		CString();
		CString (char c);
		CString (const CString& c);
		CString(char*c);
		int getLength()const;
		~CString();
		void display()const;
		int find( char* substr , int start=0 )const;
		int find( char ch, int start=0 )const;
		int insert ( int index, char* substr);
		int insert ( int index, char ch);
		CString left ( int count )const;
		CString right ( int count )const;
		int remove( int index, int count=1);
		int remove ( char ch );
		void replace( char neww );
		int replace( char old, char neww );
		int replace( char* old, char* neww );
		void trim( );
		void trimLeft();
		void trimRight();
		void makeUpper ();
		void makeLower ();
		void reverse( );
		void Resize( int add);
		CString concat ( const CString& s2 )const;
		void concatEqual ( const CString& s2 );
		void concatEqual (char* s2 );
		int isEqual ( const CString & s2 )const;
		int isEqual (char* s2)const;
		void input ();
		int isEmpty();
		char& at (int index);
		CString & operator =(const CString & ref);
		CString operator+(const CString & s2) const;
		CString operator+(const char* const s2) const;
		void operator +=(const CString & s2);
		void operator +=(const char* s2);
};
void CString::operator +=(const CString& s2){
	int len = getLength();
	int newlen = len+s2.getLength();
	if(newlen>size){
		Resize(newlen+1-size);
	}
	int k=len;
	for(int i=0; s2.str[i]!='\0'; i++){
		str[k++] = s2.str[i];
	}
	str[k] = '\0';
	
}
void CString::operator +=(const char* s2){
		int len=getLength();
	int len2 = 0;
	while(s2[len2]!='\0'){
		len2++;
	}
	int newlen = len+len2;
	if(newlen>size){
		Resize(newlen+1-size);
	}
	int k=len;
	for(int i=0; s2[i]!='\0'; i++){
		str[k++] = s2[i];
	}
	str[k]='\0';

}
CString CString::operator+(const char* const s2)const{
	CString newstr;
	int j=0;
	for(int i=0; str[i]!='\0'; i++){
		newstr.str[j++] = str[i];
	}
	for(int k=0; s2[k]!='\0'; k++){
		newstr.str[j++] = s2[k];
	}
	newstr.str[j] = '\0';
	return newstr;
}
CString CString::operator+(const CString& s2)const{
	CString newstr;
	int j=0;
	for(int i=0; str[i]!='\0'; i++){
		newstr.str[j++] = str[i];
	}
	for(int k=0; s2.str[k]!='\0'; k++){
		newstr.str[j++] = s2.str[k];
	}
	newstr.str[j] = '\0';
	return newstr;
}
CString& CString::operator =(const CString& ref){
	if(this == &ref){
		return *this;
	}
		this->~CString();
	size = ref.size;
	str = new char[size];
	int i;
	for(i=0; ref.str[i]!='\0'; i++){
		str[i] = ref.str[i];
	}
	str[i]='\0';
	return *this;
}
char& CString::at(int index){
	return str[index];
}
int CString::isEmpty(){
	if(str[0]=='\0'){
		return 0;
	}
	return 1;
}
void CString::input(){
	char temp[100];
	cout<<"enter the string";
	cin.getline(temp, 100);
	int len =0;
	while(temp[len]!='\0'){
		len++;
	}
	if(len>size){
		Resize(len+1-size);
	}
	int i;
	for(i=0; i<len; i++){
		str[i] = temp[i];
	}
	str[i] = '\0';
}
int CString::isEqual(char* s2)const{
	int i;
	for(i=0;str[i]!='\0'&& s2[i]!='\0'; i++){
		if(str[i]>s2[i]){
			return 1;
		}
		if(str[i]<s2[i]){
			return -1;
		}
	}
	if(str[i]=='\0'&& s2[i]=='\0'){
		return 0;
	}
	if(str[i]=='\0'){
		return -1;
	}
	else{
		return 1;
	}
}
int CString::isEqual(const CString& s2)const{
	int i;
	for(i=0; str[i]!='\0'&&s2.str[i]!='\0'; i++){
		if(str[i]>s2.str[i]){
			return 1;
		}
		if(str[i]<s2.str[i]){
			return -1;
		}
	}
	if(str[i]=='\0' && s2.str[i]=='\0'){
		return 0;
	}
	if(str[i]=='\0'){
		return -1;
	}
	else{
		return 1;
	}
}
void CString::concatEqual(char* s2){
	int len=getLength();
	int len2 = 0;
	while(s2[len2]!='\0'){
		len2++;
	}
	int newlen = len+len2;
	if(newlen>size){
		Resize(newlen+1-size);
	}
	int k=len;
	for(int i=0; s2[i]!='\0'; i++){
		str[k++] = s2[i];
	}
	str[k]='\0';
}
void CString::concatEqual(const CString& s2){
	int len = getLength();
	int newlen = len+s2.getLength();
	if(newlen>size){
		Resize(newlen+1-size);
	}
	int k=len;
	for(int i=0; s2.str[i]!='\0'; i++){
		str[k++] = s2.str[i];
	}
	str[k] = '\0';
}
CString CString::concat(const CString& s2)const{
	CString newstr;
	int j=0;
	for(int i=0; str[i]!='\0'; i++){
		newstr.str[j++] = str[i];
	}
	for(int k=0; s2.str[k]!='\0'; k++){
		newstr.str[j++] = s2.str[k];
	}
	newstr.str[j] = '\0';
	return newstr;
} 
void CString::Resize(int add){
	int newsize=size+add;
	char* newstr = new char[newsize];
	int i;
	for(i=0; i<size; i++){
		newstr[i] = str[i];
	}
	newstr[i] = '\0';
	delete[]str;
	size = newsize;
	str = newstr;
}
CString::CString(char* c){
	int len=0;
	for(int i=0; c[i]!='\0'; i++){
		len++;
	}
	str = new char[len];
	for(int i=0;i<len; i++){
		str[i] = c[i];
	}
	str[len]='\0';
} 
void CString::reverse(){
	int len = getLength();
	for(int i=0; i<len/2; i++){
		int temp = str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=temp;
	}
}
void CString::makeLower(){
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]>='A' && str[i]<='Z'){
			str[i] = str[i]+32;
		}
	}
}
void CString::makeUpper(){
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]>='a' && str[i]<='z'){
			str[i] = str[i]-32;
		}
	}
}
void CString::trimRight(){
	for(int i=getLength()-1; i>=0; i--){
		if(str[i]==' '){
			str[i] = '\0';
		}
	}
}
void CString::trimLeft(){
	int i=0;
	while(str[i]==' '){
		i++;
	}
	int j;
	for(j=0; str[j]!='\0'; j++){
		str[j] = str[j+1];
	}
	str[j] = '\0';
}
void CString::trim(){
	int start=0;
	int end = getLength()-1;
	while(str[start]==' '){
		start++;
	}
	while(str[end]==' '){
		end--;
	}
	int i;
	for(i=0; start<=end; i++){
		str[i] = str[start];
		start++;
	}
	str[i]='\0';
}
int CString::replace(char* old, char* neww){
	int count=0;
	int oldlen=0; int newlen=0;
	while(old[oldlen]!='\0'){
		oldlen++;
	}
	while(neww[newlen]!='\0'){
		newlen++;
	}
	for(int i=0; str[i]!='\0'; i++){
		int j=0; 
		while(str[i+j] == old[j]&&old[j]!='\0'){
			j++;
		}
		if(j==oldlen){
			count++;
			int len=getLength();
			if(oldlen>newlen){
				for(int k=i+newlen;k<=len-(oldlen-newlen); k++){
					str[k]=str[k+(oldlen-newlen)];
				}
			}
			else if(newlen>oldlen){
				for(int k=len; k>=i+(oldlen); k--){
					str[k+oldlen]=str[k];
				}
			}
			for(int u=0; u<newlen; u++){
				str[i+u]=neww[u];
			}
			i+=newlen;
		}
	}
	return count;
}
int CString::replace(char old, char neww){
	int count=0;
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]==old){
			str[i]=neww;
			count++;
		}
	}
	return count;
}
void CString::replace(char neww){
	int i;
	for( i=0; str[i]!='\0'; i++){
			str[i]=neww;
	}
}
int CString::remove(char ch){
	int count=0;
	for(int i=0; str[i]!='\0';){
		if(str[i]==ch){
			count++;
			for(int j=i; str[j]!='\0'; j++){
				str[j] = str[j+1];
			}
		}
		else{
			i++;
		}
	}
	return count;
}
int CString::remove(int index, int count){
	int len = getLength();
	if(index+count>len){
		count = len-index;
	}
	for(int i=index;i<=len-count; i++){
		str[i] = str[i+count];
	}
	return getLength();
}
CString CString::right(int count)const{
	CString temp(size);
	int len = getLength();
	int start;
	if(count>=len){
		start =0;
	}
	else{
		start = len - count;
	}
	int i;
	for(i=0; str[start]!='\0';i++){
		temp.str[i]  = str[start];
		start++;
	}
	temp.str[i] = '\0';
	return temp;
}
CString CString::left(int count)const{
	CString temp(size);
	int i;
	for(i=0; i<count&&str[i]!='\0'; i++){
		temp.str[i] = str[i];
	}
	temp.str[i] = '\0';
	return temp;
	
}
int CString::insert(int index, char ch){
 	int len = getLength();
 	for(int i=len; i>=index; i--){
 		str[i+1] = str[i];
	 }
	 for(int j=0; j<1; j++){
	 	str[index+j] = ch;
	 }
	 return getLength();
}
int CString::insert(int index, char* substr){
	int lenstr = getLength();
	int lensub = 0;
	while(substr[lensub]!='\0'){
		lensub++;
	}
	for(int i=lenstr; i>=index; i--){
		str[i+lensub] = str[i];
	}
	for(int j=0; j<lensub; j++){
		str[index+j] = substr[j];
	}
	return getLength();
}
int CString::find(char ch, int start)const{
	for(int i=start; str[i]!='\0'; i++){
		if(str[i] == ch){
			return i;
		}
	}
	return -1;
}
int CString::find(char* substr, int start)const{
	for(start; str[start]!='\0'; start++){
		int j=0;
		while(substr[j]!='\0'&& str[start+j]==substr[j]){
			j++;
		}
		if(substr[j]=='\0'){
			return start;
		}
}
	return -1;
}
void CString::display()const{
	for(int i=0;str[i]!='\0'; i++){
		cout<<str[i];
	}
	cout<<endl;
}
int CString::getLength()const{
	int len=0;
	for(int i=0; str[i] != '\0'; i++){
		len++;
	}
	return len;
}
CString::CString(){
	size = 100;
	str= new char[size];
	str[0] = '\0';
}
CString::CString(char c){
	size = 100;
	str = new char[size];
	str[0] = c;
	str[1]='\0';
}
CString::CString(const CString& c){
	size = c.size;
	str = new char[size];
	int i;
	for(i=0; c.str[i]!='\0'; i++){
		str[i] = c.str[i];
	}
	str[i]='\0';
}
CString::~CString(){
	delete[]str;
}
int main() {
	CString c1;
	CString c2('a');
	cout<<"parameterized constructor: ";
	c2.display();
	CString c3("hi");
	cout<<"conversion constructor: ";
	c3.display();
	CString c4(c2);
	cout<<"copy coonstructor: ";
	c4.display();
	cout<<"length of c3: "<<c3.getLength()<<endl;
	cout<<"value at index 1: "<<c3.at(1)<<endl;
	CString c5("hello");
	CString c6 = c5.concat(c3);
	cout<<"after concateneation of c5 and c3: ";
	c6.display();
	c3.concatEqual(c4);
	cout<<"after concatenation of c3 and c4: ";
	c3.display();
	c4.concatEqual("bcd");
	cout<<"after concatenation of c4 with a string: ";
	c4.display();
	cout<<"c5 is equal to c6: "<<c5.isEqual(c6)<<endl;
	cout<<"c5 is equal to 'hello': "<<c5.isEqual("hello")<<endl;
	cout<<"find hel in c5: "<<c5.find("hel", 0)<<endl;
	cout<<"find e in c5: "<<c5.find('e', 0)<<endl;
	cout<<"inserting world in c5: "<<c5.insert(5,"world")<<endl;
	c5.display();
	cout<<"inserting 2 in c4: "<<c4.insert(3, '2');
	c4.display();
	CString c7("programming world ");
	CString left = c7.left(4);
	cout<<"left by 4: ";
	left.display();
	CString right = c7.right(3);
	cout<<"right by 3: ";
	right.display();
	cout<<"after removing from 3 index and 2 count: "<<c7.remove(3,2)<<endl;
	c7.display();
	cout<<"after removing p from c7, new len: "<<c7.remove('p')<<endl;
	c7.display();
	cout<<"replacing c2 with char 'e': ";
	c2.replace('e');
	c2.display();
	cout<<"replacing 'm' with 'w'in c7: ";
	c7.replace('m', 'w');
	c7.display();
	cout<<"replacing 'h' with 'd' in c3: ";
	c3.replace('h','a');
	c3.display();
	CString c8("byebye");
	cout<<"lower to upper: ";
	c8.makeUpper();
	c8.display();
	CString c9("ABCD");
	cout<<"upper to lower: ";
	c9.makeLower();
	c9.display();
	CString c10(" hello ");
	cout<<"trim: ";
	c10.trim();
	c10.display();
	CString c11(" welcome");
	cout<<"trim left: ";
	c11.trimLeft();
	c11.display();
	CString c12(" hii ");
	cout<<"trim right: ";
	c12.trimRight();
	c12.display();
	cout<<"reversing c12: ";
	c12.reverse();
	c12.display();
	CString c13;
	c13.input();
	cout<<"you eneterd: ";
	c13.display();
	CString c14;
	cout<<"is empty: "<<c14.isEmpty();
	cout<<endl;
	CString c15('a');
	cout<<"is empty: "<<c15.isEmpty();
	cout<<endl;
	cout<<"results with operators overloading: ";
	CString a("operator");
	CString b("overloading");
	CString d;
	d=a+b;
	cout<<"result of + operator with cstring: "<<endl;
	d.display();
	CString e;
	e = a+'a';
	cout<<"result of + operator with char: "<<endl;
	e.display();
	d+=a;
	cout<<"result of += operator with cstring: "<<endl;
	d.display();
	e+='q';
	cout<<"result of += operator with char: "<<endl;
	e.display();
	a=b;
	cout<<"assignment operator: "<<endl;
	a.display();
	return 0;
	   }
