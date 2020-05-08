//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCT2SUB
#define INCLUDE_GUARD_STRUCT2SUB

//===========================================================================
// included dependencies
#include "SubUnit.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <ginac/ginac.h> 
using namespace GiNaC;
using namespace std;

//===========================================================================
// The acutual class
class Struct2Sub : public SubUnit {
    public:
    
    //GeneralSubUnit constructor
    Struct2Sub( SubunitID sid, Structure& S, TypeID t ) : SubUnit(sid)               //GeneralSubUnit 
    {
        type = ABSTRACT;                                                             //hvilken type distribution den bruger
        id = sid;
        
        AbsoluteReferencePointSet absref = S.StructRefPoints;
        AbsoluteReferencePointSet::iterator it;

        for(it = absref.begin(); it != absref.end(); it++){
            AddReferencePoint( it -> GetrefID() );
        }
    }
};

#endif //INCLUDE_GUARD_STRUCT2SUB