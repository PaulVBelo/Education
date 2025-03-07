#include <cassert>
#include <iostream>
#include <string>

using namespace std::literals;

#include "08.02.03.hpp"

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	Integer x = std::string(32, '1');
	
	Integer y = std::string(32, '2');

//  ----------------------------------------------------------------------------------------

	assert((x += y) == "+33333333333333333333333333333333"s);

	assert((x -= y) == "+11111111111111111111111111111111"s);

	assert((x *= y) == "+246913580246913580246913580246908641975308641975308641975308642"s);

	assert((x /= y) == "+11111111111111111111111111111111"s);

//  ----------------------------------------------------------------------------------------

	assert((x ++  ) == "+11111111111111111111111111111111"s);

	assert((  ++ y) == "+22222222222222222222222222222223"s);

	assert((x --  ) == "+11111111111111111111111111111112"s);

	assert((  -- y) == "+22222222222222222222222222222222"s);

//  ----------------------------------------------------------------------------------------

	assert((x +  y) == "+33333333333333333333333333333333"s);

	assert((x -  y) == "-11111111111111111111111111111111"s);

	assert((x *  y) == "+246913580246913580246913580246908641975308641975308641975308642"s);

	assert((x /  y) == "+0"s);

//  ----------------------------------------------------------------------------------------

	assert((x <  y) == 1);

	assert((x >  y) == 0);

	assert((x <= y) == 1);

	assert((x >= y) == 0);

	assert((x == y) == 0);

	assert((x != y) == 1);

//  ----------------------------------------------------------------------------------------

	std::cout << "main : enter Integer : "; std::cin >> x;
			
	std::cout << "main : x = " << x << '\n';

//  ----------------------------------------------------------------------------------------

	assert(sqrt(multiply(x + y, x + y)) == x + y);
}