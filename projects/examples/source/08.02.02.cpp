#include <cassert>
#include <limits>

////////////////////////////////////////////////////////

int main()
{
    auto x = 1;

//  ----------------------------------------------------
		
	for (auto i = 1; i <= 100; ++i)
	{
        if (x < std::numeric_limits < int > ::max() / i)
        {
            x *= i;
        }
	}

//  ----------------------------------------------------

    assert(x == 479'001'600);
}