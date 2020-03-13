#include <stdio.h>
#include <iostream> 
#include <ginac/ginac.h>
#include "Structure.h"
#include "SubUnit.h"

int main ( int argc, const char* argv[]){
    int structId = 0;
    int subId = 0;
    Structure Struct1(structId);
    SubUnit sub1(subId);

    Structure.addFormFactor( &Struct1 , &Sub1 );

    //  std::cout << Structure.Formfactor();

    //  Subunit sub2(subID++);

    //  Structure.add(&sub2)
    return 0;
}
    
   
    