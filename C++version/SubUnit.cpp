#include <iostream>
#include <string>
#include "SubUnit.hpp"
#include <ginac/ginac.h> 
using namespace GiNaC;
using namespace std;

// // paratemized subunit constructor
//SubUnit::SubUnit( string id )  
//         /*: subId(id)*/
// {
//     std::cout << "Subunit: " << id << ", is created" << "\n";
//     id = subId;
//     symbol F("F"), A("A"), PSI("PSI");
//     Fsub = F; //needs to be indexed
//     Asub = A; //needs to be indexed
//     PSIsub = PSI; //need to be indexed
// }


// //get methods for object
// getId(){
//     return id;
// }

// getFormFactor(){
//     return Fsub;
// }

// getAmplitudeFactor(){
//     return Asub;
// }

// getPhaseFactor(){
//     ex return PSIsub;
// }


// //Set methods for object
// void setFormfactor(ex input_FSub){
//     ex Fsub = input_FSub;
// }

// void setAmplitudeFactor(ex input_Asub){
//     ex Asub = input_Asub;
// };

// void setPhaseFactor(ex input_PSIsub){
//     ex PSIsub = input_PSIsub;
// };

// //Adds the subunit to a structure
// void addSubUnit( Structure& struct1 ){
//
// }