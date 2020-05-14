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

//Checks if two reference points are linked
    bool isLinked(AbsRefPoint& R1, AbsRefPoint& R2);

//Checks if reference point is linked to sub unit
    bool refLinkedToSubUnit(AbsRefPoint& I, SubunitID sid);

//Checks it two sub units are linked together
    bool subUnitLinkedToSubUnit( SubunitID sid1 , SubunitID sid2 );

//Takes to sub units linked together and returns the two reference points that links them as an Abslink
    AbsLink searchLink(SubunitID sid1 , SubunitID sid2 );

//Returns a set of all neigbours to an abseloutrefencepoint
    set<AbsRefPoint> NeighborAbsRef( AbsRefPoint& x );

//Returns a path between two abseloute reference points
    vector<AbsRefPoint> searchRef2Ref(AbsRefPoint& I, AbsRefPoint& J);

//Returns a path between from a sub unit to an abseloute referencepoint.
    vector<AbsRefPoint> searchSubUnit2Ref(AbsRefPoint& I, SubunitID sid);

//Returns the path from an abseloute reference point to a sub unit.
    vector<AbsRefPoint> searchRef2SubUnit(AbsRefPoint& I, SubunitID sid);


//Returns a path between two sub units.
    vector<AbsRefPoint> searchSubUnit2SubUnit(SubunitID sid1 , SubunitID sid2 );

//Prints path out in cout
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

    //Defined the most commenly used symbols in the Structure
    symbol BETA = getSymbol("BETA", "\\beta");
    symbol ID = getSymbol( id );
    symbol F = getSymbol("F");
    symbol A = getSymbol("A");
    symbol PSI = getSymbol("PSI", "\\Psi");

    //Takes a vector of absolute reference points and return the phase factor. It also takes an integer from 0 to 3 that that takes care of how complex the stuff is returned
    ex getPhaseFactor( vector<AbsRefPoint> &path, int form );
    
    //Takes two absref points and return the phase factor. It also takes an integer from 0 to 3 that that takes care of how complex the stuff is returned
    ex getPhaseFactor( AbsRefPoint &R1, AbsRefPoint &R2, int form );
    
    //Takes one absref points and returns the Form Factor Amplitude. It also takes an integer from 0 to 3 that that takes care of how complex the stuff is returned
    ex getFormFactorAmplitude( AbsRefPoint &absref, int form);

    //Returns the form factor. It also takes an integer from 0 to 3 that that takes care of how complex the stuff is returned
    ex getFormFactor( int form );                                      
  
};



#endif 
