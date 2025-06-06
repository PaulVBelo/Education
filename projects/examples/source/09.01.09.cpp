///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <utility>

///////////////////////////////////////////////////////////////////////

class Entity 
{
public :

	virtual ~Entity() = default;

//  ----------------------------------

	virtual void test() const
	{ 
		std::cout << "Entity::test\n";
	}
};

///////////////////////////////////////////////////////////////////////

class Client : public Entity 
{
public :

	void test() const override 
	{ 
		std::cout << "Client::test\n";
	}
};

///////////////////////////////////////////////////////////////////////

int main()
{
	auto client_1 = std::make_unique < Client > ();

//	auto client_2 = client_1; // error

	auto client_3 = std::move(client_1);

//  -------------------------------------------------------------------

	std::unique_ptr < Entity > entity = std::make_unique < Client > ();

//  -------------------------------------------------------------------

	entity->test();
}

///////////////////////////////////////////////////////////////////////