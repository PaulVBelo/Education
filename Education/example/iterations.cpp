#include <iostream>

int main()
{
	const auto size = 5;

	for (auto i = 0; i < size; ++i)
	{
		std::cout << "for 1: " << i << '\n';
	}

	for (auto i = 0, j = 0; i < size; ++i, j += 2)
	{
		std::cout << "for 2: " << i << ' ' << j << '\n';
	}

	for (auto i = 0; auto x = (i + 1) % size; ++i)
	{
		std::cout << "for 3: " << i << '\n';
	}

	for (auto i = size; i >= 0; --i)
	{
		if (i % 2 == 0)
		{
			continue;
		}

		std::cout << "for 4: " << i << '\n';
	}

	for (auto i = 0; i < size; ++i)
	{
		std::cout << "for 5: ";

		for (auto j = 0; j < size; ++j)
		{
			if (j > i)
			{
				break;
			}

			std::cout << j << ' ';
		}

		std::cout << '\n';
	}

	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size; ++j)
		{
			for (auto k = 0; k < size; ++k)
			{
				std::cout << "for 6: " << i << ' ' << j << ' ' << k << '\n';

				if (auto stop = size / 2; i == stop && j == stop && k == stop)
				{
					goto exit;
				}
			}
		}
	}

	exit:

	char c{};

	while (c != 'n')
	{
		std::cout << "Continue (y/n) ? ";

		std::cin >> c;
	}

	do
	{
		std::cout << "Continue (y/n) ? ";

		std::cin >> c;
	} 
	while (c != 'n');

	for (;;)
	{
		std::cout << "Continue (y/n) ? ";

		std::cin >> c;

		if (c == 'n')
		{
			break;
		}
	}

	while (true)
	{
		std::cout << "Continue (y/n) ? ";

		std::cin >> c;

		if (c == 'n')
		{
			break;
		}
	}

	return 0;
}