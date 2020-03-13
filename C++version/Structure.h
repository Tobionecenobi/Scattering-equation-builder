//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCTURE
#define INCLUDE_GUARD_STRUCTURE

//===========================================================================
// included dependencies
#include<iostream>
#include<vector>
#include <ginac/ginac.h> 
using namespace GiNaC;
//===========================================================================
// The acutual class
class Structure{
private:
//Empty formfactor eq made needs ginac libarary
    


public:
//Public variables
    symbol x("x");
    ex Fstruct;
    ex PSIstruct;
    ex Astruct;
//Constructor with methods. 
    Structure( int id);
    int getId();
    ex getFormFactor();
    ex getAmplitudeFactor();
    ex getPhaseFactor();
    void setFormFactor(ex input_Fstruct);
    void setAmplitudeFactor(ex input_Astruct);
    void setPhaseFactor(ex input_PSIstruct);
//Adds updated formfactor to the structure
    ex addFormFactor(&sub1);


//creates subunit using the subunit class, put that subunit into the subunit table
//void create(); // SKAL NOK IKKE VÆRE MED HER. 

//add sub unit to 

//Links sub units refenerence point together 
//void link(); // eksisterer i graf

//returns the formfactor of the structure build
//string formFactor();

//returns the formfactor amplitude of the structure build
//string formFactorAmpltude();

//returns the phasefactor of the structure build
//string phaseFactor();

};

//DET HELE SKAL VÆRE VIRTUAL OG ABSTRAC (TING BLIVER DECLARERET)





#endif 