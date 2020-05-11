//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_GENERALSUBUNIT
#define INCLUDE_GUARD_GENERALSUBUNIT

//===========================================================================
// included dependencies
#include "SubUnit.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <ginac/ginac.h> 
using namespace std;

//===========================================================================
// The acutual class
class GeneralSubUnit : public SubUnit {
  
    public:
    
    ex FormFactor;                                                          //definere formfactoren til at være en equation
    map<RelRefPoint,ex> FormFactorAmplitudes;                               // map: key er relrefpoint og mapper til en formfactor amplitude equation
    map< RelRefPoint ,map<RelRefPoint, ex> > PhaseFactors;                    // map: key er et rellink og mapper til en fase faktor equation


    exmap local1, local2; 
    /*RelativeReferencePointSet RefPoints;                                    //Laver relative reference poin set <======= Igen hvordan ved vi hvilken type?
    */ //RYKKET TILBAGE TIL SUBUNIT FORDI ELLERS KAN EN SUBUNIT IKKE TJEKKE SINE REFERENCE PUNKTER IGENNEM

    //GeneralSubUnit constructor that takes the sub unit ID
    GeneralSubUnit( SubunitID sid ) : SubUnit( sid ){
        type = NONINITIALIZED;
    }

    //GeneralSubUnit constructor that takes the sub Unit ID and the number of relative reference points
    GeneralSubUnit( SubunitID sid, int numOfRefPoints ) : SubUnit(sid){               //GeneralSubUnit 
        
        type = ABSTRACT;                                                             //hvilken type distribution den bruger

        for(int i = 1; i <= numOfRefPoints; i++){
            AddReferencePoint( RelRefPoint( "end" + to_string( i ) ) );              //adder reference point end + #i til objectet
        }
       
        FormFactor = SubUnit::getFormFactor();                                                              //giver formlen for formfactoren
        
        set<RelRefPoint>::iterator it;
        set<RelRefPoint>::iterator jt;

        for( it = RefPoints.begin(); it != RefPoints.end(); it++){                                    //giver formfactoramplituden fra reference punkt end#i
            RelRefPoint a = *it;
            FormFactorAmplitudes[ *it ] = SubUnit::getFormFactorAmplitude( a );     
        }

        for( it = RefPoints.begin(); it != RefPoints.begin(); it++){                                     //giver fase faktoren for end#i end end#i+1
            for(jt = RefPoints.begin(); jt != RefPoints.begin(); jt++){
                if( *it < *jt ){
                RelRefPoint a = *it, b = *jt;  
                PhaseFactors[ *it ][ *jt ] = SubUnit::getPhaseFactor( a , b );
                }     
            }   
        }
    }

    //GeneralSubUnit constructor that takes the sub Unit ID, a list that takes each reference individual id and the number of reference points
    GeneralSubUnit( SubunitID sid, int numOfRefPoints, vector<string> &s ) : SubUnit(sid){               //GeneralSubUnit 
        type = ABSTRACT;                                                                                       //hvilken type distribution den bruger

        for(int i = 0; i <= numOfRefPoints; i++){
            AddReferencePoint( s[i] );                                                                          //adder reference point end + #i til objectet
        }
       
        FormFactor = SubUnit::getFormFactor();                                                              //giver formlen for formfactoren
        
        set<RelRefPoint>::iterator it;
        set<RelRefPoint>::iterator jt;

        for( it = RefPoints.begin(); it != RefPoints.end(); it++){                                    //giver formfactoramplituden fra reference punkt end#i
            RelRefPoint a = *it;
            FormFactorAmplitudes[ *it ] = SubUnit::getFormFactorAmplitude( a );     
        }

        for( it = RefPoints.begin(); it != RefPoints.begin(); it++){                                     //giver fase faktoren for end#i end end#i+1
            for(jt = RefPoints.begin(); jt != RefPoints.begin(); jt++){
                if( *it < *jt ){
                RelRefPoint a = *it, b = *jt;  
                PhaseFactors[ *it ][ *jt ] = SubUnit::getPhaseFactor( a , b );
                }     
            }
        }
        
// more       
    }

    /*RelativeReferencePointSet getRelRefSet() { return RefPoints; }  //returner relativerefpoints

    virtual void AddReferencePoint( RelRefPoint R )                         //adder reference points til en abstract subunit
      {
         auto ret=RefPoints.insert(R);
         if (!ret.second) cout << "DIE Refpoint already in Refpointset";
      }
    */ // RYKKET TILBAGE TIL SUBUNIT FORDI ELLERS KAN EN SUBUNIT IKKE TJEKKE SINE REFERENCE PUNKTER IGENNEM

    bool has( RelRefPoint &R1 ){
       return RefPoints.find( R1 ) != RefPoints.end();
    }

    virtual ex getFormFactor( int form = 1 ){
        if(form == 0){
            return SubUnit::getFormFactor( form );
        }
        else if(form == 1){
            return FormFactor.subs( local1 ); 
        }
        else if(form == 2){
            return FormFactor.subs( local2 );
        }   
        throw "Wrong input in getFormFactor";
    }

    virtual ex getFormFactorAmplitude( RelRefPoint &R, int form = 1 ){
        
        if( ! has(R) ) throw "RelRefPoint does not exist";

        if(form == 0){
            return SubUnit::getFormFactorAmplitude( R );
        }
        else if( form == 1){
            return FormFactorAmplitudes[R].subs( local1 );
        }
        else if( form == 2){
            return FormFactorAmplitudes[R].subs( local2 );
        }
        throw "Wrong input in getFormFactorname()";
    }

    virtual ex getPhaseFactor( RelRefPoint &R1 , RelRefPoint &R2, int form = 1 ){
        
        if( !has(R1) || !has(R2) ) throw "RelRefPoint does not exist";
        
        if( R2 < R1 ){
            RelRefPoint temp = R1;
            R1 = R2;
            R2 = temp;
        }

        if( form == 0 ){
        return SubUnit::getPhaseFactor( R1, R2 );
        }
        else if( form == 1 ){
            if(R1 == R2) return ex (1.0);
            else return PhaseFactors[R1][R2].subs(local1);
        }
        else if( form == 2){
            if(R1 == R2) return ex (1.0);
            else return PhaseFactors[R1][R2].subs(local2);
        }
        throw "wrong form input";
    }
};


#endif // INCLUDE_GUARD_SUBUNIT 