#include <compare>
#include <iostream>

// =================================================================================================

class Apple
{
public:

    explicit Apple(double weight) : m_weight(weight) {}

    [[nodiscard]] auto operator<=>(const Apple & rhs) const // note: auto -> std::partial_ordering
    {
        return (m_weight <=> rhs.m_weight);
    }

private:

    double m_weight;

}; // class Apple 

// =================================================================================================

class Human
{
public:

    explicit Human(double weight, double height) : m_weight(weight), m_height(height) {}

    [[nodiscard]] auto operator<=>(const Human & rhs) const = default; // note: auto -> std::strong_ordering

private:

    double m_weight;
    double m_height;

}; // class Human

// =================================================================================================

int main()
{
    auto x = 4;
    auto y = 7;

    if ((x <=> y) < 0) std::cout << "x < y" << std::endl << std::endl; // note: same as x < y

    Apple apple_1(200.0);
    Apple apple_2(100.0);

    std::cout << "apple_1 <  apple_2: " << (apple_1 <  apple_2) << std::endl;
    std::cout << "apple_1 >  apple_2: " << (apple_1 >  apple_2) << std::endl;
    std::cout << "apple_1 <= apple_2: " << (apple_1 <= apple_2) << std::endl;
    std::cout << "apple_1 >= apple_2: " << (apple_1 >= apple_2) << std::endl;
//  std::cout << "apple_1 == apple_2: " << (apple_1 == apple_2) << std::endl; // note: partial ordering
//  std::cout << "apple_1 != apple_2: " << (apple_1 != apple_2) << std::endl; // note: partial ordering

    std::cout << std::endl;

    Human human_1(85.0, 185.0);
    Human human_2(80.0, 180.0);

    std::cout << "human_1 <  human_2: " << (human_1 <  human_2) << std::endl;
    std::cout << "human_1 >  human_2: " << (human_1 >  human_2) << std::endl;
    std::cout << "human_1 <= human_2: " << (human_1 <= human_2) << std::endl;
    std::cout << "human_1 >= human_2: " << (human_1 >= human_2) << std::endl;
    std::cout << "human_1 == human_2: " << (human_1 == human_2) << std::endl;
    std::cout << "human_1 != human_2: " << (human_1 != human_2) << std::endl;

    return 0;
}