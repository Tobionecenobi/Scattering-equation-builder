//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_RWPOLYMER
#define INCLUDE_GUARD_RWPOLYMER

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
class RWPolymer : public SubUnit {
  
/*
This is a concrete polymer class, which produce expressions that can be evaluated to numbers.
*/  
     public:

    RWPolymer( SubunitID sid ) : SubUnit(sid)                                       //random walk polymer nedarver fra subunit
    {
       type=GAUSSIANRANDOMWALK;                                                     //hvilken type distribution den bruger

       AddReferencePoint( RelRefPoint("end1") );                                    //adder reference point end1 til objectet
       AddReferencePoint( RelRefPoint("end2") );                                    //edder reference point end2 til objektet

       symbol q("q");                                                               //definere symbol q
       symbol Rg2("Rg2_"+sid);                                                      //definere symbol Rg2 plus subunit id
       
       FormFactor=2.0*(exp(-q*q*Rg2)-1.0+q*q*Rg2)/(pow(q,4)*Rg2*Rg2);               //giver formlen for formfactoren

       FormFactorAmplitudes[ RelRefPoint("end1") ] = (exp(-q*q*Rg2)-1)/(q*q*Rg2);   //giver formfactoramplituden fra reference punkt end1
       FormFactorAmplitudes[ RelRefPoint("end2") ] = (exp(-q*q*Rg2)-1)/(q*q*Rg2);   //giver formfactoramplituden fra reference punkt end1

       PhaseFactors[ RelLink( "end1", "end1") ] = 1.0;                              //giver fase faktoren for end1 end1
       PhaseFactors[ RelLink( "end2", "end2") ] = 1.0;                              //giver fase faktoren for end2 end2
       PhaseFactors[ RelLink( "end1", "end2") ] = exp(-q*q*Rg2) ;                   //giver fase faktoren for end1 end2 <====== 

// more       
    }

};


#endif // INCLUDE_GUARD_SUBUNIT

