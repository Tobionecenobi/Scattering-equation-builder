#include <iostream>
#include <string>
#include <ginac/ginac.h> 
#include "Structure.hpp"

using namespace GiNaC;
using namespace std;

void Structure::AddAbsoluteRefPoints(SubUnit* pS){

  set<RelRefPoint>::iterator it;
  
  for(it = pS -> RefPoints.begin(); it != pS -> RefPoints.end(); it++){
    StructRefPoints.insert( pair<RelRefPoint,AbsRefPoint>(*it , AbsRefPoint( pS -> getId() , *it )) );        //<====== *it giver for håbenligt value og it er adressen
  }
}

void Structure::Add( SubUnit* pS )                                  //adder subunit til strukturen
{
  if(subunits.empty()){
    subunits.insert( pS -> getId() );
    StoredSubUnits.insert( pair<SubunitID,SubUnit*>(pS -> getId() , pS) );
    AddAbsoluteRefPoints( pS );
  }
   // Test at strukturen er tom
}

void Structure::Link( RelRefPoint Rr, AbsRefPoint Ra){
  Links.insert( AbsLink( StructRefPoints.find( Rr ) -> second , Ra ) );
}

void Structure::Join(SubUnit* pS, RelRefPoint Rr, AbsRefPoint Ra) //joiner to strukturer sammen
{
  // Test at strukturen ikke er tom,
  if (Ra.GetAbsRefPoint() == ""){
    cout << "There are no subunits to add the new subunit" << "\n";
  }
  // Test at relative referencepoint tilhører subunit pS

  // Test at pS->GetID ikke findes i forvejen i strukturen.
  else if ( subunits.find( pS -> getId() ) == subunits.end() ){        //Try so find the subunit id. If not found() returns end() to iterator. then checks if it == end().
    Add( pS );
    Link( Rr , Ra );
  }                                         
  // Test at Ra findes i strukturen.
  
  // Adder pS til strukturen.
  
  // Updater set af kendte subunit IDs
  // Updater set af kendte absolutte reference punkter i strukturen
  
  // Skab link.

  // Check der ikke er cykliske loops i strukturen..
}


AbsoluteReferencePointList* Structure::FindPath(AbsLink &L)       //finder path mellem to reference points og laver en liste med den path
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
