#ifndef SOMMET_H
#define SOMMET_H

#include "Arc.h"

class CSommet
{
private:
    unsigned int uiSMTnumero;
	unsigned int uiSMTnbArrivant;
	unsigned int uiSMTnbPartant;
	CArc ** ppARCSMTarrivant;
	CArc ** ppARCSMTpartant;

public:
	CSommet(const CSommet& SMTparam);
	CSommet(unsigned int uiParam);
	~CSommet();

public:
	unsigned int SMTgetNumero();
	CArc const * const * SMTgetPartant() const;
	CArc const * const * SMTgetArrivant() const;
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);
	static void SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant);
	unsigned int SMTgetNbArrivant() const;
	unsigned int SMTgetNbPartant() const;
    //TODO fonction pour inverser arcs
    //TODO fonction pour afficher sommet

private:
	void SMTajouterArcPartant(CSommet& SMTdest);
	void SMTajouterArcArrivant(CSommet& SMTdest);
	void SMTsupprimerArcPartant(CSommet& SMTdest);
	void SMTsupprimerArcArrivant(CSommet& SMTdest);
};

#endif