//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCT2SUB
#define INCLUDE_GUARD_STRUCT2SUB

//===========================================================================
// included dependencies
#include "SubUnit.hpp"
#include "GeneralSubUnit.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <ginac/ginac.h> 
using namespace std;

//===========================================================================
// The acutual class
class Struct2Sub : public GeneralSubUnit {
    public:
    
    //Convert structure to a subunit of a specefic type, and name the relative reference point "structure id:subunit id: original relative ref point id"
    Struct2Sub( SubunitID sid, Structure& S, TypeID t ) : GeneralSubUnit(sid){               
        type = ABSTRACT;                                                             //hvilken type distribution den bruger
        id = sid;
        
        AbsoluteReferencePointSet absref = S.StructRefPoints;
        set<AbsRefPoint>::iterator it;

        for(it = absref.begin(); it != absref.end(); it++){
            RelRefPoint relrefp( S.get_Id()+ ":" + it -> GetsubID() +":" + it -> GetrefID());
            AddReferencePoint( relrefp );
        }

        FormFactor = S.getFormFactor( 2 ); 

        set<AbsRefPoint>::iterator jt;

        for( it = absref.begin(); it != absref.end(); it++){                                    //giver formfactoramplituden fra reference punkt end#i
            AbsRefPoint a = *it;
            RelRefPoint relrefp( S.get_Id()+ ":" + it -> GetsubID() +":" + it -> GetrefID());
            FormFactorAmplitudes[ relrefp ] = S.getFormFactorAmplitude( a, 2 );     
        }

        for( it = absref.begin(); it != absref.end(); it++){                                     //giver fase faktoren for end#i end end#i+1
            for(jt = absref.begin(); jt != absref.end(); jt++){
                if( it -> GetrefID() < jt -> GetrefID() ){
                AbsRefPoint a = *it, b = *jt;
                RelRefPoint relrefp( S.get_Id()+ ":" + it -> GetsubID() +":" + it -> GetrefID());
                RelRefPoint relrefp2( S.get_Id()+ ":" + jt -> GetsubID() +":" + jt -> GetrefID());
                PhaseFactors[ relrefp ] [ relrefp2 ] = S.getPhaseFactor( a , b , 2);
                }     
            }   
        }
    }

    //Convert structure to a subunit of a specefic type, and name the relatives reference point with a string you choose + the number of the rel ref point
    Struct2Sub( SubunitID sid, Structure& S, TypeID t, string refname ) : GeneralSubUnit(sid){               //GeneralSubUnit 
    
        type = ABSTRACT;                                                             //hvilken type distribution den bruger
        id = sid;
        
        AbsoluteReferencePointSet absref = S.StructRefPoints;
        set<AbsRefPoint>::iterator it;

        int count = 1;

        for(it = absref.begin(); it != absref.end(); it++){
            RelRefPoint relrefp( refname + to_string(count) );
            AddReferencePoint( relrefp );
            count++;
        }

        FormFactor = S.getFormFactor( 2 ); 

        set<AbsRefPoint>::iterator jt;
        count = 1;

        for( it = absref.begin(); it != absref.end(); it++){                                    //giver formfactoramplituden fra reference punkt end#i
            AbsRefPoint a = *it;
            RelRefPoint relrefp( refname + to_string(count) );
            FormFactorAmplitudes[ relrefp ] = S.getFormFactorAmplitude( a, 2 );     
        }

        count = 0;
        for( it = absref.begin(); it != absref.end(); it++){                                    //giver fase faktoren for end#i end end#i+1
            count++;
            int countj = 1;
            for(jt = absref.begin(); jt != absref.end(); jt++){
                if( it -> GetrefID() < jt -> GetrefID() ){
                AbsRefPoint a = *it, b = *jt;
                RelRefPoint relrefp( refname + to_string(count) );
                RelRefPoint relrefp2( refname + to_string(countj) );
                PhaseFactors[ relrefp ] [ relrefp2 ] = S.getPhaseFactor( a , b , 2);
                countj++;
                }     
            }   
        }
    }
};

#endif //INCLUDE_GUARD_STRUCT2SUB