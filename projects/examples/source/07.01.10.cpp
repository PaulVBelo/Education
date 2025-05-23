//////////////////////////////////////////////////////////////////////////////

#include <cassert>

//////////////////////////////////////////////////////////////////////////////

#include <boost/logic/tribool.hpp>

//////////////////////////////////////////////////////////////////////////////

int main()
{
	boost::logic::tribool x = false, y = true;

	boost::logic::tribool z = boost::logic::indeterminate;

//  --------------------------------------------------------------------------

	assert((!x).value == 1);
	
	assert((!y).value == 0);
	
	assert((!z).value == 2);

//  --------------------------------------------------------------------------

	assert((x && x).value == 0 && (x && y).value == 0 && (x && z).value == 0);

	assert((y && x).value == 0 && (y && y).value == 1 && (y && z).value == 2);

	assert((z && x).value == 0 && (z && y).value == 2 && (z && z).value == 2);

//  --------------------------------------------------------------------------

	assert((x || x).value == 0 && (x || y).value == 1 && (x || z).value == 2);

	assert((y || x).value == 1 && (y || y).value == 1 && (y || z).value == 1);

	assert((z || x).value == 2 && (z || y).value == 1 && (z || z).value == 2);
}

//////////////////////////////////////////////////////////////////////////////