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

// Example3: Compile success
template <typename T>
class OddClass
{
public:
	template <typename Q = T>
	typename std::enable_if_t<std::is_integral<Q>::value, bool>
	is_odd(Q i){ return bool(i % 2); }
};

int main()
{
	int x = 1;
	OddClass<int> theClass;
	if(theClass.is_odd<int>(x))
		std::cout << "x is odd" << std::endl;
	return 0;
}
