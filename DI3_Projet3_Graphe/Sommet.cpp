#include "Sommet.h"
#include <stdlib.h>

CSommet::CSommet(const CSommet& SMTparam)
{
	/*uinbArrivant = 0;
	uinbPartant = 0;
	ppARCarrivant = (CArc **) malloc(0);
	ppARCpartant = (CArc **) malloc(0);*/
}

CSommet::~CSommet(void)
{

}

void CSommet::SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant){}
void CSommet::SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant){}
CArc const * const * CSommet::SMTgetPartant() const{}
CArc const * const * CSommet::SMTgetArrivant() const{}
unsigned int CSommet::SMTgetNbArrivant() const{}
unsigned int CSommet::SMTgetNbPartant() const{}

void CSommet::SMTajouterArcPartant(CSommet& SMTdest){}
void CSommet::SMTajouterArcArrivant(CSommet& SMTdest){}
void CSommet::SMTsupprimerArcPartant(CSommet& SMTdest){}
void CSommet::SMTsupprimerArcArrivant(CSommet& SMTdest){}