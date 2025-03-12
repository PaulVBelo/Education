#include <array>

//////////////////////////////////////////////////////////////

int main()
{
    constexpr auto size = 5uz;

//  ----------------------------------------------------------

	std::array < std::array < int, size > , size > array = {};

//  ----------------------------------------------------------

	for (auto i = 0uz; i < size; ++i)
	{
		for (auto j = 0uz; j < size; ++j)
		{
			array[i][j] = j + 1;
		}
	}
}