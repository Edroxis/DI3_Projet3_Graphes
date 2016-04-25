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
	~CSommet(void);

public:
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);
	CArc const * const * SMTgetPartant() const;
	CArc const * const * SMTgetArrivant() const;
	unsigned int SMTgetNbArrivant() const;
	unsigned int SMTgetNbPartant() const;


private:
	void SMTajouterArcPartant(CSommet& SMTdest);
	void SMTajouterArcArrivant(CSommet& SMTdest);
	void SMTsupprimerArcPartant(CSommet& SMTdest);
	void SMTsupprimerArcArrivant(CSommet& SMTdest);
};

