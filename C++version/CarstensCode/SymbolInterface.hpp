//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_SYMBOLINTERFACE
#define INCLUDE_GUARD_SYMBOLINTERFACE

//===========================================================================
// included dependencies
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <ginac/ginac.h>

using namespace GiNaC;
using namespace std;

class SymbolInterface{
    private:
    static SymbolInterface* myInstance;

    public:

    SymbolInterface(){ }

    map<string, symbol> symbolDirectory;
    map<string, ex> indexDirectory;
    
    static SymbolInterface* instance(); 

    //Returns a standart utf8 symbol or if input is an array of size 2 it returns utf8 symbol and its latex format
    const symbol & getSymbol( const string s, const  string latex = "" );
        
    //takes up to 5 ex and the first is a symbol the other 4 is indicies
    const ex  getIndex( const ex s, const ex s1);
    const ex  getIndex( const ex s, const ex s1, const ex s2);
    const ex  getIndex( const ex s, const ex s1, const ex s2, const ex s3);
    const ex  getIndex( const ex s, const ex s1, const ex s2, const ex s3, const ex s4);
};

#endif