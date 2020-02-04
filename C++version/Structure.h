//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCTURE
#define INCLUDE_GUARD_STRUCTURE

//===========================================================================
// included dependencies
#include<iostream>
#include<vector>

//===========================================================================
// The acutual class
class Structure{
private:


public:
//Constructor that takes instructions and construct subunit table and linked table
Structure();



//creates subunit using the subunit class, put that subunit into the subunit table
void create();

//Links sub units refenerence point together 
void link();

//returns the formfactor of the structure build
string formFactor();

//returns the formfactor amplitude of the structure build
string formFactorAmpltude();

//returns the phasefactor of the structure build
string phaseFactor();

};







#endif 