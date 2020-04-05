#include "Structure.hpp"
#include "RWPolymer.hpp"

int main()
{
   RWPolymer P1("p1");                                            //laver polymer p1
   RWPolymer P2("p2");                                            //laver polymer p2
   
   Structure S("blockcopolymer");                                 //laver strukturen S
   
   S.Add(&P1);                                                    //sætter polymer p1 in i strukturen
   S.Join(&P2, RelRefPoint("end1"), AbsRefPoint("p1","end2") );   //sætter polymer p1 og polymer p2 sammen

   cout << S.getFormFactor() << "\n";
   cout << P1.getFormFactor() << "\n";
   cout << P2.getFormFactor() << "\n";                            //giver formfaktoren for p1 p2 og strukturen S
}
