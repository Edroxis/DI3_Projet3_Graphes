#include <iostream>
#include "Sommet.h"
#include <stdlib.h>
#include <cassert>

using namespace std;

CSommet::CSommet(const CSommet& SMTparam)
{
	/* TODO: Meme traitement pour l'opérateur = ?
	Est-ce vraiment nécessaire d'empêcher la copie, le problème se pose que quand
	2 sommets avec le meme numero sont dans un graphe mais CGraphe gère déjà
	cette problématique */
	assert(false && "Don't copy a CSommet, it's bad idea, you may burn in hell!");
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
	/* TODO: Doit-on autoriser l'ajout d'un arc déjà existant entre les 2 sommets ?
	En cas de refus, test unitaire ! */
	/* TODO: De même doit-on autoriser la création d'un arc entre un même sommet ? */

    SMTpartant.SMTajouterArcPartant(SMTarrivant);
    SMTarrivant.SMTajouterArcArrivant(SMTpartant);
}

void CSommet::SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant){
    SMTpartant.SMTsupprimerArcPartant(SMTarrivant);
    SMTarrivant.SMTsupprimerArcArrivant(SMTpartant);
}

void CSommet::SMTprintSommet(){
    unsigned int uiboucle;
    for(uiboucle = 0; uiboucle < uiSMTnbPartant; uiboucle++)
        cout << uiSMTnumero << "->" << ppARCSMTpartant[uiboucle]->ARCgetDest().SMTgetNumero() << endl;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant; uiboucle++)
        cout << uiSMTnumero << "<-" << ppARCSMTarrivant[uiboucle]->ARCgetDest().SMTgetNumero() << endl;
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

    for(uiboucle = 0; uiboucle < uiSMTnbPartant &&
		SMTdest.SMTgetNumero() != ppARCSMTpartant[uiboucle]->ARCgetDest().SMTgetNumero(); uiboucle++);

    for(; uiboucle < uiSMTnbPartant/*-1*/; uiboucle++)
        ppARCSMTpartant[uiboucle] = ppARCSMTpartant[uiboucle+1];

    ppARCSMTpartant = (CArc **) realloc(ppARCSMTpartant, uiSMTnbPartant * sizeof(CArc*));
}

void CSommet::SMTsupprimerArcArrivant(CSommet& SMTsrc){
    unsigned int uiboucle;

    uiSMTnbArrivant--;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant &&
		SMTsrc.SMTgetNumero() != ppARCSMTarrivant[uiboucle]->ARCgetDest().SMTgetNumero(); uiboucle++);

    for(; uiboucle < uiSMTnbArrivant/*-1*/; uiboucle++)
        ppARCSMTarrivant[uiboucle] = ppARCSMTarrivant[uiboucle+1];

    ppARCSMTarrivant = (CArc **) realloc(ppARCSMTarrivant, uiSMTnbArrivant * sizeof(CArc*));
}
