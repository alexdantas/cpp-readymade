/// Testing Array2D
///
/// Compile it with
///     g++ *.cpp -o test

#include <iostream>
#include "Array2D.hpp"

int main()
{
	Array2D<int> a(10, 20); // width x height

	a.at(2, 2)  = 2;
	a.at(9, 19) = 6;

	std::cout << a.at(2, 2) << " and " << a.at(9, 19) << std::endl;
	return 0;
}

