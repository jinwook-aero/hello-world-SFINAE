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

// Example4: Compile failure
template <typename T>
class OddClass
{
public:
	bool is_odd(T i);
};

template <typename T>
typename std::enable_if_t<std::is_integral<T>::value, bool>
OddClass<T>::is_odd(T i){ return bool(i % 2); }

int main()
{
	int x = 1;
	OddClass<int> theClass;
	if(theClass.is_odd(x))
		std::cout << "x is odd" << std::endl;
	return 0;
}

// 1 > D:\Kindergarten\hello - world - SFINAE\example4.cpp(23, 1) : error C2244 : 'OddClass<T>::is_odd' : unable to match function definition to an existing declaration

