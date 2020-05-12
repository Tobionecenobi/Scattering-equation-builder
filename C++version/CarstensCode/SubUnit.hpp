//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_SUBUNIT
#define INCLUDE_GUARD_SUBUNIT

//===========================================================================
// included dependencies
//#include "Structure.hpp"
#include "SubTypes.hpp"
#include "SymbolInterface.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <ginac/ginac.h> 
using namespace std;

/*
Originally I thought SubUnit should be abstract, but below its not abstract in a C++
sense. But this was because the return functions for Formfactor, formfactorampltitude, and phasefactors
needed to be implemented here, since they are the same for all derived classes.
*/

//===========================================================================
// The acutual class
class Structure;

class SubUnit{                                                             //subunit er ikke nedarvet men en base klasse i sig selv?
public:

    SubunitID id;                                                           //sætter sub unit id til at være id <==== hvordan ved vi at det er af type string???
    TypeID type;                                                            //type id fortæller hvilken slags type sub unit vi har
    
    double excessScatteringLength;                                      // beta bumber we need when calculating numbers.
    int scatteres;                  // Number of scattering sites, needed for coupling to pyPRISM.
    
    RelativeReferencePointSet RefPoints;                                    //Laver relative reference poin set <======= Igen hvordan ved vi hvilken type?

//Subunit Constructor
    SubUnit( SubunitID sid ) : id(sid)                                      //subunit constructor der er af type abstract. dvs at man SKAL lave en constructor i den bestemte type
    {
        type=ABSTRACT;
    }

    virtual SubunitID                 getId() { return id; }                //returner subunit id
    virtual TypeID                    getType() { return type; }            //returner typen af subunit vi har
    
    RelativeReferencePointSet getRelRefSet() { return RefPoints; }  //returner relativerefpoints

    virtual void AddReferencePoint( RelRefPoint R )                         //adder reference points til en abstract subunit
      {
         auto ret=RefPoints.insert(R);
         if (!ret.second) cout << "DIE Refpoint already in Refpointset";
      }

    //Makes a pointer to SymbolInterface class
    SymbolInterface *GLEX = SymbolInterface::instance();

    //Manual over writing of get index from class SymbolInterface
    ex getIndex( ex e, ex e2, ex e3, ex e4, ex e5){
        return GLEX -> getIndex(e, e2, e3, e4, e5);
    } 

    ex getIndex( ex e, ex e2, ex e3, ex e4){
        return GLEX -> getIndex(e, e2, e3, e4);
    }

    ex getIndex( ex e, ex e2, ex e3){
        return GLEX -> getIndex(e, e2, e3);
    }

    ex getIndex( ex e, ex e2){
        return GLEX -> getIndex(e, e2);
    }

    //Manaul over writing of getsymbol from class SymbolInterface
    symbol getSymbol( string s1, string latex = ""){
        return GLEX -> getSymbol(s1, latex );
    }

    //Define most used symbols
    symbol BETA = getSymbol("BETA", "\\beta");
    symbol ID = getSymbol( id );
    symbol F = getSymbol("F");
    symbol A = getSymbol("A");
    symbol PSI = getSymbol("PSI", "\\Psi");

    //Returns Formfactor as one symbol
    virtual ex getFormFactor( int form = 0 ){
        return GLEX -> getIndex( pow(BETA,2), ID ) * GLEX -> getIndex( F, ID );
    }

    //Returns form factor amplitude as one symbol
    virtual ex getFormFactorAmplitude( RelRefPoint &R, int form = 0 ){
        return GLEX -> getIndex(BETA, ID) * GLEX -> getIndex( A, ID, GLEX -> getSymbol( R ));
    }

    //Returns the phase factor as one symbol
    virtual ex getPhaseFactor( RelRefPoint &R1 , RelRefPoint &R2, int form = 0 ){
        return GLEX -> getIndex( PSI, ID, GLEX -> getSymbol(R2), GLEX -> getSymbol(R1) );
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
