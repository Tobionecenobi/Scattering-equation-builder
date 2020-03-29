#include <iostream>
#include <string>
#include <ginac/ginac.h> 
using namespace GiNaC;
#include "Structure.hpp"
//#include "SubUnit.hpp"
using namespace std;

/*I HAVE ABSOLUTE NO IDEA WHY THESE VARIABLE NEEDS TO BE DEFINED HERE
  TO WORK. WHO HAVE ACCESS, ARE THEY PRIVATE, PUBLIC OR WHAT? I'M VERY
  CONFUSED ABOUT THIS*/
    string structId;
    string id;
    ex Fstruct;
    ex Astruct;
    ex PSIstruct;

//parametrized Structure Constructor
Structure::Structure( string id )
: structId(id)
{
    std::cout << "Structure: " << id << ", is created" << "\n";
    Structure::id = id;
    symbol F("F"), A("A"), PSI("PSI"); //I'm not sure why they have to be in the constructor
    ex Fstruct = F;
    ex Astruct = A;
    ex PSIstruct = PSI;
}
//get methods for the constructer
string get_Id(){
    return id;
}

ex getFormFactor(){
    return Fstruct;
}

ex getAmplitudeFactor(){
    return Astruct;
}

ex getPhaseFactor(){
    return PSIstruct;
}

void setFormFactor( ex input_Fstruct ){
    Fstruct = input_Fstruct;
}

void setAmplitudeFactor( ex input_Astruct ){
    Astruct = input_Astruct;
}

void setPhaseFactor( ex input_PSIstruct){
    PSIstruct = input_PSIstruct;
}

// void addSubUnit( SubUnit& sub1 ){
//  make   Fstruct = Fstruct + sub1.getFormFactor();
// }