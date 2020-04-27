#include "Structure.hpp"
#include "RWPolymer.hpp"
#include "GeneralSubUnit.hpp"

int main()
{
   GeneralSubUnit s1("s1", 4);                                            //laver general subunit s1
   GeneralSubUnit s2("s2", 4);                                            //laver general subunit s2
   GeneralSubUnit s3("s3", 4);
   GeneralSubUnit s4("s4", 4);

   Structure S("GeneralStructure");                                 //laver strukturen S
   
   S.Add(&s1);                                                    //sætter polymer p1 in i strukturen
   S.Join(&s2, RelRefPoint("end1"), AbsRefPoint("s1","end4"));   //sætter polymer p1 og polymer p2 sammen
   S.Join(&s3, RelRefPoint("end1"), AbsRefPoint("s2","end4")); 
   S.Join(&s4, RelRefPoint("end1"), AbsRefPoint("s3","end4"));

   cout << "The Abseloute Refence Points that are linked is: \n";
   for( auto i = S.Links.begin(); i != S.Links.end(); i++ ){
      cout << i -> GetLink() << ", ";
   } 
   cout << "\n \n";

   AbsRefPoint A = AbsRefPoint("s1", "end1");
   AbsRefPoint B = AbsRefPoint("s4", "end4");

   /*RelativeReferencePointSet REFA = S1.getRelRefSet();

   for(auto i = REFA.begin(); i != REFA.end(); i++ ){
      cout << *i << "\n"; 
   }*/

   /*for(auto i = S.getStoredSubUnits().begin(); i != S.getStoredSubUnits().end(); i++ ){
      cout << i -> first << "\n";
   }*/
   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> path = S.searchRef2Ref(A,B);

   cout << "The path from (" << A.GetAbsRefPoint() << ") to (" << B.GetAbsRefPoint() << ") is:\n";

   S.printPath(path);
   //--------------------------------------------------------------------------------------------------------------------------

   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> path1 = S.searchSubUnit2Ref(A, s4.getId());

   cout << "\n\n The path from SubUnit (" << s4.getId() << ") to Abseloutreferencepoint (" << A.GetAbsRefPoint() << ") is:\n";
   
   S.printPath(path1);
   //--------------------------------------------------------------------------------------------------------------------------

   //--------------------------------------------------------------------------------------------------------------------------
   vector<AbsRefPoint> path2 = S.searchRef2SubUnit(A, s4.getId());

   cout << "\n\n The path from Abseloutreferencepoint (" << A.GetAbsRefPoint() << ") to SubUnit (" << s4.getId() << ") to is:\n";
   
   S.printPath(path2);
   //--------------------------------------------------------------------------------------------------------------------------

   cout << "\n" <<"The form factors are" << "\n";


   cout << S.getFormFactor() << "\n";
   cout << s1.getFormFactor() << "\n";
   cout << s2.getFormFactor() << "\n";                            //giver formfaktoren for p1 p2 og strukturen S

}
