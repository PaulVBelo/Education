#include <cassert>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <variant>

class Mobile { public: [[nodiscard]] auto run() const { return 0; }; };
class Tablet { public: [[nodiscard]] auto run() const { return 0; }; };
class Laptop { public: [[nodiscard]] auto run() const { return 1; }; };

using Computer = std::variant < Mobile, Tablet, Laptop > ;

class Tester
{
public:

    void operator()(const Mobile & mobile) const
    {
        if (mobile.run() != 0) throw std::runtime_error("invalid Mobile::run");
    }

    void operator()(const Tablet & tablet) const
    {
        if (tablet.run() != 0) throw std::runtime_error("invalid Tablet::run");
    }

    void operator()(const Laptop & laptop) const
    {
        if (laptop.run() != 0) throw std::runtime_error("invalid Laptop::run");
    }

}; // class Tester

template < typename ... Bases > struct Visitor : Bases... 
{
    using Bases::operator()...;

}; // template < typename ... Bases > struct Visitor : Bases...

int main()
{
    Computer mobile = Mobile();
    Computer tablet = Tablet();
    Computer laptop = Laptop();

    Visitor < Tester > visitor(Tester{}); // note: just Visitor in MSVC

    try
    {
        std::visit(visitor, mobile);
        std::visit(visitor, tablet);
        std::visit(visitor, laptop);
    }
    catch (const std::exception & exception)
    {
        std::cerr << "Tester error: " << exception.what() << '\n';
    }

    assert(std::visit([](auto && x){ return x; }, std::variant < int > (42)) == 42);

    auto lambda = [](auto && x){ return x; };

    Visitor < decltype(lambda) > test(lambda); // note: just Visitor in MSVC

    assert(std::visit(test, std::variant < int > (42)) == 42);

    return 0;
}