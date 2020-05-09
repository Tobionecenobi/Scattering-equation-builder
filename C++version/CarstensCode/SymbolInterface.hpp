//===========================================================================
// Included guards
#ifndef INCLUDE_GUARD_SYMBOLINTERFACE
#define INCLUDE_GUARD_SYMBOLINTERFACE

//===========================================================================
// included dependencies
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <ginac/ginac.h> 
using namespace GiNaC;
using namespace std;

class SymbolInterface{
    public:

    static map<string, symbol> symbolDirectory;
    static map<string, ex> indexDirectory;
    
    //Returns a standart utf8 symbol or if input is an array of size 2 it returns utf8 symbol and its latex format
    static const symbol & getSymbol( const string s, const  string latex = "" );
        
    //takes up to 5 ex and the first is a symbol the other 4 is indicies
    static const ex & getIndex( const ex s, const ex s1);
    static const ex & getIndex( const ex s, const ex s1, const ex s2);
    static const ex & getIndex( const ex s, const ex s1, const ex s2, const ex s3);
    static const ex & getIndex( const ex s, const ex s1, const ex s2, const ex s3, const ex s4);
};

#endif