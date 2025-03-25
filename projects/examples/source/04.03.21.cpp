#include <concepts>
#include <type_traits>

///////////////////////////////////////////////////////////////////////////////////

template < typename T1, typename T2 > concept same_as = std::is_same_v < T1, T2 > ;

///////////////////////////////////////////////////////////////////////////////////

int main()
{
    static_assert(     same_as < int, int    > == 1);
    
    static_assert(     same_as < int, double > == 0);

//  -------------------------------------------------

    static_assert(std::same_as < int, int    > == 1);
    
    static_assert(std::same_as < int, double > == 0);
}