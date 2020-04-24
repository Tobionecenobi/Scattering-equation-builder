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

//returns a set of all neigbours to an abseloutrefencepoint
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
      if( nx != x ){
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

  set<AbsRefPoint>::iterator it;                                        //iterator for going through the neighbor list

  while(!queue.empty()){
    x = queue.front();                                                  //sets x to be equal the oldest element in the queue
    queue.pop();                                                        //removes the oldest element and return none

    if(x == I) break;                                                   // if x == I then the path is found'

    set<AbsRefPoint> neighborList = NeighborAbsRef(x);

    for( it = neighborList.begin() ; it != neighborList.end() ; ++it ){ //goes through every neigbor
      
      //AbsRefPoint neighbor = *it; 
      
      if(  visited.find( *it ) == visited.end() ) continue;             //checks if the neighbor is visited

      //parent.insert( pair<AbsRefPoint , AbsRefPoint>( *it , x) );     //neigbor (child) maps to x (parent) making a tree.
      parent[ *it ] = x; 
      visited.insert( *it );                                            //put the neighbor to visited
      queue.push( *it );                                                //put neigbor in the queue so it can be treated as x in the future
    }
  }

  if( x != I )                                                          //if I is not found print a message
  { cout << "When looking for path " << I.GetAbsRefPoint() << " to " << J.GetAbsRefPoint() << ", " << I.GetAbsRefPoint() << " could not be found" << "\n" ;}

  //time to go back through tree and find the path

  if( x == I ){

    map<AbsRefPoint, AbsRefPoint>::iterator it = parent.find( I );

    while( it -> first != J )  // Stops before J
    {
      path.push_back( it -> first );
      it = parent.find( it -> second  );
    }
    path.push_back( J );
  }
  return path; 
}

//see if refpoint is linked to subunit.
bool Structure::refLinkedToSubUnit(AbsRefPoint& I, SubunitID sid){
  
  map<SubunitID , SubUnit*>::iterator itmap;                                             //Find the subunit and get its relativereference points
  itmap = StoredSubUnits.find( sid ); 
  RelativeReferencePointSet relrefset = itmap -> second -> getRelRefSet();

  set<RelRefPoint>::iterator it;                                                         //Checks if referencepoint I is on the subunit. if it is it returns true
  for( it = relrefset.begin(); it != relrefset.end(); it++ ){
    AbsRefPoint abs = AbsRefPoint( sid , *it );
    if(isLinked( abs , I )) return true;
  }
  return false;
}

vector<AbsRefPoint> Structure::searchSubUnit2Ref(AbsRefPoint& I, SubunitID sid){
  vector<AbsRefPoint> path; 

  //checks if reference point is not on the subunit or linked to the subunit
  if (I.GetsubID() == sid) return path;
  if (refLinkedToSubUnit(I, sid)) return path;

  //search front 
  queue<AbsRefPoint> queue;

  //Visited reference points
  set<AbsRefPoint> visited;

  //Child parent relation for making tree
  map<AbsRefPoint,AbsRefPoint> parent;

  //searching from I to Subunit for getting path Subunit to I
  queue.push(I);
  visited.insert(I);
  AbsRefPoint x;

  set<AbsRefPoint>::iterator it;

  while(!queue.empty()){
    x = queue.front();                                                  //sets x to be equal the oldest element in the queue
    queue.pop();                                                        //removes the oldest element and return none

    if( x.GetsubID() == sid ) break;                                    //if x is on the subunit then the path is found <===================================

    set<AbsRefPoint> neighborList = NeighborAbsRef(x);

    for( it = neighborList.begin() ; it != neighborList.end() ; ++it ){ //goes through every neigbor
        
      if(  visited.find( *it ) == visited.end() ) continue;             //checks if the neighbor is visited

      //parent.insert( pair<AbsRefPoint , AbsRefPoint>( *it , x) );     //neigbor (child) maps to x (parent) making a tree.
      parent[ *it ] = x; 
      visited.insert( *it );                                            //put the neighbor to visited
      queue.push( *it );                                                //put neigbor in the queue so it can be treated as x in the future
    }
  }

  if( x.GetsubID() != sid )                                                          //if I is not found print a message
    { cout << "When looking for path " << I.GetAbsRefPoint() << " to subunit " << sid << ", " << sid << " could not be found" << "\n" ;}

  if( x.GetsubID() == sid ){

    map<AbsRefPoint, AbsRefPoint>::iterator it = parent.find( x );      //finds x which is the first refence point that hit the subunit

    while( it -> first != I )                                           //Stops before I
    {
      path.push_back( it -> first );
      it = parent.find( it -> second  );
    }
    path.push_back( I );                                                //puts the missing refpoint I into the path
  }

  return path;                                                          // return path subunit-> A-> ...-> B-> I
}

