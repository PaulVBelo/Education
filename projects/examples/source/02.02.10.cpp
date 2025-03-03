#include <iostream>

////////////////////////////////////////////////////////////////////////////////

int main()
{
	for (auto i = 0uz; i < 5; ++i) // support: compiler-explorer.com
	{
		std::cout << "main : iteration (1) : i = " << i << '\n';
	}

//  ----------------------------------------------------------------------------

	for (auto i = 0uz, j = 0uz; i < 5; ++i, j += 2)
	{
		std::cout << "main : iteration (2) : i = " << i << " j = " << j << '\n';
	}

//  ----------------------------------------------------------------------------

	for (auto i = 0uz; [[maybe_unused]] auto x = i < 5; ++i)
	{
		std::cout << "main : iteration (3) : i = " << i << '\n';
	}

//  ----------------------------------------------------------------------------

//	for (auto i = 5uz; i >= 0; --i); // error
//	{
//		std::cout << "main : iteration (4) : i = " << i << '\n';
//	}
}