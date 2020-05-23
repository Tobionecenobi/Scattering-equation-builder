//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_STRUCT2SUB
#define INCLUDE_GUARD_STRUCT2SUB

//===========================================================================
// included dependencies
#include "SubUnit.hpp"
#include "GeneralSubUnit.hpp"
#include <iostream>
#include <utility>
using namespace std;

//===========================================================================
// The acutual class
class Struct2Sub : public GeneralSubUnit{
    
    public:

    Structure St;
    SubunitID sid;
    //Convert structure to a subunit of a specefic type, and name the relative reference point "structure id:subunit id: original relative ref point id"
    Struct2Sub( SubunitID id , Structure* S): GeneralSubUnit(id){
        
        type = STRUCTURE; 
        St = *S;
        sid = id;

        St.StoredSubUnits.clear();

        //Rename all absolute reference points
        AbsoluteReferencePointSet newAbsref;
        AbsoluteReferencePointSet originalAbsref = St.getAbsRef();
        set<AbsRefPoint>::iterator it;

        map<SubunitID, SubUnit*>::iterator itmap;
        RelativeReferencePointSet::iterator rt; 

        //tries to change stored subunits id's
        for( auto r: St.getStoredSubUnits()){
            r.second -> changerelrepoints( r.first);
            r.second -> changeID(sid);
            //r.first = id;
        }
        
        for(it = originalAbsref.begin(); it != originalAbsref.end(); it++){
            AbsRefPoint relrefp( sid ,it -> GetAbsRefPoint() );
            cout << relrefp.GetAbsRefPoint() << "\n";
            newAbsref.insert( relrefp );
        }

        cout << "Struct2sub created! The test absolute reference points are: \n";
        for(it = newAbsref.begin(); it != newAbsref.end() ; it++){
            cout << it -> GetAbsRefPoint() << "\n";
        }

        //Swaps the whole original set of reference points with new refence point set
        St.clearAbsRefPoints();
        for(it = newAbsref.begin(); it != newAbsref.end(); it++){
            St.insertAbsRefPoints( *it );
        }

        cout << "The absolute reference points are: \n";
        St.printAbsRefSet();

        //Generate relative reference points from absolute reference
        cout << "relative reference points are made \n"; 
        for (auto r : St.getAbsRef()){
            cout << r.GetrefID() << "\n";
            AddReferencePoint( RelRefPoint( r.GetrefID() ) );
        }     
    }

    AbsoluteReferencePointSet getRelRef(){
        return St.getAbsRef();
    }
    

    ex  getFormFactor( int form = 2 ){
        return St.getFormFactor( form ); 
    }

    ex getFormFactorAmplitude( RelRefPoint &relref , int form = 2){
        AbsRefPoint a(sid, relref);
        return St.getFormFactorAmplitude( a, form);
    }

    ex getPhaseFactor( RelRefPoint &R1, RelRefPoint &R2, int form = 2){
        AbsRefPoint a(sid, R1);
        AbsRefPoint b(sid, R2);
        return St.getPhaseFactor( a, b, form );
    }
    
    /*
    //Convert structure to a subunit of a specefic type, and name the relatives reference point with a string you choose + the number of the rel ref point
    Struct2Sub( SubunitID sid, Structure& S, TypeID t, string refname ) : GeneralSubUnit(sid){               //GeneralSubUnit 
    
        type = t;                                                             //hvilken type distribution den bruger
        id = sid;
        
        AbsoluteReferencePointSet absref = S.StructRefPoints;
        set<AbsRefPoint>::iterator it;

        int count = 1;

        for(it = absref.begin(); it != absref.end(); it++){
            RelRefPoint relrefp( refname + to_string(count) );
            AddReferencePoint( relrefp );
            count++;
        }

        FormFactor = S.getFormFactor( 2 ); 

        set<AbsRefPoint>::iterator jt;
        count = 1;

        for( it = absref.begin(); it != absref.end(); it++){                                    //giver formfactoramplituden fra reference punkt end#i
            AbsRefPoint a = *it;
            RelRefPoint relrefp( refname + to_string(count) );
            FormFactorAmplitudes[ relrefp ] = S.getFormFactorAmplitude( a, 2 );     
        }

        count = 0;
        for( it = absref.begin(); it != absref.end(); it++){                                    //giver fase faktoren for end#i end end#i+1
            count++;
            int countj = 1;
            for(jt = absref.begin(); jt != absref.end(); jt++){
                if( it -> GetrefID() < jt -> GetrefID() ){
                AbsRefPoint a = *it, b = *jt;
                RelRefPoint relrefp( refname + to_string(count) );
                RelRefPoint relrefp2( refname + to_string(countj) );
                PhaseFactors[ relrefp ] [ relrefp2 ] = S.getPhaseFactor( a , b , 2);
                countj++;
                }     
            }   
        }
    }
    */
};

#endif //INCLUDE_GUARD_STRUCT2SUB