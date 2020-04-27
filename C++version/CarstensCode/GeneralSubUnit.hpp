//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_GENERALSUBUNIT
#define INCLUDE_GUARD_GENERALSUBUNITq

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
class GeneralSubUnit : public SubUnit {
  
/*
This is a concrete polymer class, which produce expressions that can be evaluated to numbers.
*/  
    public:

    GeneralSubUnit( SubunitID sid, int numOfRefPoints ) : SubUnit(sid)                                       //random walk polymer nedarver fra subunit
    {
        type = ABSTRACT;                                                                   //hvilken type distribution den bruger

        for(int i = 1; i <= numOfRefPoints; i++){
            AddReferencePoint( RelRefPoint( "end" + to_string( i ) ) );                                 //adder reference point end + #i til objectet
        }     
                                        

        symbol F("F");                                                               //definere symbol q
        symbol A("A");
        symbol PSI("PSI");                                                           //definere symbol Rg2 plus subunit id 
       
        FormFactor = F;                                                              //giver formlen for formfactoren
        
        for(int n = 1; n <= numOfRefPoints; n++){  
            symbol i_sym( to_string(n) ), S_sym( sid );                                  //giver formfactoramplituden fra reference punkt end#i
            idx i(i_sym, 1), S(S_sym, 1);
            FormFactorAmplitudes[ RelRefPoint("end" + to_string(n) ) ] = indexed(A, S, i);      
        }

        for(int n = 1; n <= numOfRefPoints; n++){                                    //giver phasefaktoren for end#i og end#i
            PhaseFactors[ RelLink( "end" + to_string(n) , "end" + to_string(n) )  ] = 1.0;
        }

        for(int n = 1; n < numOfRefPoints; n++){  
            symbol i_sym( to_string(n) ), j_sym( to_string(n+1) ), S_sym( sid );                                   //giver fase faktoren for end#i end end#i+1
            idx i(i_sym, 1), j(j_sym, 1), S(S_sym, 1);
            PhaseFactors[ RelLink( "end" + to_string(n) , "end" + to_string( n + 1 ) ) ] = indexed( PSI, S, i, j);     
        }

        for(int n = numOfRefPoints; n > 1; n--){                                     //giver fase faktoren for end#i end end#i-1
            symbol i_sym( to_string(n) ), j_sym( to_string(n-1) ), S_sym( sid );
            idx i(i_sym, 1), j(j_sym, 1), S(S_sym, 1);
            PhaseFactors[ RelLink( "end" + to_string(n) , "end" + to_string( n - 1 ) ) ] = indexed( PSI, S, i, j);     
        }
// more       
    }

};


#endif // INCLUDE_GUARD_SUBUNIT