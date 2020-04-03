//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCTURE
#define INCLUDE_GUARD_STRUCTURE

//===========================================================================
// included dependencies
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ginac/ginac.h>    

using namespace GiNaC;
using namespace std;

#include "RefPoint.hpp"

//===========================================================================
// The acutual class

typedef set<SubunitID> SubunitSet;
class SubUnit;

class Structure {
public:
    StructureID id;
    SubunitSet subunits;

// En struktur har brug for at vide alle de subunit IDer den indeholder er unikke. Derfor dette set.    
    
    AbsoluteReferencePointSet RefPoints;
    
// En struktur har brug for at vide alle de reference-punkter som den indeholder er unikke. Derfor dette set.
// Absolute referencer er nødvendige her.   
    
    map<SubunitID,SubUnit*> StoredSubUnits;
    
    set<pair<AbsRefPoint,AbsRefPoint> > Links;

// Links skal være absolutte

    bool isConcrete;                                // true if all sub-units can be evaluated as expression. 

    Structure( StructureID _id ) : id(_id) { ; }
    ~Structure();  // deallocate memory

    StructureID get_Id() { return id; }

// Add first sub-unit   
    void Add(SubUnit* pS);

// Join pS to structure where R on structure is linked to R in the existing structure.
// How to handle the empty structure, where R should be "".
    void Join(SubUnit* pS, RelRefPoint Rr, AbsRefPoint Ra);

    AbsoluteReferencePointList* FindPath(AbsLink &L);

    ex getAbstractFormFactor();
    ex getFormFactor();

/*    
// Return abstract expressions for tree structure. I.e. using F_id(q), A_id_ref(q), Psi_id_ref1,ref2(q) as variables. 
// Calculate these. There is no need for internal variables.
    ex AbstractFormFactorAmplitude(AbsRefPoint &R);
    ex AbstractPhaseFactor(AbsLink &L);

// Return concrete scattering expressions for tree structure. Where the F,A,Psi expressions from the sub-units are inserted.
    ex FormFactor();
    ex FormFactorAmplitude(AbsRefPoint &R);
    ex PhaseFactor(AbsLink &L);
*/
  
};



#endif 
