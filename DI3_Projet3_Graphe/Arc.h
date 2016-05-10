#ifndef ARC_H
#define ARC_H

//Déclaration anticipée pour éviter une dépendance circulaire
class CSommet;

class CArc
{
private:
	CSommet * pSMTARCdest;

public:
	CArc(CSommet& SMTparam);
	~CArc(void);

	CSommet& ARCgetDest() const;
};

#endif