////////////////////////////////////////////////////////

#include <cassert>

////////////////////////////////////////////////////////

#include <boost/bimap.hpp>

////////////////////////////////////////////////////////

int main()
{
    boost::bimap < int, int > bimap;

//  ----------------------------------------------------

	bimap.insert({ 1, 1 });

//  ----------------------------------------------------

	assert(bimap.left.count(1) == bimap.right.count(1));

//  ----------------------------------------------------

	for (auto const & relation : bimap) 
	{
		assert(relation.left == relation.right);
	}
}

////////////////////////////////////////////////////////