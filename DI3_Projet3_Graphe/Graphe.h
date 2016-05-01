#pragma once

#include "Sommet.h"

class CGraphe
{
private:
	CSommet ** ppSMTliste;
	unsigned int uiGPHtotalSommet;
	unsigned int uiGPHtotalArc;

public:
	CGraphe(void);
	CGraphe(char * chemin);
	~CGraphe(void);

public:
	void GPHajouterSommet(CSommet& SMTparam);
	void GPHsupprimerSommet(CSommet& SMTparam);
	CSommet& GPHgetSommet(int inumero);
	unsigned int GPHgetTotalSommet();
	unsigned int GPHgetTotalArc();
};

