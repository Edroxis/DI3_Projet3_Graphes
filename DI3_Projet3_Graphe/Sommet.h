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
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);
	static void SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant);

	unsigned int SMTgetNumero();
	CArc const * const * SMTgetPartant() const;
	CArc const * const * SMTgetArrivant() const;
	unsigned int SMTgetNbArrivant() const;
	unsigned int SMTgetNbPartant() const;
    void SMTprintSommet();
    //TODO fonction pour inverser arcs

private:
	void SMTajouterArcPartant(CSommet& SMTdest);
	void SMTajouterArcArrivant(CSommet& SMTdest);
	void SMTsupprimerArcPartant(CSommet& SMTdest);
	void SMTsupprimerArcArrivant(CSommet& SMTdest);
};

#endif
