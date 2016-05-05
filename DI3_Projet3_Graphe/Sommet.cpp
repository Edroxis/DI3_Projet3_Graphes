#include "Sommet.h"
#include <stdlib.h>

CSommet::CSommet(const CSommet& SMTparam)
{
    //Necessaire? cf tous les passages de CSommet se font par reference
}

CSommet::CSommet(unsigned int uiParam){
    uiSMTnumero = uiParam;
    uiSMTnbArrivant = 0;
	uiSMTnbPartant = 0;
	ppARCSMTarrivant = (CArc **) malloc(0 * sizeof(CArc *));
	ppARCSMTpartant = (CArc **) malloc(0 * sizeof(CArc *));
}

CSommet::~CSommet(void)
{
    unsigned int uiboucle;

    uiSMTnumero = 0;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant; uiboucle++)
        delete ppARCSMTarrivant[uiboucle];
    for(uiboucle = 0; uiboucle < uiSMTnbPartant; uiboucle++)
        delete ppARCSMTpartant[uiboucle];
}

unsigned int CSommet::SMTgetNumero(){
    return uiSMTnumero;
}

CArc const * const * CSommet::SMTgetPartant() const{
    return ppARCSMTpartant;
}

CArc const * const * CSommet::SMTgetArrivant() const{
    return ppARCSMTarrivant;
}

unsigned int CSommet::SMTgetNbArrivant() const{
    return uiSMTnbArrivant;
}

unsigned int CSommet::SMTgetNbPartant() const{
    return uiSMTnbPartant;
}

void CSommet::SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant){
    SMTpartant.SMTajouterArcPartant(SMTarrivant);
    SMTarrivant.SMTajouterArcArrivant(SMTpartant);
}

void CSommet::SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant){
    SMTpartant.SMTsupprimerArcPartant(SMTarrivant);
    SMTarrivant.SMTsupprimerArcArrivant(SMTpartant);
}

void CSommet::SMTajouterArcPartant(CSommet& SMTdest){
    uiSMTnbPartant++;
    ppARCSMTpartant = (CArc **) realloc(ppARCSMTpartant, uiSMTnbPartant * sizeof (CArc *));
    ppARCSMTpartant[uiSMTnbPartant-1] = new CArc(SMTdest);
}

void CSommet::SMTajouterArcArrivant(CSommet& SMTdest){
    uiSMTnbArrivant++;
    ppARCSMTarrivant = (CArc **) realloc(ppARCSMTarrivant, uiSMTnbArrivant * sizeof (CArc *));
    ppARCSMTarrivant[uiSMTnbArrivant-1] = new CArc(SMTdest);
}

void CSommet::SMTsupprimerArcPartant(CSommet& SMTdest){
    unsigned int uiboucle;

    uiSMTnbPartant--;

    for(uiboucle = 0; uiboucle < uiSMTnbPartant && SMTdest.SMTgetNumero() != ppARCSMTpartant[uiboucle]->ARCgetDest().SMTgetNumero(); uiboucle++);
    for(; uiboucle < uiSMTnbPartant/*-1*/; uiboucle++)
        ppARCSMTpartant[uiboucle] = ppARCSMTpartant[uiboucle+1];

    ppARCSMTpartant = (CArc **) realloc(ppARCSMTpartant, uiSMTnbPartant * sizeof(CArc*));
}

void CSommet::SMTsupprimerArcArrivant(CSommet& SMTdest){
    unsigned int uiboucle;

    uiSMTnbArrivant--;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant && SMTdest.SMTgetNumero() != ppARCSMTarrivant[uiboucle]->ARCgetDest().SMTgetNumero(); uiboucle++);
    for(; uiboucle < uiSMTnbArrivant/*-1*/; uiboucle++)
        ppARCSMTarrivant[uiboucle] = ppARCSMTarrivant[uiboucle+1];

    ppARCSMTarrivant = (CArc **) realloc(ppARCSMTarrivant, uiSMTnbArrivant * sizeof(CArc*));
}
