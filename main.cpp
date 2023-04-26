#include "include/beautifulFunction.h"
#include "include/FlexArray.h"
#include "src/FlexArray.cpp"
#include <iostream>

// Hier die Definition der Datentypen einf�gen, die Sie f�r
// den Aufruf der Realisation von f ben�tigen.


int main() {
	// Hier den Aufruf Ihrer Realisation von f einf�gen.



	FlexArray<int, 2, 5> testFlex(-1);

	std::cout << "default initialized value" << std::endl;

	for(int i = 0; i < testFlex.length(); i++)
	{
		std::cout << "[" << i << "] " << testFlex.get(i) << std::endl;
	}

	std::cout << "setting 1 and 3 to +1 instead" << std::endl;

	testFlex.set(1, 1);
	testFlex.set(3, 1);

	for(int i = 0; i < testFlex.length(); i++)
	{
		std::cout << "[" << i << "] " << testFlex.get(i) << std::endl;
	}

	std::cout << "attempting to set out of bounds index 7 to 2" << std::endl;
	testFlex.set(7, 2);

	for(int i = 0; i < testFlex.length(); i++)
	{
		std::cout << "[" << i << "] " << testFlex.get(i) << std::endl;
	}
}
