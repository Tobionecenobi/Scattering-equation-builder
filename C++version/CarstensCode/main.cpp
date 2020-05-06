#include "Structure.hpp"
#include "RWPolymer.hpp"
#include "GeneralSubUnit.hpp"

int main()
{
   GeneralSubUnit s1("s1", 4);                                            //laver general subunit s1
   GeneralSubUnit s2("s2", 4);                                            //laver general subunit s2
   GeneralSubUnit s3("s3", 4);                                            //laver general subunit s3
   GeneralSubUnit s4("s4", 4);                                            //laver general subunit s4

   Structure S("GeneralStructure");                                       //laver strukturen S
   
   S.Add(&s1);                                                            //sætter sub unit s1 in i strukturen
   S.Join(&s2, RelRefPoint("end1"), AbsRefPoint("s1","end4"));            //sætter sub unit s1 og sub unit s2 sammen
   S.Join(&s3, RelRefPoint("end1"), AbsRefPoint("s2","end4"));            //sætter sub unit s2 og sub unit s3 sammen
   S.Join(&s4, RelRefPoint("end1"), AbsRefPoint("s3","end4"));            //sætter sub unit s3 og sub unit s4 sammen

   cout << "The Abseloute Refence Points that are linked is: \n";         //printer abseloute reference der er linked
   for( auto i = S.Links.begin(); i != S.Links.end(); i++ ){
      cout << i -> GetLink() << ", ";
   } 
   cout << "\n \n";

   AbsRefPoint A = AbsRefPoint("s1", "end1");                             //Laver abseloute refencepoint
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
   vector<AbsRefPoint> phasepath = S.searchRef2Ref(A,B);

   cout << "The path from (" << A.GetAbsRefPoint() << ") to (" << B.GetAbsRefPoint() << ") is:\n";

   S.printPath(phasepath);
   //--------------------------------------------------------------------------------------------------------------------------

   //prints path from sub unit to ref
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> amplitudepath = S.searchSubUnit2Ref(A, s4.getId());

   cout << "\n\n The path from SubUnit (" << s4.getId() << ") to Abseloutreferencepoint (" << A.GetAbsRefPoint() << ") is:\n";
   
   S.printPath( amplitudepath );
   //--------------------------------------------------------------------------------------------------------------------------

   //prints path from ref to sub unit
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> path2 = S.searchRef2SubUnit(A, s4.getId());

   cout << "\n\n The path from Abseloutreferencepoint (" << A.GetAbsRefPoint() << ") to SubUnit (" << s4.getId() << ") to is:\n";
   
   S.printPath(path2);
   //--------------------------------------------------------------------------------------------------------------------------

   //prints path from ref to sub unit
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> path3 = S.searchSubUnit2SubUnit(s1.getId(), s4.getId());

   cout << "\n\n The path from sub unit (" << s1.getId() << ") to sub unit (" << s4.getId() << ") to is:\n";
   
   S.printPath(path3);
   //--------------------------------------------------------------------------------------------------------------------------

   cout << "\n \n" << "The abstract Phase factor of the structure path " << A.GetAbsRefPoint() << " to " << B.GetAbsRefPoint() << " is: \n";
   cout << S.getAbstractPhaseFactor( phasepath );

   cout << "\n \n" << "The Phase factor of the structure path " << A.GetAbsRefPoint() << " to " << B.GetAbsRefPoint() << " is: \n";
   cout << S.getPhaseFactor( phasepath );   

   cout << "\n \n" << "The Abstract formfactor is: \n" ;
   cout << S.getAbsractFormFactorAmplitude(A);

   cout << "\n \n" <<"The form factors are" << "\n";
   cout << S.getAbstractFormFactor() << "\n";
   cout << s1.getFormFactor( s1.getId() ) << "\n";
   cout << s2.getFormFactor( s2.getId() ) << "\n";                            //giver formfaktoren for p1 p2 og strukturen S
};
