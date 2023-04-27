#include "include/beautifulFunction.h"
#include "src/beautifulFunction.cpp"
#include "include/FlexArray.h"
#include "src/FlexArray.cpp"
#include <iostream>

/*Task 1

//a)
int var;
int f(double x, int y) {
	int z = y.compute(x);
	for (int i = 0; i < var; i++) {
		z = z.compute(y, z);
	}
	return z;
}
-> Realization wont work because:
	integers do not have a compute() function


//b) 	error: 			Member reference base type 'int' is not a structure or union
		explaination:	Int has no member functions, so int.compute(x) cannot be called
		source:			https://stackoverflow.com/questions/21387687/c-member-reference-base-type-int-is-not-a-structure-or-union
*/

/*
template<class S, class T, 5>
S f2(T x, S y) {
	S z = y.compute(x);
	for (int i = 0; i < var; i++) {
		z = z.compute(y, z);
	}
	return z;
}
*/

//d) erros only occur when .cpp body file is not included
//	 -> for templates, header and body files need to be included
//	 -> there are no other function calls to f() outside of main(), so there is nothing to comment out

int main() {

//Task 1

	//1-b)
	//f<int, double, 5>(5, 7.0);

	//1-c)
	adjustedInt fixedF = BeautilfulFunction::f<adjustedInt, double, 5>(5, 7.0);

	//=> expected value for test using my adjustedInt implementation = y + x + (var * y)
	//because:

	//adjustedInt z = y.compute(x);
	//-> z = 7.0 + 5 = 12;

	//for (int i = 0; i < 5; i++) {
	//	z = z.compute(y, z);
	//}
	//loop 5 times, each time z = y + z;
	//-> z = z + 5 * y
	//-> z = 12 + (5 * 7.0)
	//-> z = 12 + 35 = 47
	//=> expected value is 47

	//another example:
	//test = BeautilfulFunction::f<adjustedInt, double, 15>(3, 20);

	std::cout << "Result of realization of f using adjustedInt is " << fixedF.getValue() << std::endl << std::endl;





//Task 2

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

	
	std::cout << "attempting to get out of bounds index 12, expected default value of -1" << std::endl;
	std::cout << "[" << 12 << "] " << testFlex.get(12) << std::endl;
}
