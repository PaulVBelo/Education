#include <type_traits>

////////////////////////////////////////////////////////////////////////////////////////////

template < typename T1, typename T2 > class is_same          : public std::false_type {};

template < typename T               > class is_same < T, T > : public std:: true_type {};

////////////////////////////////////////////////////////////////////////////////////////////

template < typename T1, typename T2 > constexpr auto is_same_v = is_same < T1, T2 > ::value;

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	static_assert(     is_same_v < int, int    > == 1);
    
    static_assert(     is_same_v < int, double > == 0);

//  ---------------------------------------------------

    static_assert(std::is_same_v < int, int    > == 1);
    
    static_assert(std::is_same_v < int, double > == 0);
}