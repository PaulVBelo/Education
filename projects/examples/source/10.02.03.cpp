int main()
{
    auto size = 5uz;

//  -------------------------------------

	auto array = new int*[size]{};

	for (auto i = 0uz; i < size; ++i)
	{
		array[i] = new int[size]{};
	}

//  -------------------------------------

	for (auto i = 0uz; i < size; ++i)
	{
		for (auto j = 0uz; j < size; ++j)
		{
			array[i][j] = j + 1;
		}
	}

//  -------------------------------------

	for (auto i = 0uz; i < size; ++i)
	{
		delete[] array[i];
	}

	delete[] array;
}