//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_SUBUNIT
#define INCLUDE_GUARD_SUBUNIT

//===========================================================================
// included dependencies
#include "Structure.hpp"
#include "SubTypes.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <ginac/ginac.h> 
using namespace GiNaC;
using namespace std;

/*
Originally I thought SubUnit should be abstract, but below its not abstract in a C++
sense. But this was because the return functions for Formfactor, formfactorampltitude, and phasefactors
needed to be implemented here, since they are the same for all derived classes.
*/

//===========================================================================
// The acutual class
class SubUnit {
public:

    SubunitID id;
    TypeID type;
    
    double excessScatteringLength;  // beta bumber we need when calculating numbers.
    int scatteres;                  // Number of scattering sites, needed for coupling to pyPRISM.
    
    ex FormFactor;
    map<RelRefPoint,ex> FormFactorAmplitudes;
    map<RelLink, ex> PhaseFactors;

    RelativeReferencePointSet RefPoints;
    
//Subunit Constructor
    SubUnit( SubunitID sid ) : id(sid)
    {
        type=ABSTRACT;
    }

    virtual void AddReferencePoint( RelRefPoint R )
      {
         auto ret=RefPoints.insert(R);
         if (!ret.second) cout << "DIE Refpoint already in Refpointset";
      }

    virtual SubunitID getId() { return id; }
    virtual TypeID    getType() { return type; }
    
    virtual ex getFormFactor()                              { return FormFactor; }
    virtual ex getAmplitudeFactor(RelRefPoint &R)           { return FormFactorAmplitudes[R]; }  // Check R and L exists in maps
    virtual ex getPhaseFactor(RelLink &L)                   { return PhaseFactors[L]; }

/*
//Gets formfactor of subunit object


// //returns the formfacetor amplitude of the sub unit as a function, a char and latex-string
// array formfactorAmplitude(typ, name , Aeq );

// //returns the formfactor of the sub unit as a function, a char and latex-string
// array formfactor(typ, name , Feq );

// //returns the phasefactor of the amplitude as a function, a char and latex-string
// array phasefactor(typ, name, PHIeq);

// //returns reference point where it can stick to other subunits (could be some function descibing the surface of the subunit)
// void referencePoints();
    
*/
};


#endif // INCLUDE_GUARD_SUBUNIT

//SKAL HAVE DEN PRÆCISE SAMME STRUCTURE 
