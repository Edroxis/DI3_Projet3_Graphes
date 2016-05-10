#ifndef GRAPHE_H
#define GRAPHE_H

#include "Sommet.h"

#define EXCEPTION_SOMMET_INTROUVABLE 1
#define EXCEPTION_SOMMET_EXISTANT 2

class CGraphe
{
private:
	CSommet ** ppSMTGPHliste;
	unsigned int uiGPHtotalSommet;

public:
	CGraphe();
	CGraphe(char const * const chemin);
	~CGraphe();

	void GPHajouterSommet(CSommet* SMTparam);
	void GPHsupprimerSommet(CSommet& SMTparam);
	bool GPHexistantSommet(unsigned int inumero) const;
	CSommet& GPHgetSommet(unsigned int inumero);
	unsigned int GPHgetTotalSommet() const;
    void GPHprintGraphe();
};

inline unsigned int CGraphe::GPHgetTotalSommet() const
{
	return uiGPHtotalSommet;
}

#endif
