//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCTURE
#define INCLUDE_GUARD_STRUCTURE

//===========================================================================
// included dependencies
#include<iostream>
#include<vector>
#include <ginac/ginac.h> //læs op på GiNaC

//===========================================================================
// The acutual class
class Structure{
private:


public:
//Constructor that takes instructions linked table and subUnit. 
Virtual Structure() = 0 //læs op på virtual og structures



//creates subunit using the subunit class, put that subunit into the subunit table
void create(); // SKAL NOK IKKE VÆRE MED HER. 

//Links sub units refenerence point together 
//void link(); // eksisterer i graf

//returns the formfactor of the structure build
string formFactor();

//returns the formfactor amplitude of the structure build
string formFactorAmpltude();

//returns the phasefactor of the structure build
string phaseFactor();

};

DET HELE SKAL VÆRE VIRTUAL OG ABSTRAC (TING BLIVER DECLARERET)





#endif 