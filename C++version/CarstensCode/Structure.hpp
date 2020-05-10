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
#include <queue> 
#include <ginac/ginac.h>    

using namespace GiNaC;
using namespace std;

#include "RefPoint.hpp"
#include "SubUnit.hpp"
#include "SymbolInterface.hpp"

//===========================================================================
// The acutual class

typedef set<SubunitID> SubunitSet;
class SubUnit;

class Structure{                                               //struktur klassen ser ud til at det er vores base class
public:
    StructureID id;                                             //strukturen har en struktur id
    SubunitSet subunits;                                        //strukturen har et set subunits

// En struktur har brug for at vide alle de subunit IDer den indeholder er unikke. Derfor dette set.    
    
    AbsoluteReferencePointSet StructRefPoints;                        //som sagt ovenover vi gemmer alle subunits som et set, et set kræver at hvert element er unikt. Jeg ved ikke om dette er nødvendigt
                                                                //da et map har de samme egenskaber
    
// En struktur har brug for at vide alle de reference-punkter som den indeholder er unikke. Derfor dette set.
// Absolute referencer er nødvendige her.   
    
    map<SubunitID,SubUnit*> StoredSubUnits;                     //her mapper vi subunits ved hjælp af deres subunit id, som mapper over til en subunit pointer der pejer på vores subunit objekt.
    
//set<pair<AbsRefPoint,AbsRefPoint> > Links;                  //her laver vi et sæt af unikke par hver del i parret kan fås gennem public members first and second
    set<AbsLink> Links;
// Links skal være absolutte

    bool isConcrete;                                            // true if all sub-units can be evaluated as expression. 

    Structure( StructureID _id ) : id(_id) { ; }                // constructor der laver en en structure
  //~Structure();  // deallocate memory                         // destructor der fjerne memory, den er dog ikke defineret så kommenteret ud    

    StructureID get_Id() { return id; }                         // returnerer id af en structur

    map<SubunitID, SubUnit*> getStoredSubUnits(){
        return StoredSubUnits;
    };
// Add first sub-unit   
    void Add(SubUnit* pS);                                      // adder en subunit til structuren

// Add all reference points from SubUnit to RefPoints
    void AddAbsoluteRefPoints(SubUnit* pS);

//Link relativereference point to absolute referencepoint (and maybe convert all relative reference points on subunit to absolute referencepoints)
    void Link(AbsRefPoint Rr, AbsRefPoint Ra);

//Checks if SubUnit exist
    bool SubUnitExist( SubUnit* pS );

// Join pS to structure where R on structure is linked to R in the existing structure.
// How to handle the empty structure, where R should be "".
    void Join(SubUnit* pS, RelRefPoint Rr, AbsRefPoint Ra);     // adder to subunits sammen i strukturen

    //Makes a chain of a vector of subunits the user and connect the chain to Absref point Ra
    void chain( vector<SubUnit> subContainer, AbsRefPoint Ra);
    
    //Makes a structure and generates a chain of sub units stored in a vector 
    void chain( vector<SubUnit&> subContaine, StructureID SID );

    bool isLinked(AbsRefPoint& R1, AbsRefPoint& R2);

    bool refLinkedToSubUnit(AbsRefPoint& I, SubunitID sid);

    bool subUnitLinkedToSubUnit( SubunitID sid1 , SubunitID sid2 );

    AbsLink searchLink(SubunitID sid1 , SubunitID sid2 );

    set<AbsRefPoint> NeighborAbsRef( AbsRefPoint& x );

    vector<AbsRefPoint> searchRef2Ref(AbsRefPoint& I, AbsRefPoint& J);

    vector<AbsRefPoint> searchSubUnit2Ref(AbsRefPoint& I, SubunitID sid);

    vector<AbsRefPoint> searchRef2SubUnit(AbsRefPoint& I, SubunitID sid);

    vector<AbsRefPoint> searchSubUnit2SubUnit(SubunitID sid1 , SubunitID sid2 );

    void printPath( vector<AbsRefPoint> path){
        for(auto i = path.begin(); i != path.end(); i++ ){
            if( i + 1 == path.end()){
            cout << i -> GetAbsRefPoint(); 
            break;
            }
        cout << i -> GetAbsRefPoint() << "->";
        }
    }

    AbsoluteReferencePointList* FindPath(AbsLink &L);           // er ikke defineret endnu

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

    symbol BETA = getSymbol("BETA", "\\beta");
    symbol ID = getSymbol( id );
    symbol F = getSymbol("F");
    symbol A = getSymbol("A");
    symbol PSI = getSymbol("PSI", "\\Psi");

    ex getPhaseFactor( vector<AbsRefPoint> &path, int form );
    ex getPhaseFactor( AbsRefPoint &R1, AbsRefPoint &R2, int form );
    
    ex getFormFactorAmplitude( AbsRefPoint &absref, int form);

    ex getFormFactor( int form );                                         // returnerer form factoren af strukturen

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
