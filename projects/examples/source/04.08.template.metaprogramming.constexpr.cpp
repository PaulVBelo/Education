#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>

/////////////////////////////////////////////////////////////////////////////////////////

constexpr auto factorial_v1(int x) -> int { return x > 1 ? x * factorial_v1(x - 1) : 1; }

consteval auto factorial_v2(int x) -> int { return x > 1 ? x * factorial_v2(x - 1) : 1; }

/////////////////////////////////////////////////////////////////////////////////////////

consteval auto is_prime(int x)
{
	for (auto i = 2; i * i < x; ++i)
	{
		if (x % i == 0) 
		{
			return false;
		}
	}

	return x > 1;
}

/////////////////////////////////////////////////////////////////////////////////////////

consteval auto test_v1()
{
//	[[maybe_unused]] auto ptr = new auto(1); // error

	std::vector < int > vector = { 1, 2, 3, 4, 5 };

	return std::size(vector);
}

/////////////////////////////////////////////////////////////////////////////////////////

constexpr auto test_v2(int) 
{ 
	return std::is_constant_evaluated(); 
}

/////////////////////////////////////////////////////////////////////////////////////////

template < typename T, typename ... Ts > void test_v3(T x, Ts ... xs)
{
	std::cout << "test_v3 : x = " << x << ' ';
	
	std::cout << "sizeof...(xs) = " << sizeof...(xs) << '\n';

	if constexpr (sizeof...(xs) > 0) 
	{
		test_v3(xs...);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

constinit auto g_x = 1;

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	{
		constexpr auto x = 1; auto y = 2;

		[[maybe_unused]] constexpr auto result_1 = factorial_v1(x);

//		[[maybe_unused]] constexpr auto result_2 = factorial_v1(y); // error

		[[maybe_unused]]           auto result_3 = factorial_v1(x);

		[[maybe_unused]]           auto result_4 = factorial_v1(y);

		[[maybe_unused]] constexpr auto result_5 = factorial_v2(x);

//		[[maybe_unused]] constexpr auto result_6 = factorial_v2(y); // error

		[[maybe_unused]]           auto result_7 = factorial_v2(x);

//		[[maybe_unused]]           auto result_8 = factorial_v2(y); // error
	}

//  ------------------------------------------------------------------------

	{
		constexpr auto x = 1;

		assert(!is_prime(x) && test_v1() == 5);
	}

//  ------------------------------------------------------------------------

	{
		constexpr auto x = 1; auto y = 2;

		constexpr auto result_1 = test_v2(x); assert( result_1);
		
				  auto result_2 = test_v2(y); assert(!result_2);
	}

//  ------------------------------------------------------------------------

	{
		test_v3(1, 2, 3);
	}

//  ------------------------------------------------------------------------

	{
		assert(++g_x == 2);
	}
}