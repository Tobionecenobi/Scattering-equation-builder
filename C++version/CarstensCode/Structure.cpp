#include <iostream>
#include <string>
#include <ginac/ginac.h>
#include "Structure.hpp"

using namespace GiNaC;
using namespace std;

void Structure::AddAbsoluteRefPoints(SubUnit* pS){

  set<RelRefPoint>::iterator it;
  
  for(it = pS -> RefPoints.begin(); it != pS -> RefPoints.end(); it++){
    StructRefPoints.insert( AbsRefPoint( pS -> getId() , *it ) );        //<====== *it giver for håbenligt value og it er adressen
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

void Structure::Link( AbsRefPoint Ra, AbsRefPoint Rb){
  Links.insert( AbsLink( Ra , Rb ) );
}

bool Structure::SubUnitExist( SubUnit* pS){
  return subunits.count( pS -> getId() ); //returns 1 when true and 0 when false
}

void Structure::Join(SubUnit* pS, RelRefPoint Rr, AbsRefPoint Ra) //joiner to strukturer sammen
{
  // Test at strukturen ikke er tom,
  
  // Test at relative referencepoint tilhører subunit pS <=== skal implementere i Subunit

  // Test at pS->GetID ikke findes i forvejen i strukturen.
                                         
  // Test at Ra findes i strukturen.
  
  // Adder pS til strukturen.
  
  // Updater set af kendte subunit IDs
  // Updater set af kendte absolutte reference punkter i strukturen
  
  // Skab link.

  // Check der ikke er cykliske loops i strukturen..

  AbsRefPoint a( pS -> getId() , Rr );

  if (Ra.GetAbsRefPoint() == ""){
    cout << "There are no subunits to add the new subunit" << "\n";
  }
  

  else if ( subunits.find( pS -> getId() ) == subunits.end() ){        //Try so find the subunit id. If not found() returns end() to iterator. then checks if it == end().
    Add( pS );
    Link( a , Ra );
  }
}

//Checks if R1 and R2 is Linked
bool Structure::isLinked(AbsRefPoint& R1, AbsRefPoint& R2){

  string a = AbsLink(R1, R2).GetLink(); // retunere en streng "R1<=>R2"
  set<AbsLink>::iterator it;

  for(it = Links.begin(); it  != Links.end(); it++ ){
    AbsLink b = *it;
    if(b.GetLink() == a){
      return true;
    }
    else continue;
    }
  return false;
}


set<AbsRefPoint> Structure::NeighborAbsRef( AbsRefPoint& x ){

  set<AbsLink>::iterator it;
  set<AbsRefPoint> neighborTox; 
                                      
  
  //linkedTox.insert(x); //x is linked to it self, so i dont have to write loop for it. 

  //KIG PÅ PAIR OG PRØV AT OMDEFINER 
  for(it = Links.begin(); it != Links.end(); it++){ //go to every absrefpoint in structure
    if( it -> isPartnerOfPairLink( x ) ){
      neighborTox.insert( it -> getLinkMember( x ) ); //get abselout refpoint
    }
  }

  //set<AbsRefPoint>::iterator it; //is declared 12 lines above
  map< SubunitID , SubUnit* >::iterator itmap;
  set<RelRefPoint>::iterator itrelref;

   
    
    
    SubunitID subId = x.GetsubID(); //gets subunit ID
    itmap = StoredSubUnits.find( subId ); //finds subunit
    RelativeReferencePointSet relrefset = itmap -> second -> getRelRefSet(); //get relreferencepoints
    
    for(itrelref = relrefset.begin(); itrelref != relrefset.end(); itrelref++){ // convert relrefpoint to absrefpoint
      RelRefPoint relrefpoint = *itrelref;
      AbsRefPoint nx =  AbsRefPoint( subId, relrefpoint );
      if( !(nx == x) ){
        neighborTox.insert( nx );
      }
    }
  
  return neighborTox;
  

}

vector<AbsRefPoint> Structure::searchRef2Ref(AbsRefPoint& I, AbsRefPoint& J){
  vector<AbsRefPoint> path; //empty path

  if ( I == J ){ 
    return path; //same reference point
  }
  if ( isLinked( I , J ) ){
    return path;
  }
  // how to make a pointer 
  //AbsRefPoint *p = &I;

  //search front 
  queue<AbsRefPoint> queue;

  //Visited reference points
  set<AbsRefPoint> visited;

  //Child parent relation for making tree
  map<AbsRefPoint,AbsRefPoint> parent;

  //searching from J to I for getting path I to J
  queue.push(J);
  visited.insert(J);
  AbsRefPoint x;

  J.GetsubID();

  while(!queue.empty()){
    x = queue.front();                                                  //sets x to be equal the oldest element in the queue
    queue.pop();                                                        //removes the oldest element and return none

    if(x == I) { break; }                                               // if x == I then the path is found'

    set<AbsRefPoint>::iterator it;                                      //iterator for going through the neighbor list

    set<AbsRefPoint> neighborList = NeighborAbsRef(x);

    for( it = neighborList.begin() ; it != neighborList.end() ; ++it ){ //goes through every neigbor
      
      AbsRefPoint neighbor = *it; 
      
      if(  visited.find(neighbor) != visited.end() ) { continue; }      //checks if the neighbor is visited

      parent.insert( pair<AbsRefPoint , AbsRefPoint>(neighbor, x) );    //neigbor (child) maps to x (parent) making a tree.
      visited.insert(neighbor);                                         //put the neighbor to visited
      queue.push(neighbor);                                             //put neigbor in the queue so it can be treated as x in the future
    }
  }

  if( x != I )                                                          //if I is not found print a message
  { cout << "When looking for path " << I.GetAbsRefPoint() << " to " << J.GetAbsRefPoint() << ", " << I.GetAbsRefPoint() << " could not be found" << "\n" ;}

  //time to go back through tree and find the path

  if( x == I){

    map<AbsRefPoint, AbsRefPoint>::iterator it = parent.find(x);

    bool rootchecker = false;

    while( rootchecker == false )
    {

      pair<AbsRefPoint , AbsRefPoint> currentParent = *it;
      path.push_back( currentParent );
      currentparent = parent
  }

  return path;

}

AbsoluteReferencePointList* Structure::FindPath(AbsLink &L)             //finder pa th mellem to reference points og laver en liste med den path
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
/*


*/