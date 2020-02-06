//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_SUBUNIT
#define INCLUDE_GUARD_SUBUNIT

//===========================================================================
// included dependencies
#include<iostream>
#include<vector>

//===========================================================================
// The acutual class
class SubUnit{
private:


public:
//Constructor that takes instructions and construct subunit table and linked table
SubUnit();



//returns the formfacetor amplitude of the sub unit as a function, a char and latex-string
array formfactorAmplitude(typ, name , Aeq );

//returns the formfactor of the sub unit as a function, a char and latex-string
array formfactor(typ, name , Feq );

//returns the phasefactor of the amplitude as a function, a char and latex-string
array phasefactor(typ, name, PHIeq);

//returns reference point where it can stick to other subunits (could be some function descibing the surface of the subunit)
void referencePoints();


};


#endif // INCLUDE_GUARD_SUBUNIT

//SKAL HAVE DEN PRÆCISE SAMME STRUCTURE 