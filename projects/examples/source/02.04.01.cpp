#include <iostream>
#include <tuple>

////////////////////////////////////////////////////////////////

[[nodiscard]] auto test_v1(int x);

[[nodiscard]] auto test_v1(int x) 
{
	return x;
}

////////////////////////////////////////////////////////////////

void test_v2([[maybe_unused]] int x, [[maybe_unused]] int y = 0) 
{ 
	std::cout << "test_v2\n";
}

////////////////////////////////////////////////////////////////

int main()
{
//	test_v1(1); // error

    [[maybe_unused]] auto x = test_v1(1);

    std::ignore = test_v1(1);

//  ----------------------------------------------

    test_v2(1); // support : compiler-explorer.com
}