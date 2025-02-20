#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>

#include <benchmark/benchmark.h>

//  ================================================================================================

class Entity_v1
{
public:

	Entity_v1(int x) : m_data(x)
	{
		std::cout << "Entity_v1:: Entity_v1 : m_data = " << m_data << '\n';
	}

   ~Entity_v1()
	{
		std::cout << "Entity_v1::~Entity_v1 : m_data = " << m_data << '\n';
	}

private:

	int m_data = 0;
};

//  ================================================================================================

union Entity_v2
{
	Entity_v2() : data_1() {}

   ~Entity_v2() {}

//  ---------------------------

	std::string data_1, data_2;
};

//  ================================================================================================

template < typename D > class Entity_v3
{
public:

	static auto operator new(std::size_t size) -> void *
	{
		std::cout << "Entity_v3::operator new\n";

		return ::operator new(size);
	}

	static void operator delete(void * ptr, std::size_t)
	{
		std::cout << "Entity_v3::operator delete\n";

		::operator delete(ptr);
	}

protected:

    Entity_v3() = default;

   ~Entity_v3() = default;
};

//  ================================================================================================

class Client : private Entity_v3 < Client >
{
private:

	using base_t = Entity_v3 < Client > ;

public:

	Client() { std::cout << "Client:: Client\n"; }

   ~Client() { std::cout << "Client::~Client\n"; }

//  ----------------------------------------------------

    using base_t::operator new, base_t::operator delete;
};

//  ================================================================================================

void test(benchmark::State & state)
{
    for (auto element : state)
    {
		auto ptr = operator new(state.range(0));
		
		benchmark::DoNotOptimize(ptr);
		
		operator delete(ptr, state.range(0));
    }
}

//  ================================================================================================

BENCHMARK(test)->RangeMultiplier(2)->Range(1'024 * 1'024, 1'024 * 1'024 * 1'024);

//  ================================================================================================

int main()
{
	{
		assert(sizeof(Entity_v1) == sizeof(int));

		auto size = 5uz;

		auto entities = static_cast < Entity_v1 * > (operator new(sizeof(Entity_v1) * size));

		for (auto i = 0uz; i < size; ++i)
		{
			new (entities + i) Entity_v1(i + 1);
		}

		auto offset = size / 2;

		(entities + offset)->~Entity_v1();

		new (entities + offset) Entity_v1(1);

		for (auto i = 0uz; i < size; ++i)
		{
			entities[i].~Entity_v1();
		}

		operator delete(entities, sizeof(Entity_v1) * size);
	}

//  -----------------------------------------------------------------------------------------

	{
		Entity_v2 entity_v2;

		entity_v2.data_1 = "aaaaa";

		entity_v2.data_1.~basic_string();

		new (&entity_v2.data_2) std::string;

		entity_v2.data_2 = "aaaaa";

		entity_v2.data_2.~basic_string();
	}

//  -----------------------------------------------------------------------------------------	

	{
		delete new Client;
	}

//  -----------------------------------------------------------------------------------------

	{
        benchmark::RunSpecifiedBenchmarks();
    }
}
