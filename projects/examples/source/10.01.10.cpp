#include <algorithm>
#include <cassert>
#include <functional>
#include <list>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    std::list < int > list = { 5, 4, 3, 2, 1 };

//  ----------------------------------------------------------------------------------------

//	std::ranges::sort(list); // error

//  ----------------------------------------------------------------------------------------

	std::vector < std::reference_wrapper < int > > vector(std::begin(list), std::end(list));

	std::ranges::sort(vector);

	assert(std::ranges::is_sorted(list) == 0 && std::ranges::is_sorted(vector));

//  ----------------------------------------------------------------------------------------

	list.sort();

	assert(std::ranges::is_sorted(list) == 1);
}