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
class Struct2Sub : public GeneralSubUnit {
    public:
    
    //GeneralSubUnit constructor
    Struct2Sub( SubunitID sid, Structure& S, TypeID t ) : GeneralSubUnit(sid)               //GeneralSubUnit 
    {
        type = ABSTRACT;                                                             //hvilken type distribution den bruger
        id = sid;
        
        AbsoluteReferencePointSet absref = S.StructRefPoints;
        set<AbsRefPoint>::iterator it;

        for(it = absref.begin(); it != absref.end(); it++){
            RelRefPoint relrefp( "("+ it -> GetsubID() +"," + it -> GetrefID() + ")");
            AddReferencePoint( relrefp );
        }

        FormFactor = S.getFormFactor( 2 ); 

        set<AbsRefPoint>::iterator jt;

        for( it = absref.begin(); it != absref.end(); it++){                                    //giver formfactoramplituden fra reference punkt end#i
            AbsRefPoint a = *it;
            RelRefPoint relrefp( "("+ it -> GetsubID() +"," + it -> GetrefID() + ")");
            FormFactorAmplitudes[ relrefp ] = S.getFormFactorAmplitude( a, 2 );     
        }

        for( it = absref.begin(); it != absref.begin(); it++){                                     //giver fase faktoren for end#i end end#i+1
            for(jt = absref.begin(); jt != absref.begin(); jt++){
                if( it -> GetrefID() < jt -> GetrefID() ){
                AbsRefPoint a = *it, b = *jt;
                RelRefPoint relrefp( "("+ it -> GetsubID() +"," + it -> GetrefID() + ")");
                RelRefPoint relrefp2( "("+ jt -> GetsubID() +"," + jt -> GetrefID() + ")");
                PhaseFactors[ relrefp ] [ relrefp2 ] = S.getPhaseFactor( a , b , 2);
                }     
            }   
        }
    }
};

#endif //INCLUDE_GUARD_STRUCT2SUB