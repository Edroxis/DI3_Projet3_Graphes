#pragma once

#include "Sommet.h"

class CGraphe
{
private:
	CSommet ** ppSMTliste;
	unsigned int uitotalSommet;

public:
	CGraphe(void);
	~CGraphe(void);

public:
	void GPHajouterSommet(CSommet& SMTparam);
};

