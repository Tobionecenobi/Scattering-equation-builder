// SubUnit types
// Each sub-unit needs a unique type ID, such that we can upconvert Structure* pointers to the specific type.

enum { ABSTRACT=1, GAUSSIANRANDOMWALK, MAXTYPE, NONINITIALIZED };

typedef int TypeID;  


