#ifndef cstring_h
#define cstring_h
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
		CString substr(int start, int len) const;
		CString& operator=(const CString& other);
		char* getStr() const;
};
#endif