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

    RWPolymer( SubunitID sid ) : SubUnit(sid)
    {
       type=GAUSSIANRANDOMWALK;

       AddReferencePoint( RelRefPoint("end1") );
       AddReferencePoint( RelRefPoint("end2") );

       symbol q("q");
       symbol Rg2("Rg2_"+sid);
       
       FormFactor=2.0*(exp(-q*q*Rg2)-1.0+q*q*Rg2)/(pow(q,4)*Rg2*Rg2);

       FormFactorAmplitudes[ RelRefPoint("end1") ] = (exp(-q*q*Rg2)-1)/(q*q*Rg2);
       FormFactorAmplitudes[ RelRefPoint("end2") ] = (exp(-q*q*Rg2)-1)/(q*q*Rg2);

       PhaseFactors[ RelLink( "end1", "end1") ] = 1.0;
       PhaseFactors[ RelLink( "end2", "end2") ] = 1.0;
       PhaseFactors[ RelLink( "end1", "end2") ] = exp(-q*q*Rg2) ;

// more       
    }

};


#endif // INCLUDE_GUARD_SUBUNIT

