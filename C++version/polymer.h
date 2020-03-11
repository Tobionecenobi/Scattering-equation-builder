//POLYMER CONSTRUCTOR SKAL OGSÅ VÆRE MED 
// OBJECTET SKAL HAVE  UNIKT NAVN



//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_POLYMER
#define INCLUDE_GUARD_POLYMER

//===========================================================================
// included dependencies
#include<iostream>
#include<vector>
#include <ginac/ginac.h> //læs op på GiNaC

//===========================================================================
// The acutual class
class Polymer{
private:
    int id;
    long referencePoints;   //reference punkt kan være en værdi mellem 1 og 0 
                            //    /\/\/\/\/\/\/\/\/\ - polymer
                            //   0--1/4--1/2--3/4--1
    string name;
    string formFactor;
    string amplitudeFactor;
    string phaseFactor;

public:

//Constructor that build a unique polymer object . 
Virtual Polymer() //læs op på virtual og structures

//returns the value of the form factor of a flexiblepolymer for long input x
long formFactor( long x );

//returns the amplitude factor of a flexiblepolymer for long input x
long formFactorAmpltude( long x );

//returns the phasefactor of a flexiblepolymer for long input x
long phaseFactor( long x );
};

