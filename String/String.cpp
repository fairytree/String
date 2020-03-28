#include "String.h"		

String::String()               // default constructor
	:_elem(new char[EXTRA]),
	_size(0)
{
	_elem[0] = '\0';
	std::cout << "default constructor" << std::endl;
}

String::String(const char* s)   // constructor 
{
	if (s) {                       // check if s is null 
		_size = strlen(s);
		_elem = new char[_size + 1];     // need to include '\0'
		strcpy_s(_elem, _size + 1, s);
	}
	else {
		throw std::runtime_error("paramter is null");   /* "throw" caues the program to exit the "}" of main().  */
	}
	std::cout << "constructor" << std::endl;
}

String::String(const String& s)   // copy constructor
{
	_elem = new char[s._size + 1];
	_size = s._size;
	strcpy_s(_elem, s._size + 1, s._elem);
	/*for (size_t i = 0; i < s._size + 1; ++i) {       // equivalent to strcpy
		_elem[i] = s._elem[i];
	}*/
	std::cout << "copy constructor" << std::endl;
}

String::String(String&& s)           // move constructor
{
	_elem = s._elem;
	_size = s._size;
	s._elem = nullptr;
	std::cout << "move constructor" << std::endl;
}


String& String::operator=(const String& rhs) // assignment operator
// The first "String&" means return the result by reference (String object itself)
// If the return type is simply "String", it means return the result by value (just a temporary String object)
// for the parameter, "String& rhs" means pass parameter by reference, any change within the function affect the variable, if without &, means pass by value (just a copy). 
{
	if (this == &rhs) {                // check if the parameter is itself, if so, the following delete step may cause crash of program. 
		return *this;
	}

	delete[] _elem;
	_elem = new char[rhs._size + 1];   // reallocate memory of correct _size
	_size = rhs._size;
	strcpy_s(_elem, rhs._size + 1, rhs._elem);
	std::cout << "assignment operator" << std::endl;
	return *this;
}

String& String::operator=(String&& rhs)   /*move assignment operator*/
{
	if (this == &rhs) {               
		return *this;
	}

	delete[] _elem;
	_elem = rhs._elem; 
	_size = rhs._size;
	rhs._elem = nullptr;
	std::cout << "move assignment operator" << std::endl;

	return *this;
}


String& String::operator+=(const String& rhs) /* operator+= overloading, pass the parameter by reference, return the result by reference. */
/* "*this += rhs" means "*this = *this + rhs, *this will be mordified after the function. */
{
	char* elem_new = new char[_size + rhs._size + 1];
		
	for (size_t i = 0; i < _size; ++i)
	{
		elem_new[i] = _elem[i];
	}
	
	for (size_t j = 0; j < rhs._size; ++j)
	{
		elem_new[_size + j] = rhs._elem[j];
	}
	elem_new[_size + rhs._size] = '\0';

	_size += rhs._size;
	delete[] _elem;
	_elem = elem_new;
	// elem_new = nullptr;         // no need to make a local variable null          
	
	std::cout << "+= operator" << std::endl;
	return *this;
}

String::~String()    // destructor, executing upon exit of "}" 
{
	delete[] _elem;           // only the memory pointed by a pointer needs to be recycled, otherwise may cause memory leaking.
	std::cout << "deconstructor" << std::endl;
}

String operator+(String lhs, const String& rhs) // operator+ overloading
// sum = lhs + rhs; we don't want lhs got mordified, therefore only pass in lhs by value (call copy constructor);		
// later, the result will be stored in another variable by assignment operator=, no need to permanently store the result, therefore only return the result by value.  		
{
	std::cout << "+ operator" << std::endl; 
	lhs += rhs; // reuse compound assignment shown above, lhs (just a copy) got modified, but the original lhs remains the same. 	
	return lhs;  // return the result by value (just a copy) (uses move constructor)	
}

//default constructor   d
//copy constructor      parameter lhs as in the operator+ function
//+ operator            + operator
//+= operator           lhs += rhs
//move constructor      return lhs
//deconstructor         destruct lhs
//move assignment operator     move value of "a + b" to d
//deconstructor                destruct "a + b"
//d : AAAAAAAAA


std::ostream& operator<<(std::ostream& output, const String& rhs)
{
	output << rhs._elem;
	return output;
}
