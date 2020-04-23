#ifndef INCLUDE_GUARD_REFPOINT
#define INCLUDE_GUARD_REFPOINT

#include <string>
#include <utility>

/* Small class to represent a reference points and their relations */

/*
   a subunit needs to keep track of its reference points (strings relative to subunit).
   E.g. end1,end2 for a polymer  this is represented by RelRefPoint class==string.   
   
   a structure needs to keep track of the reference points of its subunits. (strings relative to structure)
   e.g. poly1:end1 and poly2:end2 ..      This is represented by the AbsRefPoint class.

   Phasefactors depends on pairs of reference points on the same sub-unit.
   e.g. end1<=>end2  RelLink takes care of this and the fact that links are symmetric.

   Structure needs to join sub-units by abstract reference points. 
   e.g. poly1:end2<=>poly2:end1  AbsLink takes care of this and the fact that such links are symmetric.
*/

// I think of reference points like  Subunit_id:referencepoint_id which are absolute (i.e. relative to the structure)
// Since sub-unit ids are unique, we can always address any reference point by such a string combination.
// Inside a sub-unit, we only need the referencepoint_ids  I think of these as relative to the sub-unit itself.

typedef string StructureID; //omdøber string til structure ID
typedef string SubunitID;
typedef string RelRefPoint;

class AbsRefPoint {
public:
    SubunitID   subID;      // Name of sub-unit
    RelRefPoint refID;      // Name of reference on that sub-unit

    AbsRefPoint() : subID(""), refID("") {;}                                                    //definere abseloute reference punkter når der ikke er nogle dvs. en tom streng
    AbsRefPoint(SubunitID _subID, RelRefPoint _refID) : subID(_subID), refID(_refID) {;}        //definere absolute refpoint når de er fyldte
    
    SubunitID   GetsubID()      const { return subID; }                                         //giver subunit id
    RelRefPoint GetrefID()      const { return refID; }                                         //giver reference punkt id

    void SetsubID(SubunitID _subID)   { subID=_subID; }                                         //sætter subunit id
    void SetrefID(RelRefPoint _refID) { refID=_refID; }                                         //sætter refencepunkt id
    
    string operator()()        const {  return subID+":"+refID; }                               //giver operator til at definere boolean måske <================
    string GetAbsRefPoint()    const {  return subID+":"+refID; }                               //giver absolute reference punkt = refid og subid

// We probably also need a comparison operator for RefPoints for sorting in maps
    bool operator <(AbsRefPoint &b) const { return GetAbsRefPoint()<b.GetAbsRefPoint(); }       //forklarer hvordan boolean kan sammenligne abseloute reference punkter
};

inline bool operator <(const AbsRefPoint &R1, const AbsRefPoint &R2) { return R1.GetAbsRefPoint()<R2.GetAbsRefPoint(); }
inline bool operator <(AbsRefPoint &R1, AbsRefPoint &R2) { return R1.GetAbsRefPoint()<R2.GetAbsRefPoint(); }
inline bool operator ==(AbsRefPoint &R1, AbsRefPoint &R2) { return R1.GetAbsRefPoint() == R2.GetAbsRefPoint();}
inline bool operator ==(const AbsRefPoint &a, const AbsRefPoint &b) {return a.GetAbsRefPoint()==b.GetAbsRefPoint(); }
inline bool operator !=(AbsRefPoint &R1, AbsRefPoint &R2) { return R1.GetAbsRefPoint() != R2.GetAbsRefPoint();}
inline bool operator !=(const AbsRefPoint &R1, const AbsRefPoint &R2) { return R1.GetAbsRefPoint() != R2.GetAbsRefPoint();}
typedef set<AbsRefPoint>                  AbsoluteReferencePointSet;      // Could be used in structure to keep track of all Refpoints
typedef list<AbsRefPoint>                 AbsoluteReferencePointList;     // Could be used for representing a path through a structure.
typedef set<RelRefPoint>                  RelativeReferencePointSet;      // Could be used in a subunit to list reference points

/*

*/

class AbsLink : public pair<AbsRefPoint,AbsRefPoint>                                   //linker abseloute referencepunkter og sorterer dem efer id.
{
  public:
    AbsLink(AbsRefPoint &R1,AbsRefPoint &R2)
     {
        if (R1<R2)
            {
               first=R1;
               second=R2;
            }
        else
            {
               first=R2;
               second=R1;
            }
     }

    string GetLink() { return first.GetAbsRefPoint()+"<=>"+second.GetAbsRefPoint(); }   //returnere linket som en streng
       
    bool operator <(AbsLink &b) { return GetLink()<b.GetLink(); }                       //fortæller boolean hvordan man kan sammenligne links

    bool isPartnerOfPairLink( AbsRefPoint& x ) const {  return (first == x || second == x) ; } //RENAME TO MEMBER <=========== har lovet 

    const AbsRefPoint& getLinkMember( AbsRefPoint& x ) const { 
        if(first == x){
            return second;
        }
        else if( second == x ){
            return first;
        }
        else {  cout << "Partner does not exist";
                return second; }
    }
};

inline bool operator<(AbsLink &R1, AbsLink &R2) { return R1.GetLink()<R2.GetLink(); }



class RelLink: public pair<RelRefPoint,RelRefPoint>                                     //linker kun reference punkter men ikke dens subunit.
{
  public:

   RelLink(RelRefPoint R1,RelRefPoint R2)
     {
        if (R1<R2)
            {
               first=R1;
               second=R2;
            }
        else
            {
               first=R2;
               second=R1;
            }
     }
  
    string GetLink() { return first+"<=>"+second; }                                     //returnerer relLinks som en streng          
    bool operator <(RelLink &b) { return GetLink()<b.GetLink(); }                       //forklarer boolean hvordan man sammenligner to links
};

inline bool operator<(RelLink &R1, RelLink &R2) { return R1.GetLink()<R2.GetLink(); }


#endif
