//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCTURE
#define INCLUDE_GUARD_STRUCTURE

//===========================================================================
// included dependencies
#include <iostream>
#include <vector>
#include <string>
#include <ginac/ginac.h>    
//#include "SubUnit.hpp" <--- Skaber circular depedencies!!!!
using namespace GiNaC;
using namespace std;
//===========================================================================
// The acutual class
class Structure {
private:
    
protected:

public:
//Public varialbles
    string structId;
    string id;
    ex Fstruct;
    ex Astruct;
    ex PSIstruct;
//Constructor with methods. 
    Structure( string id );
    virtual string get_Id();
    virtual ex getFormFactor();
    virtual ex getAmplitudeFactor();
    virtual ex getPhaseFactor();
    virtual void setFormFactor(ex input_Fstruct);
    virtual void setAmplitudeFactor(ex input_Astruct);
    virtual void setPhaseFactor(ex input_PSIstruct);


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