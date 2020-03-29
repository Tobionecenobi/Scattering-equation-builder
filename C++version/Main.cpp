Scod#include <stdio.h>
#include <iostream> 
#include <string>
#include <ginac/ginac.h>
#include "Structure.hpp"
#include "SubUnit.hpp"
#include "Structure.cpp"
#include "SubUnit.cpp"
using namespace std;


int main ( int argc, const char* argv[]){
    string structId = "General Structure";
    string subId = "General SubUnit";
    Structure struct1(structId);
    SubUnit sub1(subId);

    sub1.addSubUnit( struct1 );

    //  std::cout << Structure.Formfactor();

    //  Subunit sub2(subID++);

    //  Structure.add(&sub2)
    return 0;
}
    
   
    