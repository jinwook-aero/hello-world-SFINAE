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

// Example5: Compile success - Exact type matching
template <typename T>
class OddClass
{
public:
	typename std::enable_if_t<std::is_integral_v<T>, bool> is_odd(T i);
};

template <typename T>
typename std::enable_if_t<std::is_integral_v<T>, bool> 
OddClass<T>::is_odd(T i)
{ return bool(i % 2); };

int main()
{
	int x = 1;
	OddClass<int> theClass;
	if(theClass.is_odd(x))
		std::cout << "x is odd" << std::endl;
	return 0;
}
