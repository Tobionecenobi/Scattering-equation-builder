#include <iostream>
#include <string>
#include <ginac/ginac.h> 
#include "Structure.hpp"

using namespace GiNaC;
using namespace std;

void Structure::Add(SubUnit* pS)
{
   // Test at strukturen er tom
}

void Structure::Join(SubUnit* pS, RelRefPoint Rr, AbsRefPoint Ra)
{
  // Test at strukturen ikke er tom,
  // Test at pS->GetID ikke findes i forvejen i strukturen.
  // Test at Ra findes i strukturen.
  
  // Adder pS til strukturen.
  
  // Updater set af kendte subunit IDs
  // Updater set af kendte absolutte reference punkter
  
  // Skab link.

  // Check der ikke er cykliske loops i strukturen..
}


AbsoluteReferencePointList* Structure::FindPath(AbsLink &L)
{
   AbsoluteReferencePointList *arpl=new AbsoluteReferencePointList();
   
   // Path through structure.
   // Note the recipient should deallcate the memory used by the list.
   
   return arpl;
}

ex Structure::getAbstractFormFactor()
// Returns  F_p1(q)+F_p2(q)+2*A_p1(q)*A_p2(q)
{
  ex F;
  return F;
}

ex Structure::getFormFactor()
// Returns long complicated expression..
{
  ex F;
  return F;
}
