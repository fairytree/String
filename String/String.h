#pragma once		
#include <iostream>		

class String
{
public:
	String();                     // default constructor
	String(const char* a);        // constructor
	String(const String& s);      // copy constructor
	~String();                    // destructor
	String(String&& s);           // move constructor

	String& operator=(const String& rhs);    // assignment operator
	String& operator=(String&& rhs);		 // move assignment operator
	String& operator+=(const String& rhs);   // assignment operator
	
	friend String operator+(String lhs, const String& rhs);   // operator overloading
	friend std::ostream& operator<<(std::ostream& output, const String& s);  // operator overloading

private:
	char* _elem;
	size_t _size;
};

std::ostream& operator<<(std::ostream& output, const String& s);
String operator+(String lhs, const String& rhs);


