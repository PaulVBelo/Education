/////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>

/////////////////////////////////////////////////////////////////

int main()
{
	bool array[5]{};

//  -------------------------------------------------------------

	static_assert(sizeof(array) == 5);

//  -------------------------------------------------------------

	std::vector < bool > vector(1'000'000'000, false);

//  -------------------------------------------------------------
 
	auto proxy = vector.front();

//  -------------------------------------------------------------

	static_assert(std::is_same_v < decltype(proxy), bool > == 0);

//  -------------------------------------------------------------

	assert(static_cast < bool > (proxy) == false);

//  -------------------------------------------------------------

	std::cout << "main : enter char : "; std::cin.get();
}

/////////////////////////////////////////////////////////////////