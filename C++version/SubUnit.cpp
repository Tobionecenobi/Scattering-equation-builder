#include <iostream>
#include "SubUnit.h"

// paratemized subunit constructor
SubUnit::SubUnit( int id) 
        : subId(id)
{
    std::cout << "Subunit: " << subId << ", is created" << "\n";
    id = subId;
}