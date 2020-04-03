#include "Structure.hpp"
#include "RWPolymer.hpp"

int main()
{
   RWPolymer P1("p1");
   RWPolymer P2("p2");
   
   Structure S("blockcopolymer");
   
   S.Add(&P1);
   S.Join(&P2, RelRefPoint("end1"), AbsRefPoint("p1","end2") );

   cout << S.getFormFactor() << "\n";
   cout << P1.getFormFactor() << "\n";
   cout << P2.getFormFactor() << "\n";
}
