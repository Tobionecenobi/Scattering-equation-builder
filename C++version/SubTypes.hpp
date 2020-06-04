/*
SubUnit types
Each sub-unit needs a unique type ID, such that we can upconvert Structure* pointers to the specific type.
*/

enum { ABSTRACT, GAUSSIANRANDOMWALK, MAXTYPE, NONINITIALIZED, ROD, GENERAL, STRUCTURE };

typedef int TypeID;  


