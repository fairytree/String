#pragma once		
#include <iostream>		

class String
{
public:
	String();                     // default constructor
	explicit String(const char* a);        // constructor.  'explicit' means "implicit construction" is not allowed.  
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
	static constexpr size_t EXTRA = 10;
};

std::ostream& operator<<(std::ostream& output, const String& s);
String operator+(String lhs, const String& rhs);


