#include "Structure.hpp"
#include "RWPolymer.hpp"
#include "GeneralSubUnit.hpp"
#include "Struct2Sub.hpp"

int main()
{
   GeneralSubUnit s1("s1", 4);                                            //laver general subunit s1
   GeneralSubUnit s2("s2", 4);                                            //laver general subunit s2
   GeneralSubUnit s3("s3", 4);                                            //laver general subunit s3
   GeneralSubUnit s4("s4", 4);                                            //laver general subunit s4

   Structure S("GS");                                       //laver strukturen S
   
   S.Add(&s1);                                                            //sætter sub unit s1 in i strukturen
   S.Join(&s2, RelRefPoint("end1"), AbsRefPoint("s1","end4"));            //sætter sub unit s1 og sub unit s2 sammen
   S.Join(&s3, RelRefPoint("end1"), AbsRefPoint("s2","end4"));            //sætter sub unit s2 og sub unit s3 sammen
   S.Join(&s4, RelRefPoint("end1"), AbsRefPoint("s3","end4"));            //sætter sub unit s3 og sub unit s4 sammen

   cout << "The Abseloute Refence Points that are linked is: \n";         //printer abseloute reference der er linked
   for( auto i = S.Links.begin(); i != S.Links.end(); i++ ){
      cout << i -> GetLink() << ", ";
   } 
   cout << "\n \n";

   AbsRefPoint A1 = AbsRefPoint("s1", "end1");                             //Laver abseloute refencepoint
   AbsRefPoint B = AbsRefPoint("s4", "end4");                             //Laver abseloute refencepoint 

   /*RelativeReferencePointSet REFA = s1.getRelRefSet();                  //printer alle relative refence points i s1 ud

   for(auto i = REFA.begin(); i != REFA.end(); i++ ){
      cout << *i << "\n"; 
   }*/
                                                                           //printer alle stored sub units i strukturen
   cout << "The stored subunits are: \n";
   map<SubunitID, SubUnit*> stsubs = S.getStoredSubUnits();
   auto i = stsubs.begin();
   while( i != stsubs.end() ){
      cout << i -> first << "\n";
      i++;
   }

   //print path from ref to ref
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> phasepath = S.searchRef2Ref(A1,B);

   cout << "The path from (" << A1.GetAbsRefPoint() << ") to (" << B.GetAbsRefPoint() << ") is:\n";

   S.printPath(phasepath);
   //--------------------------------------------------------------------------------------------------------------------------

   //prints path from sub unit to ref
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> amplitudepath = S.searchSubUnit2Ref(A1, s4.getId());

   cout << "\n\n The path from SubUnit (" << s4.getId() << ") to Abseloutreferencepoint (" << A1.GetAbsRefPoint() << ") is:\n";
   
   S.printPath( amplitudepath );
   //--------------------------------------------------------------------------------------------------------------------------

   //prints path from ref to sub unit
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> path2 = S.searchRef2SubUnit(A1, s4.getId());

   cout << "\n\n The path from Abseloutreferencepoint (" << A1.GetAbsRefPoint() << ") to SubUnit (" << s4.getId() << ") to is:\n";
   
   S.printPath(path2);
   //--------------------------------------------------------------------------------------------------------------------------

   //prints path from ref to sub unit
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> path3 = S.searchSubUnit2SubUnit(s1.getId(), s4.getId());

   cout << "\n\n The path from sub unit (" << s1.getId() << ") to sub unit (" << s4.getId() << ") to is:\n";
   
   S.printPath(path3);
   //--------------------------------------------------------------------------------------------------------------------------

   //uncomment to get everything in latex format
   cout << latex;

   cout << "\n \n" << "The abstract Phase factor of the structure path " << A1.GetAbsRefPoint() << " to " << B.GetAbsRefPoint() << " is: \n";
   cout << S.getPhaseFactor(A1, B, 0) << "=" << S.getPhaseFactor( A1, B, 1 );
   
   cout << "\n \n" << "The Abstract Amplitude form factor is: \n" ;
   cout << S.getFormFactorAmplitude(A1, 0) << "=" << S.getFormFactorAmplitude(A1, 1);

   cout << "\n \n" <<"The form factors are" << "\n";
   cout << S.getFormFactor(0) << "=" << S.getFormFactor(1) << "\n";

   Struct2Sub stub( "stub", S, ABSTRACT );
   cout << "\n \n" <<"The Structure, " << S.get_Id() << ", is now made to a sub unit, " << stub.getId() << ", that has the factors: \n";
   cout << stub.getFormFactor(0) << "=" << stub.getFormFactor(2) << "\n \n";
   
   RelRefPoint rlrp = *(stub.getRelRefSet().begin());
   cout << rlrp << "\n";
   RelRefPoint rlrp2 = *(stub.getRelRefSet().rbegin());
   cout << rlrp2 << "\n";
   cout << stub.getFormFactorAmplitude( rlrp  ,0) << "=" << stub.getFormFactorAmplitude( rlrp , 1) << "\n \n";
   cout << stub.getPhaseFactor(  rlrp , rlrp2, 0) << " = " << stub.getPhaseFactor(rlrp, rlrp2, 1) << "\n";
 
   cout << "\n \n" <<"Some of the factors of s1 are" << "\n";
   cout << s1.getFormFactor( 0 ) << "\n";
   
   /*cout << "\n \n The structure is now convertet to a sub unit called str: \n";
   Struct2Sub str("oncestructure", S, ABSTRACT );

   cout << "\n \n" <<"Some of the factors of str are" << "\n";
   cout << str.subUnitFormFactor() << "\n";*/

   /*
   RelRefPoint relpoint1( s1.getRelRefSet() find("end1"));
   cout << s1.getFormFactorAmplitude( relpoint1 , s1.getId() ) << "\n";                            //giver formfaktoren for p1 p2 og strukturen S
   RelRefPoint relpoint2(s1.getRelRefSet() -> find("end4"));
   RelLink rel(relpoint1, relpoint2);
   cout << s1.getPhaseFactor( rel, s1.getId() ) << "\n";
   */
};
