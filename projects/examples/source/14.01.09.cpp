#include <cassert>
#include <future>
#include <utility>

///////////////////////////////////////////////////////////////////////////////////////////////

auto test(int x) 
{ 
	return x;
}

///////////////////////////////////////////////////////////////////////////////////////////////

template < typename F, typename ... Ts > auto async_invoke(F && f, Ts && ... xs)
{
	return std::async(std::launch::async, std::forward < F > (f), std::forward < Ts > (xs)...);
}

///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	assert(std::async(std::launch::async,    test, 1).get() == 1);

	assert(std::async(std::launch::deferred, test, 1).get() == 1);

//  --------------------------------------------------------------

	assert(async_invoke(test, 1).get() == 1);
}