//returns the oppisite path than searchSubunit2ref
vector<AbsRefPoint> Structure::searchRef2SubUnit(AbsRefPoint& I, SubunitID sid){
  vector<AbsRefPoint> path;
  vector<AbsRefPoint> oppisitepath =searchSubUnit2Ref( I , sid );
  vector<AbsRefPoint>::iterator it = oppisitepath.end();

  for(it; it != oppisitepath.begin(); it--){ 
    path.push_back( *it );
  }

  return path;
}

//returns the path between two Subunits
bool Structure::subUnitLinkedToSubUnit(SubunitID sid1 , SubunitID sid2 ){
  
  map<SubunitID , SubUnit*>::iterator itmap;                                             //Find the subunits and get its relativereference points
  
  itmap = StoredSubUnits.find( sid1 ); 
  RelativeReferencePointSet relrefset1 = itmap -> second -> getRelRefSet();

  itmap = StoredSubUnits.find( sid2 ); 
  RelativeReferencePointSet relrefset2 = itmap -> second -> getRelRefSet();

  set<RelRefPoint>::iterator it1;                                                    
  set<RelRefPoint>::iterator it2;
  for( it1 = relrefset1.begin(); it1 != relrefset1.end(); it1++ ){
   
    AbsRefPoint abs1 = AbsRefPoint( sid1 , *it1 );
    
    for(it2 =relrefset2.begin(); it2 != relrefset2.end(); it2++){

    AbsRefPoint abs2 = AbsRefPoint( sid2 , *it2 );
    if(isLinked( abs1 , abs2 )) return true;
    }
  }
  return false;
}

vector<AbsRefPoint> Structure::searchSubUnit2SubUnit( SubunitID sid1, SubunitID sid2){
  
  vector<AbsRefPoint> path; 

  if( sid1 == sid2 ) return path;
  if( subUnitLinkedToSubUnit( sid1, sid2) ) return path; 

  //search front 
  queue<AbsRefPoint> queue;

  //Visited reference points
  set<AbsRefPoint> visited;

  //Child parent relation for making tree
  map<AbsRefPoint,AbsRefPoint> parent;

  //gives all referencepoints on a sub unit
  map<SubunitID , SubUnit*>::iterator itmap;
  itmap = StoredSubUnits.find( sid2 ); 
  RelativeReferencePointSet relrefset2 = itmap -> second -> getRelRefSet();

  set<RelRefPoint>::iterator it2;

  //insert all of subunit1 reference point into queue and visited
  for( it2 = relrefset2.begin(); it2 != relrefset2.end(); it2++ ){
    AbsRefPoint abs2 = AbsRefPoint( sid2 , *it2 );
    queue.push( abs2 );
    visited.insert( abs2 );
  }

   AbsRefPoint x;
  set<AbsRefPoint>::iterator it;

  while(!queue.empty()){
    x = queue.front();                                                  //sets x to be equal the oldest element in the queue
    queue.pop();                                                        //removes the oldest element and return none

    if( x.GetsubID() == sid1 ) break; 

    set<AbsRefPoint> neighborList = NeighborAbsRef(x);

    for( it = neighborList.begin() ; it != neighborList.end() ; ++it ){ //goes through every neigbor
        
      if(  visited.find( *it ) == visited.end() ) continue;             //checks if the neighbor is visited

      //parent.insert( pair<AbsRefPoint , AbsRefPoint>( *it , x) );     //neigbor (child) maps to x (parent) making a tree.
      parent[ *it ] = x; 
      visited.insert( *it );                                            //put the neighbor to visited
      queue.push( *it );                                                //put neigbor in the queue so it can be treated as x in the future
    }
  }

  if( x.GetsubID() != sid1 )                                                          //if I is not found print a message
    { cout << "When looking for path from subunit " << sid1 << " to subunit " << sid2 << ", " << sid1 << " could not be found" << "\n" ;}

  if( x.GetsubID() == sid1 ){

    map<AbsRefPoint, AbsRefPoint>::iterator it = parent.find( x );      //finds x which is the first refence point that hit the subunit
    bool subUnitTouched = false; 

  while( it -> first.GetsubID() != sid1 && subUnitTouched)                                           //Stops before I
    {
      path.push_back( it -> first );
      it = parent.find( it -> second  );
      if( it -> first.GetsubID() == sid1) subUnitTouched = true;
    }
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
