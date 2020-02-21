#include "String.h"		

int main()
{
	String a("AAA");
	std::cout << "a: " << a << '\n' << std::endl;

	String b(a);
	b += a;         
	std::cout << "b: "<< b << '\n' << std::endl;

	String c;
	c = a;
	std::cout << "c: " << c << '\n' << std::endl;

	String d;
	d = a + b;     //??? how the code is executed???
	std::cout << "d: " << d << '\n' << std::endl;

	String e(std::move(a));
	std::cout << "e: " << e << '\n' << std::endl;
	//std::cout << a << std::endl;

	String f;
	f = std::move(b);
	std::cout << "f: " << f << '\n' << std::endl;
	//std::cout << b << std::endl;

	return 0;
}
