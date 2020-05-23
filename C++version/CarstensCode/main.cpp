#include "Structure.hpp"
#include "RWPolymer.hpp"
#include "GeneralSubUnit.hpp"
#include "Struct2Sub.hpp"
#include "Rod.hpp"

int main()
{
   /*
   Rod r1("s1");
   GeneralSubUnit s1("s1", 4);                                            //laver general subunit s1
   GeneralSubUnit s2("s2", 4);                                            //laver general subunit s2
   GeneralSubUnit s3("s3", 4);                                            //laver general subunit s3
   GeneralSubUnit s4("s4", 3);                                            //laver general subunit s4
   GeneralSubUnit s5("s5", 1);

   */
   //Structure S1("GS");                                       //laver strukturen S
   /*
   S1.Add(&s1);                                                            //sætter sub unit s1 in i strukturen
   S1.Join(&s2, RelRefPoint("end1"), AbsRefPoint("s1","end4"));            //sætter sub unit s1 og sub unit s2 sammen
   S1.Join(&s3, RelRefPoint("end1"), AbsRefPoint("s2","end4"));            //sætter sub unit s2 og sub unit s3 sammen
   S1.Join(&s4, RelRefPoint("end1"), AbsRefPoint("s3","end4"));            //sætter sub unit s3 og sub unit s4 sammen
   S1.Join(&s5, RelRefPoint("end1"), AbsRefPoint("s4","end3"));
   cout << "The Abseloute Refence Points that are linked is: \n";         //printer abseloute reference der er linked
   /*for( auto i = S.Links.begin(); i != S.Links.end(); i++ ){
      cout << i -> GetLink() << ", ";
   } 
   cout << "\n \n";*/
   

   AbsRefPoint A1 = AbsRefPoint("s1", "end1");                             //Laver abseloute refencepoint
   AbsRefPoint B = AbsRefPoint("s5", "end1");                             //Laver abseloute refencepoint 
   //Generate a polymer
        RWPolymer p1("p1");     
        RWPolymer p2("p2");
        RWPolymer p3("p3");
        RWPolymer p4("p4");
        RWPolymer p5("p5");
        //Generate a structure
        Structure S("S");       
        
        //Add the polymer p1 to the structure S
        S.Add(&p1);            
        
        //Join the second polymer together in a chain
        S.Join(&p2, RelRefPoint("end1"), AbsRefPoint("p1","end2"));
        S.Join(&p3, RelRefPoint("end1"), AbsRefPoint("p2","end2"));
        S.Join(&p4, RelRefPoint("end1"), AbsRefPoint("p3","end2"));
        S.Join(&p5, RelRefPoint("end1"), AbsRefPoint("p4","end2"));
        //Get ginac to output in latex format
        cout << latex;
        
        //prints the formfactor of the structure S
        cout << S.getFormFactor(0) << "=";
        cout << S.getFormFactor(4) << "\n";


   //generate rods
        Rod r1("r1");
        Rod r2("r2");
        Rod r3("r3");
        Rod r4("r4");
        
        //Generate a structure
        Structure S1("S1");       
        
        //Add the polymer p1 to the structure S
        S1.Add(&r1);

        //Join the second polymer together in a chain
        S1.Join(&r2, RelRefPoint("end1"), AbsRefPoint("r1","end2"));
        S1.Join(&r3, RelRefPoint("end1"), AbsRefPoint("r2","end2"));
        S1.Join(&r4, RelRefPoint("end1"), AbsRefPoint("r3","end2"));

      //prints the formfactor of the structure S
        cout << S1.getFormFactor(0) << "=";
        cout << S1.getFormFactor(4) << "\n";

   /*RelativeReferencePointSet REFA = s1.getRelRefSet();                  //printer alle relative refence points i s1 ud

   for(auto i = REFA.begin(); i != REFA.end(); i++ ){
      cout << *i << "\n"; 
   }*/
   /*                                                                        //printer alle stored sub units i strukturen
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

   Struct2Sub stub( "stub", &S );

   Structure S2S("S2S");

   S2S.Add(&stub);


   for(auto r: stub.getRelRef()){
      cout << r.GetrefID() << "\n";
   }

   cout << "\n \n" <<"The Structure, " << S.get_Id() << ", is now made to a sub unit, " << stub.getId() << ", and then added to " << S2S.get_Id() << "that has the factors: \n";
   cout << S2S.getFormFactor(0) << "=" << S2S.getFormFactor(2) << "\n \n";
   */
   /*
   RelRefPoint rlrp = *(stub.getRelRefSet().begin());
   cout << rlrp << "\n";
   RelRefPoint rlrp2 = *(stub.getRelRefSet().rbegin());
   cout << rlrp2 << "\n";
   cout << stub.getFormFactorAmplitude( rlrp  ,0) << "=" << stub.getFormFactorAmplitude( rlrp , 1) << "\n \n";
   cout << stub.getPhaseFactor(  rlrp , rlrp2, 0) << " = " << stub.getPhaseFactor(rlrp, rlrp2, 1) << "\n";
 
   cout << "\n \n" <<"Some of the factors of s1 are" << "\n";
   cout << s1.getFormFactor( 0 ) << "\n";
   */
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
