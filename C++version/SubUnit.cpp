#include <iostream>
#include "SubUnit.h"
#include <ginac/ginac.h> 
using namespace GiNaC;

// paratemized subunit constructor
SubUnit::SubUnit( int id) 
        : subId(id)
{
    std::cout << "Subunit: " << subId << ", is created" << "\n";
    id = subId;
    Fsub = symbol F("F"); //needs to be indexed
    Asub = symbol A("A"); //needs to be indexed
    PSIsub = symbol PSI("PSI", "\psi"); //need to be indexed
}


//get methods for Constructor
SubUnit::getId(){
    return id;
}

SubUnit::getFormFactor(){
    return Fsub;
}

SubUnit::getAmplitudeFactor(){
    return Asub;
}

SubUnit::getPhaseFactor(){
    return PSIsub;
}


//Set methods for constructor
SubUnit::setFormfactor(ex input_FSub){
    Fsub = input_FSub;
}

SubUnit::setAmplitudeFactor(ex input_Asub){
    Asub = input_Asub;
}

SubUnit::setPhaseFactor(ex input_PSIsub){
    PSIsub = input_PSIsub;
}