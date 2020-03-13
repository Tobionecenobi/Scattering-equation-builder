#include <iostream>
#include <ginac/ginac.h> 
using namespace GiNaC;
#include "Structure.h"
#include "SubUnit.h"


//parametrized Structure Constructor
Structure::Structure( int id )
          : structId(id)
{
    std::cout << "Structure: " << structId << ", is created" << "\n";
    id = structId;
    Fstruct = symbol F("F");
    Astruct = symbol A("A");
    PSIstruct = symbol PSI("PSI", "\psi");
}
//get methods for the constructer
Strcuture::getId(){
    return id;
}

Structure::getFormFactor(){
    return Fstruct;
}

Structure::getAmplitudeFactor(){
    return Astruct
}

Structure::getPhaseFactor(){
    return PSIstruct;
}

Structure::setFormFactor( ex input_Fstruct ){
    Fstruct = input_Fstruct;
}

Structure::setAmplitudeFactor( ex input_Astruct ){
    Astruct = input_Astruct;
}

Structure::setPhaseFactor( ex input_PSIstruct){
    PSIstruct = input_PSIstruct;
}

//adds a subunit to the structure
ex addFormFactor( &Structure , &SubUnit ){
    *Structure.setFormFactor( *SubUnit.getFormFactor() );
};