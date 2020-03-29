#include <iostream>
#include <string>
#include <ginac/ginac.h> 
using namespace GiNaC;
#include "Structure.hpp"
//#include "SubUnit.hpp"
using namespace std;

//parametrized Structure Constructor
Structure::Structure( string id )
: structId(id)
{
    std::cout << "Structure: " << id << ", is created" << "\n";
    Structure::id = id;
    symbol F("F"), A("A"), PSI("PSI"); //I'm not sure why they have to be in the constructor
    ex Fstruct = F;
    ex Astruct = A;
    ex PSIstruct = PSI;
};
//get methods for the constructer
//get_Id(){
//    return id;
//}

ex getFormFactor(){
    return Fstruct;
}

// getAmplitudeFactor(){
//     return Astruct
// }

// getPhaseFactor(){
//     return PSIstruct;
// }

// setFormFactor( ex input_Fstruct ){
//     Fstruct = input_Fstruct;
// }

// setAmplitudeFactor( ex input_Astruct ){
//     Astruct = input_Astruct;
// }

// setPhaseFactor( ex input_PSIstruct){
//     PSIstruct = input_PSIstruct;
// }

// //adds a subunit to the structure
// addSubUnit( &struc , &sub ){
//     struc.setFormFactor( sub.getFormFactor() );
// };