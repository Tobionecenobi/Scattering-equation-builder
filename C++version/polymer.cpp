
    // Parameterized Constructor wich gives the form-, ampltiude- phase- phactor, name and id.  
    Polymer::Polymer(int uniqueID) {
        id = uniqueID;
        name = "flexible polymer"; 
        formFactor = "(2*(exp(-x)-1+x))/x*x";
        amplitudeFactor = "(1-exp(-x))/x";
        phaseFactor = "exp(-x)";
    }

    //returns the value of the form factor of a flexiblepolymer for long input x
    long formFactor(long x){
        return (2*(exp(-x)-1+x))/x*x;
    }

    //returns the amplitude factor of a flexiblepolymer for long input x
    long amplitudeFactor(long x){
        return (1-exp(-x))/x;
    }

    //returns the phas factor of a flexiblepolymer for long input x
    long phaseFactor(long x){
        return exp(-x);
    }




