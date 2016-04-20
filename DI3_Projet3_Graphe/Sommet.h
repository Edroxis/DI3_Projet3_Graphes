#pragma once

#include "Arc.h"

class CSommet
{
private:
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
	CArc const * const * getPartant() const;
	CArc const * const * getArrivant() const;
	unsigned int getNbArrivant();
	unsigned int getNbPartant();

};

