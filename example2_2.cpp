// main.cpp
// Main file for testing SFINAE
//
// Author  : Jinwook Lee
// Reviewer: Sungwook Lee
// First version: April 14, 2020
// Last update  : April 14, 2020
//

#include <iostream>
#include <type_traits>

// Example2_2: Compile (still) sucess
template <typename T>
class OddClass
{
public:
	// template <typename T> // this line is commented
	typename std::enable_if_t<std::is_integral_v<T>, bool>
	is_odd(T i) { return bool(i % 2); }
};

int main()
{
	int x = 1;
	OddClass<int> theClass;
	if (theClass.is_odd(x))
		std::cout << "x is odd" << std::endl;
	return 0;
}