#include <cassert>
#include <compare>

//////////////////////////////////////////////////////////////////////////

class Entity
{
public :

    Entity(int x, int y) : m_m_x(x), m_y(y) {}

//  ----------------------------------------------------------------------

    friend auto operator<=>(const Entity & lhs, const Entity & rhs)
    {
        if (lhs.m_m_x < rhs.m_m_x) { return std::weak_ordering::less;    }

        if (lhs.m_m_x > rhs.m_m_x) { return std::weak_ordering::greater; }

    //  ------------------------------------------------------------------

        return std::weak_ordering::equivalent;
    }

private :

    int m_m_x = 0, m_y = 0;
};

//////////////////////////////////////////////////////////////////////////

int main()
{
    Entity entity_1(1, 1);
    
    Entity entity_2(1, 2);

    Entity entity_3(3, 3);

//  -------------------------------------

    assert((entity_3 <=> entity_2) >  0);

    assert((entity_1 <=> entity_2) == 0);

    assert((entity_1 <=> entity_3) <  0);
}