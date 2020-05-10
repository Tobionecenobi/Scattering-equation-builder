//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_RWPOLYMER
#define INCLUDE_GUARD_RWPOLYMER

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
//using namespace GiNaC;
//using namespace std;

//===========================================================================
// The acutual class
class RWPolymer : public GeneralSubUnit {
  
/*
This is a concrete polymer class, which produce expressions that can be evaluated to numbers.
*/  
     public:

    RWPolymer( SubunitID sid ) : GeneralSubUnit(sid)                                       //random walk polymer nedarver fra subunit
    {
       type=GAUSSIANRANDOMWALK;                                                     //hvilken type distribution den bruger

       AddReferencePoint( RelRefPoint("end1") );                                    //adder reference point end1 til objectet
       AddReferencePoint( RelRefPoint("end2") );                                    //edder reference point end2 til objektet

       symbol q = getSymbol("q");                                                                 //definere symbol q                                                    //definere symbol Rg2 plus subunit id
       ex Rg2 = pow(getIndex(getSymbol("R"), getSymbol("g"), getSymbol(sid)),2);
       symbol x = getSymbol("x");
       
       local1[x] = getIndex(x, getSymbol(sid));
       local2[x] = pow(q,2)*Rg2;

       FormFactor=2.0*(exp(-x)-1.0+x)/(pow(x,2));                       //giver formlen for formfactoren

       FormFactorAmplitudes[ RelRefPoint("end1") ] = (exp(-x)-1)/(x);   //giver formfactoramplituden fra reference punkt end1
       FormFactorAmplitudes[ RelRefPoint("end2") ] = (exp(-x)-1)/(x);   //giver formfactoramplituden fra reference punkt end1

       PhaseFactors["end1"]["end2"] = exp(-x) ;                         //giver fase faktoren for end1 end2 <====== 

// more       
    }

};


#endif // INCLUDE_GUARD_SUBUNIT

