#include <cassert>
#include <string>
#include <tuple>

using namespace std::literals;

//////////////////////////////////////////////////////////////////

int main()
{
    static_assert(std::get < 0 > (std::make_tuple(1, 2, 3)) == 1);

//  --------------------------------------------------------------

    auto tuple = std::make_tuple(1, "aaaaa"s);

//  --------------------------------------------------------------

	static_assert(std::tuple_size_v < decltype(tuple) > == 2);

//  --------------------------------------------------------------

    auto x = 0;
        
    std::tie(x, std::ignore) = tuple;
        
    assert(x == 1);

//  --------------------------------------------------------------

    const auto & [y, string] = tuple; // support : cppinsights.io

    assert(y == 1 && string == "aaaaa");

//  --------------------------------------------------------------

    assert(std::tuple_cat(tuple, std::tuple <> ()) == tuple);
}