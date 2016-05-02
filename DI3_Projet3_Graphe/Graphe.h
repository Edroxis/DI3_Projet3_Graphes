#ifndef GRAPHE_H
#define GRAPHE_H

#include "Sommet.h"

class CGraphe
{
private:
	CSommet ** ppSMTliste;
	unsigned int uiGPHtotalSommet;
	unsigned int uiGPHtotalArc;

public:
	CGraphe();
	CGraphe(char const * const chemin);
	~CGraphe();

	void GPHajouterSommet(CSommet& SMTparam);
	void GPHsupprimerSommet(CSommet& SMTparam);
	CSommet& GPHgetSommet(int inumero);
	unsigned int GPHgetTotalSommet() const;
	unsigned int GPHgetTotalArc();
};

inline unsigned int CGraphe::GPHgetTotalSommet() const
{
	return uiGPHtotalSommet;
}

#endif