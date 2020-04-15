// main.cpp
// Main file for testing SFINAE
//
// Author  : Jinwook Lee
// Reviewer: Sungwook Lee
// First version: April 14, 2020
// Last update  : April 14, 2020
//

#include <iostream>
#include <type_traits> // compiler seems ok without type_traits..?!

// Example8: Finally it works
template <typename T>
class OddClass
{
public:
	template<typename U = T>
	typename std::enable_if_t<std::is_integral_v<U>, bool> is_odd(U i);

	template<typename U = T>
	typename std::enable_if_t<!std::is_integral_v<U>, bool> is_odd(U i);
};

template <typename T>
template<typename U = T>
typename std::enable_if_t<std::is_integral_v<U>, bool>
OddClass<T>::is_odd(U i)
{
	std::cout << "Modular can be computed" << std::endl;
	return bool(i % 2);
}

template <typename T>
template<typename U = T>
typename std::enable_if_t<!std::is_integral_v<U>, bool>
OddClass<T>::is_odd(U i)
{
	std::cout << "Modular cannot be computed" << std::endl;
	return false;
}

int main()
{
	int x = 1;
	double y = 1;
	OddClass<int> theClass;
	std::cout << "For x, ";  theClass.is_odd(x); std::cout << std::endl;
	std::cout << "For y, ";  theClass.is_odd(y); std::cout << std::endl;
	return 0;
}
