//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_SUBUNIT
#define INCLUDE_GUARD_SUBUNIT

//===========================================================================
// included dependencies
#include<iostream>
#include<vector>
#include <ginac/ginac.h> 
using namespace GiNaC;

//===========================================================================
// The acutual class
class SubUnit{
private:
    int subId;
    ex Fsub;
    ex PSIsub;
    ex Asub;

public:
//Subunit Constructor
    SubUnit( int id);
    int getId();
    ex getFormFactor();
    ex getAmplitudeFactor();
    ex getPhaseFactor();
    void setFormFactor(ex input_Fsub);
    void setAmplitudeFactor(ex input_Asub);
    void setPhaseFactori(ex input_PSIsub);


    

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