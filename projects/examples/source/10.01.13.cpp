#include <array>
#include <cassert>
#include <iterator>
#include <vector>

////////////////////////////////////////////////////////////////

int main()
{
    int array[5]{ 1, 2, 3, 4, 5 };

//  ------------------------------------------------------------

//	assert(array.size() == 5); // error

	assert(std::size(array) == 5 && *std::begin(array) == 1);

//  ------------------------------------------------------------

	std::vector < int > vector = { 1, 2, 3, 4, 5 };

//  ------------------------------------------------------------

//	for (auto i = std:: size(vector) - 1; i >= 0; --i); // error

	for (auto i = std::ssize(vector) - 1; i >= 0; --i);
}