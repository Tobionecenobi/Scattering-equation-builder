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
class SubUnit {                                                             //subunit er ikke nedarvet men en base klasse i sig selv?
public:

    SubunitID id;                                                           //sætter sub unit id til at være id <==== hvordan ved vi at det er af type string???
    TypeID type;                                                            //type id fortæller hvilken slags type sub unit vi har
    
    double excessScatteringLength;  // beta bumber we need when calculating numbers.
    int scatteres;                  // Number of scattering sites, needed for coupling to pyPRISM.
    
    ex FormFactor;                                                          //definere formfactoren til at være en equation
    map<RelRefPoint,ex> FormFactorAmplitudes;                               // map: key er relrefpoint og mapper til en formfactor amplitude equation
    map<RelLink, ex> PhaseFactors;                                          // map: key er et rellink og mapper til en fase faktor equation

    RelativeReferencePointSet RefPoints;                                    //Laver relative reference poin set <======= Igen hvordan ved vi hvilken type?
    
//Subunit Constructor
    SubUnit( SubunitID sid ) : id(sid)                                      //subunit constructor der er af type abstract. dvs at man SKAL lave en constructor i den bestemte type
    {
        type=ABSTRACT;
    }

    virtual void AddReferencePoint( RelRefPoint R )                         //adder reference points til en abstract subunit
      {
         auto ret=RefPoints.insert(R);
         if (!ret.second) cout << "DIE Refpoint already in Refpointset";
      }

    virtual SubunitID                 getId() { return id; }                //returner subunit id
    virtual TypeID                    getType() { return type; }            //returner typen af subunit vi har
    virtual RelativeReferencePointSet getRelRefSet() { return RefPoints; }  //returner relativerefpoints
    
    virtual ex getFormFactor( SubUnit sid )                         { return FormFactor; }
    virtual ex getFormFactorAmplitude(RelRefPoint &R, SubunitID s)  { return FormFactorAmplitudes[R]; }  // Check R and L exists in maps
    virtual ex getPhaseFactor(RelLink &L , SubunitID s)             { return PhaseFactors[L]; }

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
