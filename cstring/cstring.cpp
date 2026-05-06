#include<iostream>
#include "cstring.h"
#include<string>
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
    int len = getLength();
    int len2 = 0;

    while(s2[len2] != '\0') len2++;

    if(len + len2 + 1 > size){
        Resize((len + len2 + 1) - size);
    }

    for(int i = 0; i < len2; i++){
        str[len + i] = s2[i];
    }

    str[len + len2] = '\0';
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
    int newsize = size + add;

    char* newstr = new char[newsize];

    int i;
    for(i = 0; i < size && str[i] != '\0'; i++){
        newstr[i] = str[i];
    }

    newstr[i] = '\0';

    delete[] str;
    str = newstr;
    size = newsize;
}
CString::CString(char* c){
    int len = 0;
    for(int i = 0; c[i] != '\0'; i++){
        len++;
    }

    size = len + 1;   // 🔥 MUST ADD THIS
    str = new char[size];

    for(int i = 0; i < len; i++){
        str[i] = c[i];
    }
    str[len] = '\0';

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
CString CString::substr(int start, int len) const {
    CString temp;
    int j = 0;

    for(int i = start; i < start + len && str[i] != '\0'; i++){
        if(j >= temp.size - 1) break;  // safety
        temp.str[j++] = str[i];
    }

    temp.str[j] = '\0';
    return temp;
}
CString& CString::operator=(const CString& other) {
        if (this != &other) {
            delete[] str;
            size = other.size;
            str = new char[size];
            strcpy(str, other.str); // or a manual loop
        }
        return *this;
    }

char* CString::getStr() const {
    return str;
}	