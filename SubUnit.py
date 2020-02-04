class subunit
import math
# returns the formfacetor amplitude of the sub unit as a function, a char and latex-string
def formfactorAmplitude(typ, name , Aeq ):
     A = Aeq
     Asymbol = "A" + name
     Alatex = "A" + "_" + "{" + name + "}"
     Alist = {A,Asymbol, Alatex}
     return Alist

# returns the formfactor of the sub unit as a function, a char and latex-string
def formfactor(typ, name , Feq ):
    F = Feq
    Fsymbol = "F" + name
    Flatex = "F"  + "_" + "{" + name + "}"
    Flist = {F,Fsymbol, Flatex}
    return Flist


# returns the phasefactor of the amplitude as a function, a char and latex-string
def phasefactor(typ, name, PHIeq):
    PHI = PHIeq 
    PHIsymbol = "PHI" + name
    PHIlatex = "\Phi" + "_" + "{" + name + "}"
    PHIlist = {PHI,PHIsymbol, PHIlatex}
    return PHIlist

class SubUnit:

    #constructor: Contructs sub unit with an id, its referencepoints its varialbles.
    def __init__( self , typ , Aeq , Feq , PHIeq , name , refpoints):
        ID = name
        referencepoints = refpoints
        variable = var
        formfactor(typ, ID , Feq)
        formfactorAmplitude(typ, ID, Aeq )
        phasefactor(typ, ID, PHIeq )

    #Main functions runs the program
if __name__ == "__main__":
        import Rod
        ID = Rod.ID
        referencepoints = Rod.referencepoints()
        typ = Rod.typ()
        Aeq = Rod.Aeq()
        Feq = Rod.Feq()
        PHIeq = Rod.PHIeq()
        print( formfactorAmplitude( typ , ID , Aeq ) )
        print( formfactor( typ, ID , Feq ) )
        print( phasefactor( typ, ID, PHIeq ) )
        SubUnit(typ, Aeq , Feq, PHIeq , ID , referencepoints, variable)

   
