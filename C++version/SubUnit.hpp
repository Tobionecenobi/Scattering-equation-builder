//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_SUBUNIT
#define INCLUDE_GUARD_SUBUNIT

//===========================================================================
// included dependencies
#include "Structure.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <ginac/ginac.h> 
using namespace GiNaC;
using namespace std;

//===========================================================================
// The acutual class
class SubUnit : public Structure {
private:
    int id;
    ex Fsub;
    ex Asub;
    ex PSIsub;
    string subId;
protected:
    
public:
    
//Subunit Constructor
    SubUnit( string id );
    int getId() override;
    // ex getFormFactor() override;
    // ex getAmplitudeFactor() override;
    // ex getPhaseFactor() override;
    // void setFormFactor(ex input_Fsub) override;
    // void setAmplitudeFactor(ex input_Asub) override;
    // void setPhaseFactori(ex input_PSIsub) override;


    

//Gets formfactor of subunit object


// //returns the formfacetor amplitude of the sub unit as a function, a char and latex-string
// array formfactorAmplitude(typ, name , Aeq );

// //returns the formfactor of the sub unit as a function, a char and latex-string
// array formfactor(typ, name , Feq );

// //returns the phasefactor of the amplitude as a function, a char and latex-string
// array phasefactor(typ, name, PHIeq);

// //returns reference point where it can stick to other subunits (could be some function descibing the surface of the subunit)
// void referencePoints();
    

};


#endif // INCLUDE_GUARD_SUBUNIT

//SKAL HAVE DEN PRÆCISE SAMME STRUCTURE 