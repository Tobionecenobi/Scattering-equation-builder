#include <iostream>
#include <string>
#include "SubUnit.hpp"
#include "Structure.hpp"
#include <ginac/ginac.h> 
using namespace GiNaC;
using namespace std;


/*
// paratemized subunit constructor
SubUnit::SubUnit( string id )  
       : subId(id)
{
    std::cout << "Subunit: " << id << ", is created" << "\n";
    id = subId;
    symbol Fs("Fs"), Ad("As"), PSIs("PSIs");
    Fsub = Fs; //needs to be indexed
    Asub = As; //needs to be indexed
    PSIsub = PSIs; //need to be indexed
}


//get methods for object
getId(){
    return id;
}

getFormFactor(){
    return Fsub;
}

getAmplitudeFactor(){
    return Asub;
}

getPhaseFactor(){
    ex return PSIsub;
}


//Set methods for object
void setFormfactor(ex input_FSub){
    ex Fsub = input_FSub;
}

void setAmplitudeFactor(ex input_Asub){
    ex Asub = input_Asub;
};

void setPhaseFactor(ex input_PSIsub){
    ex PSIsub = input_PSIsub;
};

//Adds the subunit to a structure
void addSubUnit( Structure& struct1 ){
    struct1.setFormfacetor(getFormFactor());
}

*/
