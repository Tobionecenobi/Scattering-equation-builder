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
class Structure;

class SubUnit {                                                             //subunit er ikke nedarvet men en base klasse i sig selv?
public:

    SubunitID id;                                                           //sætter sub unit id til at være id <==== hvordan ved vi at det er af type string???
    TypeID type;                                                            //type id fortæller hvilken slags type sub unit vi har
    
    double excessScatteringLength;                                      // beta bumber we need when calculating numbers.
    int scatteres;                  // Number of scattering sites, needed for coupling to pyPRISM.
    
//Subunit Constructor
    SubUnit( SubunitID sid ) : id(sid)                                      //subunit constructor der er af type abstract. dvs at man SKAL lave en constructor i den bestemte type
    {
        type=ABSTRACT;
    }

    virtual SubunitID                 getId() { return id; }                //returner subunit id
    virtual TypeID                    getType() { return type; }            //returner typen af subunit vi har
    

    virtual ex getFormFactor( int form = 0 ){
        symbol F("F"), BETA("BETA" , "\\beta"), s_sym( id );
        idx s(s_sym, 1 );
        return indexed(pow(BETA,2), s)*indexed( F , s );
    }

    virtual ex getFormFactorAmplitude( RelRefPoint &R, int form = 0 ){
        symbol A("A"), BETA("BETA" , "\\beta"), I_sym( R ), s_sym( id );
        idx I(I_sym, 1), s(s_sym, 1);
        return indexed(BETA, s)*indexed( A , s , I);
    }
    virtual ex getPhaseFactor( RelRefPoint &R1 , RelRefPoint &R2, int form = 0 ){
        symbol PSI("PSI" , "\\Psi"), I_sym( R1 ), J_sym( R2 ), sid_sym( id );
        idx I(I_sym, 1), J(J_sym, 1), sid(sid_sym, 1);
        return indexed(PSI, sid, J, I);
    }
};
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
#endif // INCLUDE_GUARD_SUBUNIT

//SKAL HAVE DEN PRÆCISE SAMME STRUCTURE 
