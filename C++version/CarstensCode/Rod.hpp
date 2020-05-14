//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_ROD
#define INCLUDE_GUARD_ROD

//===========================================================================
// included dependencies
#include "GeneralSubUnit.hpp"

//===========================================================================
// The acutual class
class Rod : public GeneralSubUnit {
    public:

    Rod( SubunitID sid) : GeneralSubUnit(sid){
        
        type = ROD;

        AddReferencePoint( "end1" );
        AddReferencePoint( "end2" );
        
        symbol q = getSymbol("q");   
        symbol L = getSymbol("L");
        symbol x = getSymbol("x");
        symbol y = getSymbol("y");

        local1[x] = getIndex(x, getSymbol(sid));
        local2[x] = q*L;

        //Integral from 0 to x, taking change in variable y with expression sin(y)/y
        ex Si = integral(y, 0, x, sin(y)/y );      

        FormFactor = (2*Si/x) - (4 / x*x) * sin(x/2) * 2;

        FormFactorAmplitudes[ "end1" ] = Si/x;
        FormFactorAmplitudes[ "end2" ] = Si/x;

        PhaseFactors[ "end1" ][ "end2" ] = sin(x) / x; 

    }
};

#endif // INCLUDE_GUARD_SUBUNIT