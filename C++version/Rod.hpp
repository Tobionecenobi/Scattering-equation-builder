//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_ROD
#define INCLUDE_GUARD_ROD

//===========================================================================
// included dependencies
#include "GeneralSubUnit.hpp"

//===========================================================================
// The acutual class

/*
This is a concrete Rod class, which produce expressions that can be evaluated to numbers.
*/  
class Rod : public GeneralSubUnit {
    public:

    Rod( SubunitID sid) : GeneralSubUnit(sid){
        
        type = ROD;

        AddReferencePoint( "end1" );
        AddReferencePoint( "end2" );
        
        symbol q = getSymbol("q");   
        symbol L = getSymbol("L." + sid, "L_{" + sid + "}");
        symbol x = getSymbol("x");
        symbol y = getSymbol("y");

        local1[x] = getSymbol("x." + sid, "x_{" + sid + "}");           //getIndex(x, getSymbol(sid));
        local2[x] = q*L;
        local3[x] = x;

        //Integral from 0 to x, taking change in variable y with expression sin(y)/y
        ex Si = integral(y, 0, x, sin(y)/y );      

        FormFactor = pow(BETA, 2)*((2*Si/x) - (4 / (x*x)) * pow(sin(x/2),2));

        FormFactorAmplitudes[ "end1" ] = BETA*Si/x;
        FormFactorAmplitudes[ "end2" ] = BETA*Si/x;

        PhaseFactors[ "end1" ][ "end2" ] = sin(x) / x;
        PhaseFactors[ "end2" ][ "end1" ] = sin(x) / x; 

    }
};

#endif // INCLUDE_GUARD_SUBUNIT