#include <iostream>
#include <string>
#include <ginac/ginac.h>
#include "SymbolInterface.hpp"

using namespace GiNaC;
using namespace std;

//Resets Symbol interface
SymbolInterface* SymbolInterface::myInstance = 0;

// In first call to instance, generate symbol interface class
SymbolInterface* SymbolInterface::instance(){
    if( !myInstance ){
        myInstance = new SymbolInterface();
    }
    return myInstance;
}

//Return the symbol of the string from the symbol interface
const symbol & SymbolInterface::getSymbol( const string s, const string latex = "" ){
    if( latex.empty() ){
        map<string, symbol>::iterator it = symbolDirectory.find( s );
        if( it != symbolDirectory.end()) return it -> second; 
        else{
            return symbolDirectory.insert( make_pair( s , symbol( s) )).first -> second;
        }
    }
    else{
        map<string, symbol>::iterator it = symbolDirectory.find( s );
        if( it != symbolDirectory.end()) return it -> second; 
        else{
            return symbolDirectory.insert( make_pair( s , symbol( s, latex ) )).first -> second;
        }
    }
}
    
//takes up to 5 ex and the first is a symbol the other 4 is indicies
const ex & SymbolInterface::getIndex( const ex s, const ex s1){
    idx const indeks( s1, 1);
    return indexed( s , indeks );
}

const ex  SymbolInterface::getIndex( const ex s, const ex s1, const ex s2){
    idx const indeks1( s1, 1), indeks2( s2, 1);
    return indexed( s , indeks1, indeks2);
}

const ex  SymbolInterface::getIndex( const ex s, const ex s1, const ex s2, const ex s3){
    idx const indeks1( s1, 1), indeks2( s2, 1), indeks3( s3, 1);
    return indexed( s , indeks1, indeks2, indeks3);
}

const ex  SymbolInterface::getIndex( const ex s, const ex s1, const ex s2, const ex s3, const ex s4){
    idx const indeks1( s1, 1), indeks2( s2, 1), indeks3( s3, 1), indeks4( s4, 1);
    return indexed( s , indeks1, indeks2, indeks3, indeks4);
}