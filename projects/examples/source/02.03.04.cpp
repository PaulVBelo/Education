#include <cassert>
#include <iterator>

////////////////////////////////////////////////////////////

int main()
{
    int array[5]{ 1, 2, 3, 4, 5 };

//  --------------------------------------------------------

//	assert(sizeof(array) / sizeof(int) == 5); // bad
    
    assert(std::size(array) == 5);

//  --------------------------------------------------------
    
    assert(array[0] == 1 && 0[array] == 1 && array[1] == 2);
    
//	array[1'000] = 1; // error

//  --------------------------------------------------------
    
    assert(*array == 1 && *(array + 1) == 2);
    
//	*(array + 1'000) = 1; // error
    
    assert(array + std::size(array) - array == 5);
}