#include <array>
#include <cassert>
#include <tuple>
#include <type_traits>

///////////////////////////////////////////////////////////////////////////////

int main()
{
    std::array < int, 5 > array = { 1, 2, 3, 4, 5 };

//  ---------------------------------------------------------------------------

	assert(array.at(0) == 1);

//  ---------------------------------------------------------------------------

    static_assert(std::is_same_v < std::array < int, 5 > ::iterator, int * > );
}