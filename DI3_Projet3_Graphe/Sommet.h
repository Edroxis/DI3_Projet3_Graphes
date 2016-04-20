#pragma once

#include "Arc.h"

class CSommet
{
private:
	unsigned int uinumero;
	unsigned int uinbArrivant;
	unsigned int uinbPartant;
	CArc ** ppARCarrivant;
	CArc ** ppARCpartant;

public:
	CSommet(const CSommet& SMTparam);
	CSommet(unsigned int uiParam);
	~CSommet(void);

public:
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);
};

