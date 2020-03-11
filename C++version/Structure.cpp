#include <iostream>
#include "Structure.h"
#include "SubUnit.h"

//parametrized Structure Constructor
Structure::Structure( int id )
          : structId(id)
{
    std::cout << "Structure: " << structId << ", is created" << "\n";
    id = structId;
}

//adds a subunit to the structure
Subunit add(&SubUnit){
    
}