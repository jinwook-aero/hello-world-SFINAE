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

// Example7: Approaching a hint template<typename U = T>
template <typename T>
class OddClass
{
public:
	template<typename U = T>
	typename std::enable_if_t<std::is_integral_v<U>, bool> is_odd(U i) 
	{
		std::cout << "Modular can be computed" << std::endl; 
		return bool(i % 2);
	}

	template<typename U = T>
	typename std::enable_if_t<!std::is_integral_v<U>, bool> is_odd(U i)
	{
		std::cout << "Modular cannot be computed" << std::endl; 
		return false;
	}
};

int main()
{
	int x = 1;
	double y = 1;
	OddClass<int> theClass;
	theClass.is_odd(x);
	theClass.is_odd(y);
	return 0;
}
