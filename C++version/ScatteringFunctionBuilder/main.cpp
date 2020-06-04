#include "Structure.hpp"
#include "RWPolymer.hpp"
#include "GeneralSubUnit.hpp"
#include "Rod.hpp"
#include <vector>

int main()
{
//-------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------- Two chain polymer---------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------
Structure Chain("Chain");

   vector<RWPolymer> rWPolymer;
   
   RWPolymer p0("p0");

   Chain.Add(&p0);
   
   RWPolymer p1("p1");
   Chain.Join(&p1, RelRefPoint("end1"), AbsRefPoint("p0","end2"));

   cout << latex;

   cout << Chain.getFormFactor(0) << "= \n";
   cout << Chain.getFormFactor(0) << "\\\\ \n \n";

   cout << Chain.getFormFactor(0) << "= \n";
   cout << Chain.getFormFactor(1) << "\\\\ \n \n";

   cout << Chain.getFormFactor(0) << "= \n";
   cout << Chain.getFormFactor(2) << "\\\\ \n \n";

   cout << Chain.getFormFactor(0) << "= \n";
   cout << Chain.getFormFactor(3) << "\\\\ \n \n";

   cout << Chain.getFormFactor(0) << "= \n";
   cout << Chain.getFormFactor(4) << "\\\\ \n \n";
   /*
//-------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------- one rod ---------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------
//generate a rod
Rod r1("r1");

//generate a structure 
Structure SRod("SRod");

//Add rod r1 to the structure
SRod.Add(&r1);

cout << latex;
//gets the formfactor of r1
cout << r1.getFormFactor( 0 ) << "=" << r1.getFormFactor( 3 ) << "\n\n";
      
//Generates two relative reference points
RelRefPoint rel1("end1");
RelRefPoint rel2("end2");

//gets the formfactor amplitude of r1 relative rel1
cout << r1.getFormFactorAmplitude( rel1 , 0) << "="; 
cout << r1.getFormFactorAmplitude( rel1 , 2) << "\n\n";

//gets phase factor of r1 for the path rel1 to rel2
cout << r1.getPhaseFactor(rel1, rel2, 0) << "="; 
cout << r1.getPhaseFactor(rel1, rel2, 1) <<"\n\n";
*//*
//-------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------- Chain of rods ---------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------
Structure Chain("Chain");

   vector<Rod> rWPolymer;
   
   Rod p0("p0");

   Chain.Add(&p0);
   
   Rod p1("p1");
   Rod p2("p2");
   Rod p3("p3");
   Rod p4("p4");
   Rod p5("p5");
   Rod p6("p6");
   Rod p7("p7");
   Rod p8("p8");
   Rod p9("p9");
   
   Rod p10("p10");
   Rod p11("p11");
   Rod p12("p12");
   Rod p13("p13");
   Rod p14("p14");
   Rod p15("p15");
   Rod p16("p16");
   Rod p17("p17");
   Rod p18("p18");
   Rod p19("p19");
   Rod p20("p20");
   Rod p21("p21");
   Rod p22("p22");
   Rod p23("p23");
   Rod p24("p24");



   Chain.Join(&p1, RelRefPoint("end1"), AbsRefPoint("p0","end2"));
   Chain.Join(&p2, RelRefPoint("end1"), AbsRefPoint("p1","end2"));
   Chain.Join(&p3, RelRefPoint("end1"), AbsRefPoint("p2","end2"));
   Chain.Join(&p4, RelRefPoint("end1"), AbsRefPoint("p3","end2"));
   Chain.Join(&p5, RelRefPoint("end1"), AbsRefPoint("p4","end2"));
   Chain.Join(&p6, RelRefPoint("end1"), AbsRefPoint("p5","end2"));
   Chain.Join(&p7, RelRefPoint("end1"), AbsRefPoint("p6","end2"));
   Chain.Join(&p8, RelRefPoint("end1"), AbsRefPoint("p7","end2"));
   Chain.Join(&p9, RelRefPoint("end1"), AbsRefPoint("p8","end2"));
   Chain.Join(&p10, RelRefPoint("end1"), AbsRefPoint("p9","end2"));
   Chain.Join(&p11, RelRefPoint("end1"), AbsRefPoint("p10","end2"));
   Chain.Join(&p12, RelRefPoint("end1"), AbsRefPoint("p11","end2"));
   Chain.Join(&p13, RelRefPoint("end1"), AbsRefPoint("p12","end2"));
   Chain.Join(&p14, RelRefPoint("end1"), AbsRefPoint("p13","end2"));
   
   Chain.Join(&p15, RelRefPoint("end1"), AbsRefPoint("p14","end2"));
   Chain.Join(&p16, RelRefPoint("end1"), AbsRefPoint("p15","end2"));
   Chain.Join(&p17, RelRefPoint("end1"), AbsRefPoint("p16","end2"));
   Chain.Join(&p18, RelRefPoint("end1"), AbsRefPoint("p17","end2"));
   Chain.Join(&p19, RelRefPoint("end1"), AbsRefPoint("p18","end2"));
   Chain.Join(&p20, RelRefPoint("end1"), AbsRefPoint("p19","end2"));
   Chain.Join(&p21, RelRefPoint("end1"), AbsRefPoint("p20","end2"));
   Chain.Join(&p22, RelRefPoint("end1"), AbsRefPoint("p21","end2"));
   Chain.Join(&p23, RelRefPoint("end1"), AbsRefPoint("p22","end2"));
   Chain.Join(&p24, RelRefPoint("end1"), AbsRefPoint("p23","end2"));


   cout << latex;

   cout << Chain.getFormFactor(0) << "= \n";
   cout << Chain.getFormFactor(4) << "\\\\ \n \n";
*/
/*
//-------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------- Chain of polymers ---------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------

   Structure Chain("Chain");

   vector<RWPolymer> rWPolymer;
   
   RWPolymer p0("p0");

   Chain.Add(&p0);
   
   RWPolymer p1("p1");
   RWPolymer p2("p2");
   RWPolymer p3("p3");
   RWPolymer p4("p4");
   RWPolymer p5("p5");
   RWPolymer p6("p6");
   RWPolymer p7("p7");
   RWPolymer p8("p8");
   RWPolymer p9("p9");
   RWPolymer p10("p10");
   RWPolymer p11("p11");
   RWPolymer p12("p12");
   RWPolymer p13("p13");
   RWPolymer p14("p14");
   RWPolymer p15("p15");
   RWPolymer p16("p16");
   RWPolymer p17("p17");
   RWPolymer p18("p18");
   RWPolymer p19("p19");
   RWPolymer p20("p20");
   RWPolymer p21("p21");
   RWPolymer p22("p22");
   RWPolymer p23("p23");
   RWPolymer p24("p24");
   RWPolymer p25("p25");
   RWPolymer p26("p26");
   RWPolymer p27("p27");
   RWPolymer p28("p28");
   RWPolymer p29("p29");
   RWPolymer p30("p30");
   RWPolymer p31("p31");
   RWPolymer p32("p32");
   RWPolymer p33("p33");
   RWPolymer p34("p34");
   RWPolymer p35("p35");
   RWPolymer p36("p36");
   RWPolymer p37("p37");
   RWPolymer p38("p38");
   RWPolymer p39("p39");
   RWPolymer p40("p40");
   RWPolymer p41("p41");
   RWPolymer p42("p42");
   RWPolymer p43("p43");
   RWPolymer p44("p44");
   RWPolymer p45("p45");
   RWPolymer p46("p46");
   RWPolymer p47("p47");
   RWPolymer p48("p48");
   RWPolymer p49("p49");
   //RWPolymer p44("p44");

   Chain.Join(&p1, RelRefPoint("end1"), AbsRefPoint("p0","end2"));
   Chain.Join(&p2, RelRefPoint("end1"), AbsRefPoint("p1","end2"));
   Chain.Join(&p3, RelRefPoint("end1"), AbsRefPoint("p2","end2"));
   Chain.Join(&p4, RelRefPoint("end1"), AbsRefPoint("p3","end2"));
   Chain.Join(&p5, RelRefPoint("end1"), AbsRefPoint("p4","end2"));
   Chain.Join(&p6, RelRefPoint("end1"), AbsRefPoint("p5","end2"));
   Chain.Join(&p7, RelRefPoint("end1"), AbsRefPoint("p6","end2"));
   Chain.Join(&p8, RelRefPoint("end1"), AbsRefPoint("p7","end2"));
   Chain.Join(&p9, RelRefPoint("end1"), AbsRefPoint("p8","end2"));
   Chain.Join(&p10, RelRefPoint("end1"), AbsRefPoint("p9","end2"));
   Chain.Join(&p11, RelRefPoint("end1"), AbsRefPoint("p10","end2"));
   Chain.Join(&p12, RelRefPoint("end1"), AbsRefPoint("p11","end2"));
   Chain.Join(&p13, RelRefPoint("end1"), AbsRefPoint("p12","end2"));
   Chain.Join(&p14, RelRefPoint("end1"), AbsRefPoint("p13","end2"));
   Chain.Join(&p15, RelRefPoint("end1"), AbsRefPoint("p14","end2"));
   Chain.Join(&p16, RelRefPoint("end1"), AbsRefPoint("p15","end2"));
   Chain.Join(&p17, RelRefPoint("end1"), AbsRefPoint("p16","end2"));
   Chain.Join(&p18, RelRefPoint("end1"), AbsRefPoint("p17","end2"));
   Chain.Join(&p19, RelRefPoint("end1"), AbsRefPoint("p18","end2"));
   Chain.Join(&p20, RelRefPoint("end1"), AbsRefPoint("p19","end2"));
   Chain.Join(&p21, RelRefPoint("end1"), AbsRefPoint("p20","end2"));
   Chain.Join(&p22, RelRefPoint("end1"), AbsRefPoint("p21","end2"));
   Chain.Join(&p23, RelRefPoint("end1"), AbsRefPoint("p22","end2"));
   Chain.Join(&p24, RelRefPoint("end1"), AbsRefPoint("p23","end2"));
   Chain.Join(&p25, RelRefPoint("end1"), AbsRefPoint("p24","end2"));
   Chain.Join(&p26, RelRefPoint("end1"), AbsRefPoint("p25","end2"));
   Chain.Join(&p27, RelRefPoint("end1"), AbsRefPoint("p26","end2"));
   Chain.Join(&p28, RelRefPoint("end1"), AbsRefPoint("p27","end2"));
   Chain.Join(&p29, RelRefPoint("end1"), AbsRefPoint("p28","end2"));
   Chain.Join(&p30, RelRefPoint("end1"), AbsRefPoint("p29","end2"));
   Chain.Join(&p31, RelRefPoint("end1"), AbsRefPoint("p30","end2"));
   Chain.Join(&p32, RelRefPoint("end1"), AbsRefPoint("p31","end2"));
   Chain.Join(&p33, RelRefPoint("end1"), AbsRefPoint("p32","end2"));
   Chain.Join(&p34, RelRefPoint("end1"), AbsRefPoint("p33","end2"));
   Chain.Join(&p35, RelRefPoint("end1"), AbsRefPoint("p34","end2"));
   Chain.Join(&p36, RelRefPoint("end1"), AbsRefPoint("p35","end2"));
   Chain.Join(&p37, RelRefPoint("end1"), AbsRefPoint("p36","end2"));
   Chain.Join(&p38, RelRefPoint("end1"), AbsRefPoint("p37","end2"));
   Chain.Join(&p39, RelRefPoint("end1"), AbsRefPoint("p38","end2"));
   Chain.Join(&p40, RelRefPoint("end1"), AbsRefPoint("p39","end2"));
   Chain.Join(&p41, RelRefPoint("end1"), AbsRefPoint("p40","end2"));
   Chain.Join(&p42, RelRefPoint("end1"), AbsRefPoint("p41","end2"));
   Chain.Join(&p43, RelRefPoint("end1"), AbsRefPoint("p42","end2"));
   Chain.Join(&p44, RelRefPoint("end1"), AbsRefPoint("p43","end2"));
   Chain.Join(&p45, RelRefPoint("end1"), AbsRefPoint("p44","end2"));
   Chain.Join(&p46, RelRefPoint("end1"), AbsRefPoint("p45","end2"));
   Chain.Join(&p47, RelRefPoint("end1"), AbsRefPoint("p46","end2"));
   Chain.Join(&p48, RelRefPoint("end1"), AbsRefPoint("p47","end2"));
   Chain.Join(&p49, RelRefPoint("end1"), AbsRefPoint("p48","end2"));
   *//*
   cout << latex;

   int length = 10;

   for(int poly = 1; poly <= length ; poly ++ ){
      rWPolymer.push_back(RWPolymer("p"+to_string(poly)));
   }

   for(int i = 1; i < length; i++){
      Chain.Join(&rWPolymer[(i)], RelRefPoint("end1"), AbsRefPoint("p"+to_string((i-1)),"end2"));
      cout << "p"+to_string(i) << "\n";
   }
   */
  /*
   cout << Chain.getFormFactor(0) << "= \n";
   cout << Chain.getFormFactor(4) << "\\\\ \n \n";
 */  
/*
//-------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------- STAR OF RODS ---------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------

   Rod main("main");

   Structure Star("Star");

   Star.Add(&main);
   
   vector<Rod> vRod;

   int maxarms = 4;

   for(int arm = 0; arm <= maxarms; arm ++ ){
      vRod.push_back(Rod("r" + to_string(arm)));
   }

   for(int i =0; i <= maxarms; i++){
      Star.Join(&vRod[i], RelRefPoint("end1"), AbsRefPoint("main","end1"));
   }

   cout << latex;

   cout << Star.getFormFactor(0) << "= \n";
   cout << Star.getFormFactor(1) << "\\\\ \n \n";

   AbsRefPoint abs("r1", "end2");
   AbsRefPoint abs2("r1","end1");
   AbsRefPoint abs3("r" + to_string(maxarms%2), "end2");

   

   cout << Star.getFormFactorAmplitude( abs2, 0 ) << "= \n";
   cout << Star.getFormFactorAmplitude( abs2, 4 ) << "\\\\ \n \n";

   cout << Star.getPhaseFactor(abs, abs3, 0) << "= \n";
   cout << Star.getPhaseFactor(abs, abs3, 4) << "\\\\ \n \n";
*//*
//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------STAR OF POLYMERS ------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------
   RWPolymer main("main");

   Structure Star("Star");

   Star.Add(&main);
   
   vector<RWPolymer> rWPolymer;

   cout << latex;

   int maxarms = 100;

   for(int arm = 0; arm <= maxarms; arm ++ ){
      rWPolymer.push_back(RWPolymer("p" + to_string(arm)));
   }
   
   for(int i =0; i <= maxarms; i++){
      Star.Join(&rWPolymer[i], RelRefPoint("end1"), AbsRefPoint("main","end1"));
   }
   */
   /*
   for(int i = maxarms/2; i <= maxarms; i++){
      Star.Join(&rWPolymer[i], RelRefPoint("end1"), AbsRefPoint("main","end2"));
   }*/

   
   /*
   cout << Star.getFormFactor(0) << "= \n";
   cout << Star.getFormFactor(4) << "\\\\ \n \n";

   AbsRefPoint abs("p1", "end1");
   AbsRefPoint abs2("p10","end1");
   AbsRefPoint abs3("p" + to_string(maxarms%2), "end2");

   cout << Star.getFormFactorAmplitude( abs2, 0 ) << "= \n";
   cout << Star.getFormFactorAmplitude( abs2, 4 ) << "\\\\ \n \n";

   cout << Star.getPhaseFactor(abs, abs3, 0) << "= \n";
   cout << Star.getPhaseFactor(abs, abs3, 4) << "\\\\ \n \n";
   */
/*
//-------------------------------------------------------------------------------------------------------------------------------------------------
// micelle
//-------------------------------------------------------------------------------------------------------------------------------------------------
 GeneralSubUnit g1("A", 2);
 GeneralSubUnit g2("B", 2);
 GeneralSubUnit g3("D", 2);
 GeneralSubUnit gmid("C", 3);
 
 Structure Star("star");

 Star.Add(&gmid);
 Star.Join(&g1, RelRefPoint("end1"), AbsRefPoint("C","end1"));
 Star.Join(&g2, RelRefPoint("end1"), AbsRefPoint("C","end2"));
 Star.Join(&g3, RelRefPoint("end1"), AbsRefPoint("C","end3"));

 cout << latex;

   cout << Star.getFormFactor(0) << "= \n";
   cout << Star.getFormFactor(4) << "\\\\ \n \n";

   AbsRefPoint abs("A", "end2");
   AbsRefPoint abs2("B","end2");
   AbsRefPoint abs3("D", "end2");

   cout << Star.getFormFactorAmplitude( abs2, 0 ) << "= \n";
   cout << Star.getFormFactorAmplitude( abs2, 4 ) << "\\\\ \n \n";

   cout << Star.getPhaseFactor(abs, abs3, 0) << "= \n";
   cout << Star.getPhaseFactor(abs, abs3, 4) << "\\\\ \n \n";
*/
/*
//-------------------------------------------------------------------------------------------------------------------------------------------------
//----4 rods in chain
//-------------------------------------------------------------------------------------------------------------------------------------------------
   Rod r1("r1");                                            
   Rod r2("r2");                                             
   Rod r3("r3");                                            
   Rod r4("r4");
                                             

   Structure S("S");                                                   
   
   S.Add(&r1);                                                            
   S.Join(&r2, RelRefPoint("end1"), AbsRefPoint("r1","end2"));            
   S.Join(&r3, RelRefPoint("end1"), AbsRefPoint("r2","end2"));            
   S.Join(&r4, RelRefPoint("end1"), AbsRefPoint("r3","end2"));
   
   cout << latex;

   cout << S.getFormFactor(0) << "= \n";
   cout << S.getFormFactor(1) << "\\\\ \n \n";

   cout << S.getFormFactor(0) << "= \n";
   cout << S.getFormFactor(4) << "\\\\ \n \n";
   */
   /*
   AbsRefPoint abs("r1", "end2");
   AbsRefPoint abs2("r2","end2");
   AbsRefPoint abs3("r4", "end2");

   cout << S.getFormFactorAmplitude( abs2, 0 ) << "= \n";
   cout << S.getFormFactorAmplitude( abs2, 1 ) << "\\\\ \n \n";

   cout << S.getPhaseFactor(abs, abs3, 0) << "= \n";
   cout << S.getPhaseFactor(abs, abs3, 1) << "\\\\ \n \n";
   */
   

   /*
   cout << "The Abseloute Refence Points that are linked is: \n";         //printer abseloute reference der er linked
   for( auto i = S.Links.begin(); i != S.Links.end(); i++ ){
      cout << i -> GetLink() << ", ";
   } 
   cout << "\n \n";
   
   //Generate a polymer
        RWPolymer p1("p1");     
        RWPolymer p2("p2");
        RWPolymer p3("p3");
        RWPolymer p4("p4");
        //Generate a structure
        Structure S("Sp");       
        
        //Add the polymer p1 to the structure S
        S.Add(&p1);            
        
        //Join the second polymer together in a chain
        S.Join(&p2, RelRefPoint("end1"), AbsRefPoint("p1","end2"));
        S.Join(&p3, RelRefPoint("end1"), AbsRefPoint("p2","end2"));
        S.Join(&p4, RelRefPoint("end1"), AbsRefPoint("p3","end2"));
        //Get ginac to output in latex format
        cout << latex;
        
        //prints the formfactor of the structure S
        cout << S.getFormFactor(0) << "=";
        cout << S.getFormFactor(3) << "\n \n";
      
      //defining two abselout reference points you want the path for
      AbsRefPoint abs1 = AbsRefPoint("p1", "end1");                             
      AbsRefPoint abs2 = AbsRefPoint("p4", "end2");

      //prints the phase factor of structures path from abs1 to abs2
      cout << S.getPhaseFactor(abs1, abs2, 0) << "=" << S.getPhaseFactor( abs1, abs2, 3 ) << "\n\n"; 

      //Gets the form factor amplitude structure a point abs1
      cout << S.getFormFactorAmplitude(abs1, 0) << "=" << S.getFormFactorAmplitude( abs1, 2 ) << "\n\n"; 


      //generate a rod
      Rod r1("r1");

      //generate a structure 
      Structure SRod("SRod");

      //Add rod r1 to the structure
      SRod.Add(&r1);

      //gets the formfactor of r1
      cout << r1.getFormFactor( 0 ) << "=" << r1.getFormFactor( 3 ) << "\n\n";
      
      //Generates two relative reference points
      RelRefPoint rel1("end1");
      RelRefPoint rel2("end2");

      //gets the formfactor of r2
      cout << r1.getFormFactorAmplitude( rel1 , 0) << "=" << r1.getFormFactorAmplitude( rel1 , 2) << "\n\n";
      cout << r1.getPhaseFactor(rel1, rel2, 0) << "=" << r1.getPhaseFactor(rel1, rel2, 1) <<"\n\n";

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

      

   RelativeReferencePointSet REFA = s1.getRelRefSet();                  //printer alle relative refence points i s1 ud

   for(auto i = REFA.begin(); i != REFA.end(); i++ ){
      cout << *i << "\n"; 
   }
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

   Struct2Sub stub( "stub", &S );

   Structure S2S("S2S");

   S2S.Add(&stub);


   for(auto r: stub.getRelRef()){
      cout << r.GetrefID() << "\n";
   }

   cout << "\n \n" <<"The Structure, " << S.get_Id() << ", is now made to a sub unit, " << stub.getId() << ", and then added to " << S2S.get_Id() << "that has the factors: \n";
   cout << S2S.getFormFactor(0) << "=" << S2S.getFormFactor(2) << "\n \n";
   
   
   RelRefPoint rlrp = *(stub.getRelRefSet().begin());
   cout << rlrp << "\n";
   RelRefPoint rlrp2 = *(stub.getRelRefSet().rbegin());
   cout << rlrp2 << "\n";
   cout << stub.getFormFactorAmplitude( rlrp  ,0) << "=" << stub.getFormFactorAmplitude( rlrp , 1) << "\n \n";
   cout << stub.getPhaseFactor(  rlrp , rlrp2, 0) << " = " << stub.getPhaseFactor(rlrp, rlrp2, 1) << "\n";
 
   cout << "\n \n" <<"Some of the factors of s1 are" << "\n";
   cout << s1.getFormFactor( 0 ) << "\n";
   
   cout << "\n \n The structure is now convertet to a sub unit called str: \n";
   Struct2Sub str("oncestructure", S, ABSTRACT );

   cout << "\n \n" <<"Some of the factors of str are" << "\n";
   cout << str.subUnitFormFactor() << "\n";
   */
   /*
   RelRefPoint relpoint1( s1.getRelRefSet() find("end1"));
   cout << s1.getFormFactorAmplitude( relpoint1 , s1.getId() ) << "\n";                            //giver formfaktoren for p1 p2 og strukturen S
   RelRefPoint relpoint2(s1.getRelRefSet() -> find("end4"));
   RelLink rel(relpoint1, relpoint2);
   cout << s1.getPhaseFactor( rel, s1.getId() ) << "\n";
   */
};
